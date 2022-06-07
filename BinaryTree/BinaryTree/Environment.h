#pragma once
#include "UIInputBox.h"
#include "BinaryTree.h"
#include "UIPanel.h"
#include "UIButton.h"
class Environment
{
public:
	Environment();
	~Environment();

	void Start();

	void Update(float DeltaTime);
	void Draw(float DeltaTime);
	
	void AddListElement();
	void RemoveListElement();

	void RandomiseBinaryTree();

	BinaryTree binaryTree = BinaryTree();;

	UIInputBox* addNumInput;
	UIInputBox* indexInput;

	void ResetGameObjects();

	void DisplayBinaryTreeNode(TreeNode<int>* node, int x, int y, int iteration = 0);


	static std::vector<Object*> objects;

	static int lifetimeObjectCount;
	static int AddObjectToGame(Object* obj) {
		objects.push_back(obj);
		lifetimeObjectCount++;
		// Return count for object id
		return lifetimeObjectCount;
	}
};

