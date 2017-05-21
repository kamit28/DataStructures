/*
 * linked_queue.hpp
 *
 *  Created on: 21-May-2017
 *      Author: Amit
 */

#ifndef LINKED_QUEUE_HPP_
#define LINKED_QUEUE_HPP_

#include <iostream>
#include <exception>
#include "link_node.h"

template<class T>
class LinkedQueue {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	LinkedQueue(void);

	LinkedQueue(const LinkedQueue<T>& otherQueue);

	virtual ~LinkedQueue(void);

	Node<T>* getHead(void) const;

	Node<T>* getTail(void) const;

	int getSize(void) const;

	void offer(const T& data);

	T& take(void);

	T& peek(void) const;

	bool is_empty(void) const;

};

template<class T>
LinkedQueue<T>::LinkedQueue(void) :
		head(nullptr), tail(nullptr), size(0) {
}

template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& otherQueue) {
	head = tail = nullptr;
	Node<T> *node;
	if (otherQueue.head != nullptr) {
		if (head == nullptr) {
			node = new Node<T>(otherQueue.head->getData(), nullptr);
			head = tail = node;
		}

		Node<T> *ptr = otherQueue.head->getNext();
		for (; ptr != nullptr; ptr = ptr->getNext()) {
			node = new Node<T>(ptr->getData(), nullptr);
			tail->setNext(node);
			tail = node;
		}
	}
	size = otherQueue.size;
}

template<class T>
LinkedQueue<T>::~LinkedQueue(void) {
	Node<T> *ptr;
	while (head != nullptr) {
		ptr = head->getNext();
		delete head;
		head = ptr;
	}
}

template<class T>
Node<T>* LinkedQueue<T>::getHead(void) const {
	return head;
}

template<class T>
Node<T>* LinkedQueue<T>::getTail(void) const {
	return tail;
}

template<class T>
int LinkedQueue<T>::getSize(void) const {
	return size;
}

template<class T>
void LinkedQueue<T>::offer(const T& data) {
	Node<T> *node = new Node<T>(data, nullptr);

	if (size == 0) {
		tail = head = node;
	} else {
		tail->setNext(node);
		tail = node;
	}
	++size;
}

template<class T>
T& LinkedQueue<T>::take(void) {
	if (size == 0) {
		throw std::logic_error("Queue was empty");
	}

	Node<T> *node = head;
	T& data = node->getData();
	if (size == 1) {
		head = tail = nullptr;
	} else {
		head = node->getNext();
	}
	--size;
	delete node;
	return data;
}

template<class T>
T& LinkedQueue<T>::peek(void) const {
	if (size == 0) {
		throw std::logic_error("Queue was empty");
	}

	return head->getData();
}

template<class T>
bool LinkedQueue<T>::is_empty(void) const {
	return head == nullptr;
}

#endif /* LINKED_QUEUE_HPP_ */
