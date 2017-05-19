/*
 * link_node.h
 *
 *  Created on: 13-May-2017
 *      Author: Amit
 */

#ifndef LINK_NODE_H_
#define LINK_NODE_H_

template<class T>
class Node {
public:
	Node() {
		this(nullptr, nullptr);
	}

	Node(const T& obj, Node<T>* nextPtr = nullptr) :
			data(obj), next(nextPtr) {
	}
	;

	Node(const Node<T>& node) :
			data(node.data), next(node.next) {
	}

	~Node() {
	}

	T& getData() {
		return data;
	}

	void setData(const T& theData) {
		data = theData;
	}

	Node<T>* getNext() {
		return next;
	}

	void setNext(Node<T>* nextNode) {
		next = nextNode;
	}

private:
	T data;
	Node<T>* next;
};

#endif /* LINK_NODE_H_ */
