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
	node<T> *head, *tail;
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
		if (index == 0)
			return front();
		else if (index == size - 1)
			return back();
		else {
			node<T> *node = get_node_at(index);
			return node->data;
		}
	}


public:
	void insert_item(int index, T value) {
		if (index == 0)
			push_front(value);
		else if (index == size - 1)
			push_back(value);
		else{
		node<T> *previousNode = get_node_at(index-1);
		node<T> *addedNode = new node<T>;
		addedNode->data = value;
		addedNode->next = previousNode->next;
		previousNode->next = addedNode;
		}
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
	T pop_front_with_value() {
		T returnValue = head->data;
		head = head->next;
		size--;
		return returnValue;
	}

public:
	void earse(int index) {
		if (index == 0)
			pop_front();
		else if (index == size - 1)
			pop_back();
		else {
			node<T> *previousNode = get_node_at(index - 1);
			node<T> *earsedNode = previousNode->next;
			previousNode->next = earsedNode->next;
			size--;
		}
	}

	public:
		void remove_value(T value) {
			node<T> *earsedNode = new node<T>;
			node<T> *previousNode = new node<T>;
			earsedNode = head;
			previousNode = head;
			int i=0;
			for (i ; i < size; i++)
			{
				if (earsedNode->data == value)
					break;

				previousNode = earsedNode;
				earsedNode = earsedNode->next;
			}
			if (i == 0)
				pop_front();
			else if (i == size - 1)
				pop_back();
			else {
				previousNode->next = earsedNode->next;
				size--;
			}

		}

public:
	 void reverse() {
		 node<T> *newTail= NULL;	
		 node<T> *previousNode = new node<T>;
		 int fixedSize = size;
		 for (int i = 0; i < fixedSize; i++)
		 {
			 T value = pop_front_with_value();
			 node<T> *nextNode = new node<T>;
			 nextNode->data = value;
			 nextNode->next = NULL;

			 if (newTail == NULL) {
				 newTail = nextNode;
				 previousNode = nextNode;
			
			 }
			 else
			 {
				 nextNode->next = previousNode;
				 previousNode = nextNode;

			 }
          
		 }
		 head = previousNode;
		 tail = newTail;
		 size = fixedSize;

		 }

public:
	T front() {
		return head->data;
	}

public:
	T back() {
		return tail->data;
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


	private :
		node<T>* get_node_at(int index) {
			node<T> *nextNode = new node<T>;
			nextNode = head;
			for (int i = 0; i < index; i++)
			{
				nextNode = nextNode->next;
			}

			return nextNode;
		}

};
