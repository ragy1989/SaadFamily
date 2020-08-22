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

		std::cout << "Queen \n";
	}

public:
	void enqueue(T value) {
		linda.push_back(value);
	}

public:
	T dequeue() {
		return linda.pop_front_with_value();
	}

};

