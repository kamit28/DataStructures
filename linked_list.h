/*
 * linked_list.h
 *
 *  Created on: 13-May-2017
 *      Author: Anshu
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
#include <exception>
#include "link_node.h"

template<class T>
class LinkedList {
public:
	Node<T>* getHead() const {
		return head;
	}

	int getSize() const {
		return size;
	}

	LinkedList(Node<T>* h = nullptr, int s = 0) :
			head(h), size(s) {
	}

	LinkedList(const LinkedList<T>& list) {
		head = nullptr;
		if (list.getHead() != nullptr) {
			Node<T>* temp;
			for (Node<T>* ptr = list.getHead(); ptr != nullptr;
					ptr = ptr->getNext()) {
				Node<T>* node = new Node<T>(ptr->getData(), nullptr);
				if (head == nullptr) {
					head = node;
					temp = head;
				}
				temp->setNext(node);
				temp = temp->getNext();
			}
		}
		size = list.getSize();
	}

	~LinkedList() {
		Node<T>* ptr;
		while (head != nullptr) {
			ptr = head->getNext();
			delete head;
			head = ptr;
		}
	}

	void append(const T& data) {
		Node<T>* node = new Node<T>(data, nullptr);

		if (head == nullptr) {
			head = node;
		} else {
			Node<T>* ptr = head;
			while (ptr->getNext() != nullptr) {
				ptr = ptr->getNext();
			}
			ptr->setNext(node);
		}
		++size;
	}

	void prepend(const T& data) {
		Node<T>* node = new Node<T>(data, head);
		head = node;
		++size;
	}

	T* get(const int pos) {
		check_range(pos);
		Node<T>* ptr;
		int i = 0;
		for (ptr = head; ptr != nullptr && i < pos; ++i, ptr = ptr->getNext())
			;
		if (ptr != nullptr) {
			return &(ptr->getData());
		}
		return nullptr;
	}

	void check_range(int pos) {
		if (pos >= size) {
			throw std::logic_error("Search position was out of range");
		}
	}

	void printList() {
		Node<T>* ptr = head;
		std::cout << "HEAD->";
		while (ptr != nullptr) {
			std::cout << ptr->getData() << "->";
			ptr = ptr->getNext();
		}
		std::cout << "NULL" << std::endl;
	}

private:
	Node<T>* head;
	int size;
};

#endif /* LINKED_LIST_H_ */
