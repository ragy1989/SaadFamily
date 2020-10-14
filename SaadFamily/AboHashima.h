#pragma once
#include <iostream>

using namespace std;

template <typename K , typename V>
class AboHashima
{
private:
	int size;
	V *array;
	int *avaliableIndexes;
public:
	AboHashima(int size) {
		this->size = size;
		array = new V[this->size];
		avaliableIndexes = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			avaliableIndexes[i] = false;
		}
	}
public:
	void add(K key, V value) {
		int index = divisionHashFun(key);
		array[index] = value;
		avaliableIndexes[index] = true;
	}

public:
	void data() {
		for (int i = 0; i < size; i++) {
			if (!avaliableIndexes[i])
				continue;

			std::cout << i;
			std::cout << "-";
			std::cout << array[i];
			std::cout << "\n";
		}
	}
public:
	bool exists(K key) {
		int index = divisionHashFun(key);
		if (avaliableIndexes[index]==true) {
			return true;
		}
		return false;
	}

public:
	V get(K key) {
		int index = divisionHashFun(key);
		if (exists(key))
			return array[index];
		else
			return NULL;
	}

public:
	void remove(K key) {
		int index = divisionHashFun(key);
		if (exists(key))
			 avaliableIndexes[index]=false;
	}
private:
		int divisionHashFun(K key) {
		std::hash<K> hash;
		auto hashed = hash(key);
		int divisionHash = hashed % size;
		return abs(divisionHash);
	}

};

