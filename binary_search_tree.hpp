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

	TreeNode<T>* findSmallestInRightSubtree(const TreeNode<T>* rootNode) {
		TreeNode<T>* ptr = rootNode->getRight();
		while (ptr->getLeft() != nullptr) {
			ptr = ptr->getLeft();
		}
		return ptr;
	}

	TreeNode<T>* findLargestInLeftSubtree(const TreeNode<T>* rootNode) {
		TreeNode<T>* ptr = rootNode->getLeft();
		while (ptr->getRight() != nullptr) {
			ptr = ptr->getRight();
		}
		return ptr;
	}

	void swap(TreeNode<T>* one, TreeNode<T>* two) const {
		T tempData = one->getData();
		one->setData(two->getData());
		two->setData(tempData);
	}

	TreeNode<T>* findPrev(TreeNode<T>* node, TreeNode<T>* rootNode) {
		TreeNode<T>* ptr = rootNode;
		while (ptr != nullptr && !ptr->isLeaf()) {
			if ((ptr->getLeft() != nullptr
					&& ptr->getLeft()->getData() == node->getData())
					|| (ptr->getRight() != nullptr
							&& ptr->getRight()->getData() == node->getData())) {
				return ptr;
			} else if (ptr->getData() < node->getData()) {
				ptr = ptr->getRight();
			} else {
				ptr = ptr->getLeft();
			}
		}
		return nullptr;
	}

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

	TreeNode<T>* searchElement(const T& element) const {
		TreeNode<T>* temp = root;

		while (temp != nullptr) {
			if (temp->getData() == element) {
				return temp;
			} else if (element < temp->getData()) {
				temp = temp->getLeft();
			} else {
				temp = temp->getRight();
			}
		}
		return nullptr;
	}

	void deleteElement(const T& element) {
		TreeNode<T>* temp = searchElement(element);
		TreeNode<T>* prev = nullptr;
		TreeNode<T>* ptr = nullptr;

		if (temp != nullptr) {
			if (temp->isLeaf()) {
				prev = findPrev(temp, root);
				if (temp == prev->getRight()) {
					prev->setRight(nullptr);
				} else {
					prev->setLeft(nullptr);
				}
				delete temp;
			} else if (temp->getRight() != nullptr) {
				ptr = findSmallestInRightSubtree(temp);
				if (ptr->isLeaf()) {
					prev = findPrev(ptr, temp);
					swap(temp, ptr);
					if (ptr == prev->getRight()) {
						prev->setRight(nullptr);
					} else {
						prev->setLeft(nullptr);
					}
					delete ptr;
				} else {
					prev = findPrev(ptr, temp);
					swap(temp, ptr);
					if (prev != nullptr) {
						prev->setLeft(ptr->getRight());
						delete ptr;
					}
				}
			} else {
				ptr = findLargestInLeftSubtree(temp);
				if (ptr->isLeaf()) {
					prev = findPrev(ptr, temp);
					swap(ptr, temp);
					if (ptr == prev->getRight()) {
						prev->setRight(nullptr);
					} else {
						prev->setLeft(nullptr);
					}
					delete ptr;
				} else {
					prev = findPrev(ptr, temp);
					swap(ptr, temp);
					if (prev != nullptr) {
						prev->setRight(ptr->getLeft());
						delete ptr;
					}
				}
			}
		}
	}

	void printTree() const {
		inOrder(root);
	}

	void inOrder(TreeNode<T>* node) const {
		if (node != nullptr) {
			inOrder(node->getLeft());
			std::cout << node->getData() << '\t';
			inOrder(node->getRight());
		}
	}

};
#endif /* BINARY_SEARCH_TREE_HPP_ */
