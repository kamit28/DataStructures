/*
 * linked_circular_Queue.hpp
 *
 *  Created on: 22-May-2017
 *      Author: Amit
 */

#ifndef LINKED_CIRCULAR_QUEUE_HPP_
#define LINKED_CIRCULAR_QUEUE_HPP_

#include "link_node.h"

template<class T>
class LinkedCircularQueue {
private:
	Node<T>* head;
	Node<T>* tail;
	unsigned int size_t;

	inline void range_check(void) const;

public:

	LinkedCircularQueue(void);

	LinkedCircularQueue(const LinkedCircularQueue& other);

	virtual ~LinkedCircularQueue(void);

	void offer(const T& element);

	const T& take(void);

	inline const T& peek(void) const;

	inline bool empty(void) const;

	inline unsigned int size(void) const;
};

template<class T>
LinkedCircularQueue<T>::LinkedCircularQueue(void) {
	head = tail = nullptr;
	size_t = 0;
}

template<class T>
LinkedCircularQueue<T>::LinkedCircularQueue(
		const LinkedCircularQueue<T>& otherQueue) {
	Node<T> *node;
	if (!otherQueue.empty()) {
		node = new Node<T>(otherQueue.head->getData(), nullptr);
		head = tail = node;
		tail->setNext(head);

		Node<T> *ptr = otherQueue.head->getNext();
		for (; ptr != otherQueue.head; ptr = ptr->getNext()) {
			node = new Node<T>(ptr->getData(), head);
			tail->setNext(node);
			tail = node;
		}
	}
	size_t = otherQueue.size_t;
}

template<class T>
LinkedCircularQueue<T>::~LinkedCircularQueue(void) {
	tail->setNext(nullptr);
	for (Node<T> *ptr = head; ptr != nullptr;) {
		head = ptr->getNext();
		delete ptr;
		ptr = head;
	}
}

template<class T>
inline unsigned int LinkedCircularQueue<T>::size(void) const {
	return size_t;
}

template<class T>
void LinkedCircularQueue<T>::offer(const T& data) {
	Node<T> *node = new Node<T>(data, head);

	if (size_t == 0) {
		tail = head = node;
	} else {
		tail->setNext(node);
		tail = node;
	}
	++size_t;
}

template<class T>
const T& LinkedCircularQueue<T>::take(void) {
	range_check();

	Node<T> *node = head;
	T& data = node->getData();
	if (size_t == 1) {
		head = tail = nullptr;
	} else {
		head = node->getNext();
		tail->setNext(head);
	}
	--size_t;
	delete node;
	return data;
}

template<class T>
inline const T& LinkedCircularQueue<T>::peek(void) const {
	range_check();
	return head->getData();
}

template<class T>
bool LinkedCircularQueue<T>::empty(void) const {
	return size_t == 0;
}

template<class T>
inline void LinkedCircularQueue<T>::range_check(void) const {
	if (size_t == 0) {
		throw std::logic_error("Queue was empty");
	}
}
#endif /* LINKED_CIRCULAR_QUEUE_HPP_ */
