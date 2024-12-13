#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <exception>
template <typename T>
class Stack {
public:
	Stack();

	~Stack();

	Stack& operator<<(const T& value); //push

	Stack& operator>>(T& value); //pop

	Stack& operator=(const Stack& other);

	bool operator<(const Stack& other);

	bool operator==(const Stack& other);

	T operator[](int index) const;

	bool isEmpty() const;

	void print() const;
private:
	T* data;

	int capacity;

	int size;
};
template <typename T>
Stack<T>::Stack() {
    size = 0;
    capacity = 20;
    data = new T[capacity];
}

template <typename T>
bool Stack<T>::operator==(const Stack& other) {
    if (size != other.size) {
        return false;
    }
    return true;
}
template <typename T>
bool Stack<T>::operator<(const Stack& other) {
    return size < other.size;
}
template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}
template <typename T>
Stack<T>& Stack<T>::operator<<(const T& value) {
    if (size == capacity) {
        capacity *= 2; T* newData = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;

    return *this;
}
template <typename T>
Stack<T>& Stack<T>::operator>>(T& value) {
    if (!isEmpty()) {
        value = data[--size];
        return *this;
    }
    // throw std::exception("Stack is empty");
    throw std::out_of_range("Stack is Empty");
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}
template <typename T>
T Stack<T>::operator[](int index) const {
    if ((index < 0) || (index >= size)) {
        throw std::out_of_range("Incorrect index");
    }
    return data[index];
}
template <typename T>
bool Stack<T>::isEmpty() const {
    return size == 0;
}
template <typename T>
void Stack<T>::print() const {     //для вывода, проверки работы стека :)
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
#endif //STACK_H

