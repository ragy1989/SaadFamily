#pragma once
#include <iostream>

using namespace std;
#include "Linda.h"
template <typename T>
class QueenLinda 
{
public:
private :
	Linda<T> linda;

public:
	QueenLinda()
	{

		std::cout << "Queen iam linked list queue \n";
	}

public:
	void enqueue(T value) {
		linda.push_back(value);
	}

public:
	T dequeue() {
		return linda.pop_front_with_value();
	}

public:
	bool is_empty() {
		return linda.is_empty();
	}

};

template <typename T>
class QueenCarole
{
public:
private:
	int capacity,front,rear;
	T *array;

public:
	QueenCarole(int capacity)
	{
		this->capacity = capacity;
		array = new T[this->capacity];
		front = rear = -1;
		std::cout << "hi iam Queen Carole iam circular array queue\n";
	}

public:
	void enqueue(T value) {
		if (is_Full()) {
			std::cout << "queue is full \n";
			return;
		}

		if (is_empty())
			rear = front = 0;
		else
			rear++;

		array[get_index(rear)] = value;

	}

public:
	T dequeue() {
		if (is_empty()) {
			std::cout << "queue is empty \n";
			return array[front];
		}
		T value = array[front];
		if (get_index(rear) == get_index(front))
			front = rear = -1;
		else
		front++;
		return value;

	}

public:
	bool is_empty() {
		return (rear == -1 && front==-1);
	}

public:
	bool is_Full() {
		return (get_index(rear + 1) == get_index(front)) ;

	}

public:
	int get_size() {
		return (rear - front) + 1;

	}

private:
	int get_index(int value) {
		return value % capacity;
	}

};


