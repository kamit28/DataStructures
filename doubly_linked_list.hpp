/*
 * doubly_linked_list.hpp
 *
 *  Created on: 22-May-2017
 *      Author: Amit
 */

#ifndef DOUBLY_LINKED_LIST_HPP_
#define DOUBLY_LINKED_LIST_HPP_

#include "bidirectional_node.hpp"

template<class T>
class DoublyLinkedList {
private:
	BidirectionalNode<T>* head;
	unsigned int size_t;

	void check_range(const int pos) const {
		if (pos >= size_t) {
			throw std::logic_error("Search position was out of range");
		}
	}

public:
	DoublyLinkedList() :
			head(nullptr), size_t(0) {
	}

	DoublyLinkedList(const DoublyLinkedList<T>& other) {
		if (other.size_t != 0) {
			BidirectionalNode<T>* temp = nullptr;
			for (BidirectionalNode<T>* ptr = other.head; ptr != nullptr; ptr =
					ptr->getNext()) {
				BidirectionalNode<T>* node = new BidirectionalNode<T>(
						ptr->getData(), nullptr, temp);
				if (head == nullptr) {
					head = node;
					temp = head;
				}
				temp->setNext(node);
				temp = temp->getNext();
			}
		}
		size_t = other.size_t;
	}

	~DoublyLinkedList() {
		BidirectionalNode<T>* ptr;
		while (head != nullptr) {
			ptr = head->getNext();
			delete head;
			head = ptr;
		}
	}

	void append(const T& data) {
		BidirectionalNode<T>* node = new BidirectionalNode<T>(data, nullptr,
				nullptr);

		if (head == nullptr) {
			head = node;
		} else {
			BidirectionalNode<T>* ptr = head;
			while (ptr->getNext() != nullptr) {
				ptr = ptr->getNext();
			}
			ptr->setNext(node);
			node->setPrev(ptr);
		}
		++size_t;
	}

	void prepend(const T& data) {
		BidirectionalNode<T>* node = new BidirectionalNode<T>(data, nullptr,
				nullptr);
		node->setNext(head);
		head->setPrev(node);
		head = node;
		++size_t;
	}

	T* get(const int pos) const {
		check_range(pos);
		BidirectionalNode<T>* ptr;
		int i = 0;
		for (ptr = head; ptr != nullptr && i < pos; ++i, ptr = ptr->getNext())
			;
		if (ptr != nullptr) {
			return &(ptr->getData());
		}
		return nullptr;
	}

	bool remove(const int pos) {
		check_range(pos);
		BidirectionalNode<T>* ptr;
		int i = 0;
		for (ptr = head; ptr != nullptr && i < pos; ++i, ptr = ptr->getNext())
			;
		if (ptr != nullptr) {
			if (ptr == head) {
				head = ptr->getNext();
				ptr->getNext()->setPrev(nullptr);
				ptr->setNext(nullptr);

			} else if (ptr->getNext() == nullptr) {
				ptr->getPrev()->setNext(nullptr);
				ptr->setPrev(nullptr);
			} else {
				ptr->getPrev()->setNext(ptr->getNext());
				ptr->getNext()->setPrev(ptr->getPrev());
			}
			--size_t;
			delete ptr;
			return true;
		}
		return false;
	}

	void printList() const {
		BidirectionalNode<T>* ptr = head;
		std::cout << "HEAD->";
		while (ptr != nullptr) {
			std::cout << ptr->getData() << "->";
			ptr = ptr->getNext();
		}
		std::cout << "NULL" << std::endl;
	}

	unsigned int size() const {
		return size_t;
	}
};

#endif /* DOUBLY_LINKED_LIST_HPP_ */
