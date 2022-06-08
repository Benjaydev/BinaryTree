#pragma once
#include <iostream>

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

	int GetValue(int value);

	void PrintAllValues();

	void Clear();

private:
	TreeNode<int>* First = nullptr;

	int size = 0;
};


