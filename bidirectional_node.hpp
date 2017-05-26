/*
 * bidirectional_node.hpp
 *
 *  Created on: 22-May-2017
 *      Author: Amit
 */

#ifndef BIDIRECTIONAL_NODE_HPP_
#define BIDIRECTIONAL_NODE_HPP_

template<class T>
class BidirectionalNode {
public:
	BidirectionalNode(const T& obj, BidirectionalNode<T>* nextPtr = nullptr,
			BidirectionalNode<T>* prevPtr = nullptr) :
			data(obj), next(nextPtr), prev(prevPtr) {
	}

	BidirectionalNode(const BidirectionalNode<T>& node) :
			data(node.data), next(node.next), prev(node.prev) {
	}

	~BidirectionalNode() {
	}

	const T& getData() const {
		return data;
	}

	void setData(const T& theData) {
		data = theData;
	}

	BidirectionalNode<T>* getNext() const {
		return next;
	}

	void setNext(BidirectionalNode<T>* nextNode) {
		next = nextNode;
	}

	BidirectionalNode<T>* getPrev() const {
		return prev;
	}

	void setPrev(BidirectionalNode<T>* prevNode) {
		prev = prevNode;
	}

private:
	T data;
	BidirectionalNode<T>* next;
	BidirectionalNode<T>* prev;
};

#endif /* BIDIRECTIONAL_NODE_HPP_ */
