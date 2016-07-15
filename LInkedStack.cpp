// Stack.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace System;
using namespace std;

template <typename T>
struct StackElement {
	T data;
	StackElement* next;
};

template <typename T>
class LinkedStack {
private:
	StackElement* top;
public:
	LinkedStack();
	LinkedStack(LinkedStack const&);
	LinkedStack& operator=(LinkedStack const&);
	bool empty() const;
	int peek() const;
	void push(int const&);
	int pop();
	~LinkedStack();
};
template <typename T>
LinkedStack<T>::LinkedStack() {
	top = NULL;
}
template <typename T>
bool LinkedStack<T>::empty() const {
	return top == NULL;
}
template <typename T>
int LinkedStack<T>::peek() const {
	if (empty()) {
		cout << "??????: ???? ?? ?????????? ? ?????? ????!\n";
		return 0;
	}
	return top->data;
}
template <typename T>
void LinkedStack<T>::push(int const& x) {
	StackElement* p = new StackElement;
	p->data = x;
	p->next = top;
	top = p;
}
template <typename T>
int LinkedStack<T>::pop() {
	if (empty()) {
		cout << "??????: ???? ?? ?????????? ?? ?????? ????!\n";
		return 0;
	}
	StackElement* p = top;
	top = top->next;
	int x = p->data;
	delete p;
	return x;
}
template <typename T>
LinkedStack<T>::~LinkedStack() {
	StackElement* toDelete;
	while (top != NULL) {
		toDelete = top;
		top = top->next;
		delete toDelete;
	}
}
template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack const& ls) : top(NULL) {
	while (!ls.empty()) {
		push(ls.pop());
	}
}
template <typename T>
LinkedStack& LinkedStack<T>::operator=(LinkedStack const& ls) {
	if (this != &ls) {
		while (!empty()) pop();
		StackElement* toCopy = ls.top;
		StackElement *copy, *lastCopied = NULL;
		while (toCopy != NULL) {
			copy = new StackElement;
			if (top == NULL)
				top = copy;
			copy->data = toCopy->data;
			if (lastCopied != NULL)
				lastCopied->next = copy;
			lastCopied = copy;
			toCopy = toCopy->next;
		}
		lastCopied->next = NULL;
	}
	return *this;
}

int main()
{

}
