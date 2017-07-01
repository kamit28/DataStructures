/*
 * TreeNode.hpp
 *
 *  Created on: 27-May-2017
 *      Author: Amit
 */

#ifndef TREE_NODE_HPP_
#define TREE_NODE_HPP_

template<class T>
class TreeNode {
private:
	/**
	 * The data object
	 */
	T data;

	/**
	 * Pointer to the left subtree
	 */
	TreeNode<T>* left;

	/**
	 * Pointer to the right subtree
	 */
	TreeNode<T>* right;

public:

	/**
	 * The parameterized constructor. Creates a TreeNode object with default data object set
	 * to null, left and right subtrees also set to null.
	 */
	TreeNode(const T& obj, TreeNode<T>* leftPtr = nullptr,
			TreeNode<T>* rightPtr = nullptr) :
			data(obj), left(leftPtr), right(rightPtr) {
	}

	/**
	 * The copy constructor
	 */
	TreeNode(const TreeNode<T>& node) :
			data(node.data), left(node.left), right(node.right) {
	}

	~TreeNode() {
	}

	const T& getData() const {
		return data;
	}

	void setData(const T& theData) {
		data = theData;
	}

	TreeNode<T>* getLeft() const {
		return left;
	}

	void setLeft(TreeNode<T>* left) {
		this->left = left;
	}

	TreeNode<T>* getRight() const {
		return right;
	}

	void setRight(TreeNode<T>* right) {
		this->right = right;
	}

	bool isLeaf(void) const {
		return this->right == nullptr && this->left == nullptr;
	}
};

#endif /* TREE_NODE_HPP_ */
