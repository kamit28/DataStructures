/*
 * arr_list.h
 *
 *  Created on: 11-May-2017
 *      Author: Amit
 */

#ifndef ARR_LIST_H_
#define ARR_LIST_H_

#include <iostream>
#include <iterator>
#include <exception>

template<typename T>
class arr_list {
public:
	arr_list() {
		arr = new T[DEFAULT_SIZE];
		size_t = 0;
		capacity_t = DEFAULT_SIZE;
	}

	arr_list(int size) {
		arr = new T[size];
		size_t = 0;
		capacity_t = size;
	}

	arr_list(const T* other, int start, int end) {
		size_t = capacity_t = end - start;
		arr = new T[end - start];
		std::copy(other, other+size_t, arr);
	}

	virtual ~arr_list() {
		//delete arr;
	}

	//inserts an element at the front of the list.
	bool insert(const T& element) {
		return insert(element, 0);
	}

	//inserts an element at the specified position in the list.
	bool insert(const T& element, int position) {
		capacity_check();
		range_check(position);
		int start = position + 1;
		for(int i = size_t; i >= start; --i) {
			arr[i] = arr[i-1];
		}
		arr[position] = element;
		size_t++;
		return true;
	}

	//inserts the element at the back of the list;
	bool push_back(const T& element) {
		capacity_check();
		arr[size_t] = element;
		++size_t;
		return true;
	}

	// deletes the elements at position.
	bool remove(int position) {
		range_check(position);

		for(int i = position + 1; i <= size_t; ++i) {
			arr[i - 1] = arr[i];
		}

		--size_t;
		return true;
	}

	//returns the reference to the element at position
	T& get(const int position) const {
		range_check(position);
		return arr[position];
	}

	//returns the reference to the first element.
	T& front() const {
		if (!empty()) {
			return arr[0];
		}
		throw std::logic_error("list is empty");
	}

	//returns the reference to the last element.
	T& back() const {
		if (!empty()) {
			return arr[size_t - 1];
		}
		throw std::logic_error("list is empty");
	}

	// returns true if list is empty.
	inline bool empty() const {
		return size_t == 0;
	}

	//returns the number of elements in the list.
	inline int size() const {
		return size_t;
	}

	// returns the capacity of the list.
	inline int capacity() const {
		return capacity_t;
	}

private:
	static const int DEFAULT_SIZE = 10;
	T* arr;
	int size_t;
	int capacity_t;

	void range_check(const int position) const {
		if(position > size_t - 1) {
			throw std::logic_error("position was out of range");
		}
	}

	void capacity_check() const {
		if(size_t + 1 > capacity_t) {
			throw std::logic_error("list is full");
		}
	}

};

#endif /* ARR_LIST_H_ */
