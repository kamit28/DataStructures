/*
 * arr_circular_queue.hpp
 *
 *  Created on: 21-May-2017
 *      Author: Amit
 */

#ifndef ARR_CIRCULAR_QUEUE_HPP_
#define ARR_CIRCULAR_QUEUE_HPP_

#include <algorithm>
#include <limits>
#include <iostream>

template<class T>
class CircularQueue {
private:
	static const int DEFAULT_CAPACITY = 10;
	T* arr;
	int head;
	int tail;
	unsigned int capacity_t;
	unsigned int size_t;

	inline void capacity_check();

	inline void range_check();

	inline void nextPos(void);

public:

	CircularQueue(const unsigned int capacity = DEFAULT_CAPACITY);

	CircularQueue(const CircularQueue& other);

	virtual ~CircularQueue(void);

	void offer(const T& element);

	const T& take(void);

	inline const T& peek(void) const;

	inline bool empty(void) const;

	inline bool full(void) const;

	inline unsigned int capacity() const;

	inline unsigned int size(void) const;

	inline int getHead(void) const;

	inline int getTail(void) const;
};

template<class T>
CircularQueue<T>::CircularQueue(const unsigned int capacity) :
		arr(new T[capacity]), head(-1), tail(-1), capacity_t(capacity), size_t(
				0) {
}

template<class T>
CircularQueue<T>::CircularQueue(const CircularQueue& other) {
	arr = new T[other.capacity_t];
	capacity_t = other.capacity_t;
	size_t = other.size_t;
	if (other.empty()) {
		head = tail = -1;
	} else {
		head = 0;
		tail = other.size_t - 1;
		std::copy(other.arr + head, other.arr + tail + 1, arr);
	}
}

template<class T>
CircularQueue<T>::~CircularQueue(void) {
	delete[] arr;
}

template<class T>
inline void CircularQueue<T>::capacity_check() {
	if (full()) {
		throw std::logic_error("queue is full!!");
	}
}

template<class T>
inline void CircularQueue<T>::range_check() {
	if (empty()) {
		throw std::logic_error("queue is empty!!");
	}
}

template<class T>
inline void CircularQueue<T>::nextPos(void) {
	if (tail == INT_MAX) {
		if (tail % capacity_t < head % capacity_t) {
			tail = capacity_t + (tail % capacity_t);
		} else {
			tail = tail % capacity_t;
		}
		head = head % capacity_t;
	}
}

template<class T>
void CircularQueue<T>::offer(const T& element) {
	capacity_check();
	if (head == -1) {
		head = tail = 0;
	} else {
		nextPos();
		++tail;
	}
	arr[tail % capacity_t] = element;
	++size_t;
}

template<class T>
const T& CircularQueue<T>::take(void) {
	range_check();
	T& val = arr[head % capacity_t];
	if (size() == 1) {
		head = tail = -1;
	} else {
		++head;
	}
	--size_t;
	return val;
}

template<class T>
inline const T& CircularQueue<T>::peek(void) const {
	return arr[head % capacity_t];
}

template<class T>
inline bool CircularQueue<T>::empty(void) const {
	return head == -1;
}

template<class T>
inline bool CircularQueue<T>::full(void) const {
	return (tail + 1) % capacity_t == head;
}

template<class T>
inline unsigned int CircularQueue<T>::capacity() const {
	return capacity_t;
}

template<class T>
inline unsigned int CircularQueue<T>::size(void) const {
	return size_t;
}

template<class T>
inline int CircularQueue<T>::getHead(void) const {
	return head;
}

template<class T>
inline int CircularQueue<T>::getTail(void) const {
	return tail;
}

#endif /* ARR_CIRCULAR_QUEUE_HPP_ */
