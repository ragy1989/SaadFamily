#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct node
{
	T data;
	node *next;
};

template <typename T>
class Linda
{
private:
	node<T> *head, *tail, *previousNode;
	int size;

public:
	Linda()
	{
		size = 0;
		head = NULL;
		tail = NULL;
		std::cout << "Hi iam linda.\n";
	}

public:
	T item_at(int index) {
		node<T> *nextNode = new node<T>;
		nextNode = head;
		for (int i = 0; i < index; i++)
		{
			nextNode = nextNode->next;
		}

		return nextNode->data;

	}

public:
	void push_back(T value) {
		node<T> *nextNode = new node<T>;
		nextNode->data = value;
		nextNode->next = NULL;
		size++;
		if (head == NULL) {
			head = nextNode;
			tail = nextNode;
		}
		else
		{
			tail->next = nextNode;
			tail = tail->next;
		}
	}

public:
	void push_front(T value) {
		node<T> *nextNode = new node<T>;
		nextNode->data = value;
		size++;
		if (head == NULL) {
			head = nextNode;
			tail = nextNode;
			nextNode->next = NULL;
		}
		else
		{
			nextNode->next = head;
			head = nextNode;
		}
	}


public:
	void pop_back() {
		node<T> *nextNode = new node<T>;
		nextNode = head;
		for (int i = 0; i < size - 1; i++)
		{
			nextNode = nextNode->next;
		}
		nextNode->next = NULL;
		tail = nextNode;
		size--;

	}

public:
	void pop_front() {
		head = head->next;
		size--;
	}

public:
	int get_size() {
		return size;
	}

public:
	bool is_empty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}
public:
	void data() {
		node<T> *nextNode = new node<T>;
		nextNode = head;
		for (int i = 0; i < size; i++)
		{
			cout << nextNode->data;
			cout << "\n";
			nextNode = nextNode->next;
		}
	}

};