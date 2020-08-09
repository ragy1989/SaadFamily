template <typename T>
class Sara
{
private:
	int capacity = 16;
	T *array = new T[capacity];
	T *lastIndex;
public:
	Sara() {
		lastIndex = array;
		std::cout << "Hi iam sara. Vector sister\n";
	}

public:
	T item_at(int index) {

		return array[index];
	}

public:
	int find(T value) {
		for (int i = 0; i < get_size(); i++) {
			if (array[i] == value) {
				return i;
			}
		}
		return -1;
	}

public:
	void insert_item(int index, T value) {
		if (lastIndex == &array[capacity]) {
			resize(capacity * 2);
		}

		for (int i = get_size() - 1; i >= index; i--) {
			array[i + 1] = array[i];

		}
		array[index] = value;
		lastIndex++;
	}


public:
	void push_back(T value) {
		if (lastIndex == &array[capacity]) {
			resize(capacity * 2);
		}
		*lastIndex = value;
		lastIndex++;
	}

public:
	void pop_back() {
		lastIndex--;
		if (get_size() == capacity / 4) {
			resize(capacity / 2);
		}
	}

public:
	void delete_item(int index) {
		for (int i = index; i < get_size() - 1; i++) {
			array[i] = array[i + 1];
		}
		lastIndex--;
		if (get_size() == capacity / 4) {
			resize(capacity / 2);
		}

	}

public:
	void remove(T value) {
		for (int i = 0; i < get_size(); i++) {
			if (array[i] == value) {
				delete_item(i);
			}
		}

	}

public:
	int get_capacity() {
		return capacity;
	}


public:
	int get_size() {
		return lastIndex - &array[0];
	}

public:
	bool is_empty() {
		if (lastIndex == array) {
			return true;
		}
		return false;
	}

public:
	void data() {
		for (int i = 0; i < get_size(); i++) {
			std::cout << array[i];
			std::cout << "\n";
		}
	}


private:
	void resize(int newCapacity) {

		T*	newArray = new T[newCapacity];
		int size = get_size();
		for (int i = 0; i < size; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
		lastIndex = &array[size];
		capacity = newCapacity;

	}
};