#include "Queue.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <new>

Exception::Exception(const int id, const char* message) : id(id), message(message) {}

FatalError::FatalError(const int id, const char * message) : Exception(id, message) {}

void FatalError::display() const
{
	std::cerr << "Fatal error - #" << std::hex << std::uppercase << id << ", " << message << std::endl;
	system("pause");
	exit(id);
}

Queue::QueueException::QueueException(const int id, const char* message) : Exception(id, message) {}

void Queue::QueueException::display() const
{
	std::cerr << "Exception - #" << std::hex << std::uppercase << id << ", " << message << std::endl;
}

Queue::Node::Node() : str(nullptr), next(nullptr) {}

Queue::Node::Node(const char * str) : next(nullptr) 
{
	this->str = _strdup(str);
	if (!this->str)
		throw FatalError(0x3E7, "Not enough memory");
}

void Queue::DeleteBegin()
{
	Node* temp = head;
	head = head->next;
	free(temp->str);
	delete temp;
}

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue()
{
	try
	{
		if (!head)
			throw QueueException(0x1, "Queue is empty!");
		while (head)
		{
			DeleteBegin();
		}
		std::cout << "\t Queue is clear" << std::endl;
	}
	catch (const QueueException& e)
	{
		e.display();
	}
	
}

void Queue::Put(const char * str)
{
	try
	{
		Node* cell = new Node(str);
		if (tail)
		{
			tail->next = cell;
			tail = cell;
		}
		else head = tail = cell;
	}
	catch (std::bad_alloc)
	{
		throw FatalError(0x3E7, "Not enough memory");
	}
	catch (const FatalError& e)
	{
		Queue::~Queue();
		e.display();
	}
}

char * Queue::Get()
{
	try
	{
		if (!head)
			throw QueueException(0x1, "Queue is empty");
		char* temp = _strdup(head->str);
		if(!temp)
			throw FatalError(0x3E7, "Not enough memory");
		DeleteBegin();
		return temp;
	}
	catch (const QueueException& e)
	{
		e.display();
		return nullptr;
	}
	catch (const FatalError& e)
	{
		Queue::~Queue();
		e.display();
	}
}

void Queue::Print() const
{
	try
	{
		if (!head)
			throw QueueException(0x1, "Queue is empty");
		Node* temp = head;
		int i = 1;
		while (temp)
		{
			std::cout << i << ") " << temp->str << std::endl;
			i++;
			temp = temp->next;
		}
	}
	catch (const QueueException& e)
	{
		e.display();
	}
}