/*
 * arr_stack.h
 *
 *  Created on: 11-May-2017
 *      Author: Amit
 */

#ifndef ARR_STACK_H_
#define ARR_STACK_H_

#include <exception>

template<typename T>
class arr_stack {
public:
	arr_stack(const int size = DEFAULT_SIZE) :
			arr(new T[size]), top(-1), capacity_t(size) {
	}

	inline T& pop() {
		range_check();
		T& val = arr[top];
		--top;
		return val;
	}

	inline void push(const T& element) {
		capacity_check();
		++top;
		arr[top] = element;
	}

	inline T& peek() const {
		return arr[top];
	}

	inline bool empty() const {
		return top == -1;
	}

	inline bool full() const {
		return top + 1 == capacity_t;
	}

	inline int capacity() const {
		return capacity_t;
	}

private:
	static const int DEFAULT_SIZE = 10;
	T* arr;
	int top;
	int capacity_t;

	void capacity_check() {
		if (full()) {
			throw std::logic_error("stack is full!!");
		}
	}

	void range_check() {
		if (empty()) {
			throw std::logic_error("stack is empty!!");
		}
	}
};

#endif /* ARR_STACK_H_ */
