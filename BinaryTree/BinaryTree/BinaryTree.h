#pragma once
#include <iostream>
#include <vector>

// List element class
// Non-pointer templated
template<typename T>
struct TreeNode {
	public:
		TreeNode(T v, TreeNode* l, TreeNode* r);

		T value;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;
};

// Pointer templated
template<typename T>
struct TreeNode<T*> {
	public:
		TreeNode(T* v, TreeNode* l, TreeNode* r);
		~TreeNode();

		T* value;
		TreeNode* left;
		TreeNode* right;
};

template<typename T>
inline TreeNode<T>::TreeNode(T v, TreeNode* l, TreeNode* r)
{
	value = v;
	left = l;
	right = r;
}

template<typename T>
inline TreeNode<T*>::TreeNode(T* v, TreeNode* l, TreeNode* r)
{
	value = v;
	left = l;
	right = r;
}

template<typename T>
inline TreeNode<T*>::~TreeNode()
{
	if (value != nullptr) {
		delete value;
		value = nullptr;
	}
}

// Double linked list class

class BinaryTree
{
public:

	BinaryTree();
	~BinaryTree();


	void Add(int value);

	void Remove(int value);

	BinaryTree Copy();

	
	bool IsEmpty() { return size == 0; }
	int GetSize() { return size; }

	TreeNode<int>* GetFirstNode() { return First != nullptr ? First : nullptr; }

	std::vector<int> PostOrderGet(TreeNode<int>* node, std::vector<int> currentList = std::vector<int>()) {
		if (node == nullptr) {
			return currentList;
		}

		if (node->left != nullptr) {
			currentList = PostOrderGet(node->left, currentList);
		}
		if (node->right != nullptr) {
			currentList = PostOrderGet(node->right, currentList);
		}
		currentList.push_back(node->value);
		return currentList;
	}

	void Clear();

private:
	TreeNode<int>* First = nullptr;

	int size = 0;
};


