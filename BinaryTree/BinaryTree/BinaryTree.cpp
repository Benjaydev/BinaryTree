#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
	Clear();
}

BinaryTree BinaryTree::Copy()
{
	BinaryTree copy = BinaryTree();
	return copy;
}


void BinaryTree::Add(int value)
{
	if (First == nullptr) {
		First = new TreeNode<int>(value, nullptr, nullptr);
		return;
	}


	TreeNode<int>* currentNode = First;
	TreeNode<int>* newNode = new TreeNode<int>(value, nullptr, nullptr);

	while (true) {
		if (value == currentNode->value) {
			break;
		}

		// Move right
		if (value > currentNode->value) {
			// If spot is empty, add the new node
			if (currentNode->right == nullptr) {
				currentNode->right = newNode;
				break;
			}
			// Else move on
			currentNode = currentNode->right;
		}
		// Move left
		else if (value < currentNode->value) {
			// If spot is empty, add the new node
			if (currentNode->left == nullptr) {
				currentNode->left = newNode;
				break;
			}
			// Else move on
			currentNode = currentNode->left;
		}
	
	}

	currentNode = nullptr;
	newNode = nullptr;

	size++;

}

void BinaryTree::Remove(int value)
{

	TreeNode<int>* currentNode = First;
	TreeNode<int>* lastNode = First;

	bool leftOrRight = true;

	while (true) {
		if (value == currentNode->value) {
			break;
		}

		if (value > currentNode->value) {
			// If the node to the right is nullptr, that means this value does not exist in tree
			if (currentNode->right == nullptr) {
				return;
			}
			// Else move on
			leftOrRight = true;
			lastNode = currentNode;
			currentNode = currentNode->right;
		}
		// Move left
		else if (value < currentNode->value) {
			// If the node to the left is nullptr, that means this value does not exist in tree
			if (currentNode->left == nullptr) {
				return;
			}
			// Else move on
			leftOrRight = false;
			lastNode = currentNode;
			currentNode = currentNode->left;
		}

	}

	 // If it has no nodes after
	 if (currentNode->right == nullptr && currentNode->left == nullptr) {
		 // If node is the first node, that means this node is the only node in the tree, so make First pointer null
		 if (First->value == currentNode->value) {
			 First = nullptr;
		 }

		// If the node being removed is on the right of the previous node
		if(leftOrRight) {
			lastNode->right = nullptr;
		}
		// If the node being removed is on the left of the previous node
		else {
			lastNode->left = nullptr;
		}

		delete currentNode;
		currentNode = nullptr;
	}


	// Right one child
	else if (currentNode->right != nullptr && currentNode->left == nullptr) {
		// If node is the first node, that means the next node has to come up
		if (First->value == currentNode->value) {
			First = currentNode->right;
		}
		// If current node is on right side of its parent
		else if (leftOrRight) {
			lastNode->right = currentNode->right;
		}
		// If current node is on left side of its parent
		else {
			lastNode->left = currentNode->right;
		}

		delete currentNode;
		currentNode = nullptr;
	}

	// Left one child
	else if (currentNode->left != nullptr && currentNode->right == nullptr) {
		 // If node is the first node, that means the next node has to come up
		 if (First->value == currentNode->value) {
			 First = currentNode->left;
		 }
		 // If current node is on right side of its parent
		 else if (leftOrRight) {
			lastNode->right = currentNode->left;
		}
		 // If current node is on left side of its parent
		else {
			lastNode->left = currentNode->left;
		}

		delete currentNode;
		currentNode = nullptr;
	}

	// Two children
	else if (currentNode->left != nullptr && currentNode->right != nullptr) {
		// Search for the value that is the lowest value that is higher than the value being deleted
		TreeNode<int>* lowestHighest = currentNode->right;

		while (lowestHighest->left != nullptr) {
			lowestHighest = lowestHighest->left;
		}

		int savedValue = lowestHighest->value;
		Remove(savedValue);

		currentNode->value = savedValue;

		currentNode = nullptr;
	}

	 size--;
}

void BinaryTree::FindNode(int value, TreeNode<int>*& foundNode, TreeNode<int>*& parentNode)
{
	parentNode = nullptr;
	foundNode = First;
	while (true) {
		if (value < foundNode->value) {
			parentNode = foundNode;
			foundNode = foundNode->left;

		}

		else if (value > foundNode->value) {
			parentNode = foundNode;
			foundNode = foundNode->right;
		}
		else {

			break;
		}
	}
}

void BinaryTree::Clear()
{
	std::vector<int> nodes = PostOrderGet(First);

	for (int i = 0; i < nodes.size(); i++) {
		Remove(nodes[i]);
	}

}
