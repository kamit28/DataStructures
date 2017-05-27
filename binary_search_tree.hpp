/*
 * binary_search_tree.hpp
 *
 *  Created on: 27-May-2017
 *      Author: Anshu
 */

#ifndef BINARY_SEARCH_TREE_HPP_
#define BINARY_SEARCH_TREE_HPP_

#include <exception>
#include "tree_node.hpp"

template<class T>
class BinarySearchTree {

private:
	TreeNode<T>* root;

public:
	BinarySearchTree() {
		root = nullptr;
	}

	void insertElement(const T& element) {
		TreeNode<T>* node = new TreeNode<T>(element, nullptr, nullptr);
		TreeNode<T>* temp = nullptr;
		TreeNode<T>* prev = nullptr;
		// If tree is empty
		if (root == nullptr) {
			root = node;
		} else {
			for (temp = root; temp != nullptr;) {
				prev = temp;
				if (element < temp->getData()) {
					temp = temp->getLeft();
				} else if (temp->getData() == element) {
					throw std::logic_error(
							"Can not insert. Element already exists in tree.");
				} else {
					temp = temp->getRight();
				}
			}
			if (element < prev->getData()) {
				prev->setLeft(node);
			} else {
				prev->setRight(node);
			}
		}
	}

	bool searchElement(const T& element) const {
		TreeNode<T>* temp = root;

		while (temp != nullptr) {
			if (temp->getData() == element) {
				return true;
			} else if (element < temp->getData()) {
				temp = temp->getLeft();
			} else {
				temp = temp->getRight();
			}
		}
		return false;
	}
};
#endif /* BINARY_SEARCH_TREE_HPP_ */
