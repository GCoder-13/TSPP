#pragma once
#define _QUEUE_H_

class Exception
{
protected:
	const int id;
	const char* message;
public:
	Exception(const int id, const char* message);
	virtual void display() const = 0;
};

class FatalError : private Exception
{
public:
	FatalError(const int id, const char* message);
	void display() const;
};

class Queue
{
private:
	class QueueException : private Exception
	{
	public:
		QueueException(const int id, const char* message);
		void display() const;
	};
	struct Node
	{
		char* str;
		Node* next;
		Node();
		Node(const char* str);
	};
	Node* head;
	Node* tail;
	void DeleteBegin();
public:
	Queue();
	~Queue();
	void Put(const char* str);
	char* Get();
	void Print() const;
};

#if !defined(_QUEUE_H_)
#include "Queue.h"
#endif