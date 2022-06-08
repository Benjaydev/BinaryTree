#include "pch.h"
#include "CppUnitTest.h"
#include "../BinaryTree/BinaryTree.cpp" 


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTests
{
	TEST_CLASS(BinaryTreeTests)
	{
	public:
		
		TEST_METHOD(AddingTest)
		{
			BinaryTree testTree = BinaryTree();

			testTree.Add(5);
			testTree.Add(10);
			testTree.Add(13);
			testTree.Add(3);
			testTree.Add(2);
			testTree.Add(4);
			/* Based on this order of adding, the tree should look like this:
							5
						   / \
						  3	  10
			             / \    \
			            2   4    13
			*/

			Assert::AreEqual(5, testTree.GetFirstNode()->value);
			Assert::AreEqual(3, testTree.GetFirstNode()->left->value);
			Assert::AreEqual(2, testTree.GetFirstNode()->left->left->value);
			Assert::AreEqual(4, testTree.GetFirstNode()->left->right->value);

			Assert::AreEqual(10, testTree.GetFirstNode()->right->value);
			Assert::AreEqual(13, testTree.GetFirstNode()->right->right->value);

		}
		
		
		TEST_METHOD(RemoveTest1)
		{
			BinaryTree testTree = BinaryTree();

			testTree.Add(5);
			testTree.Add(10);
			testTree.Add(13);
			testTree.Add(3);
			testTree.Add(2);
			testTree.Add(4);
			/* Based on this order of adding, the tree should look like this:
							5
						   / \
						  3	  10
			             / \    \
			            2   4    13
			*/
			testTree.Remove(5);
			testTree.Remove(2);
			/* After removing, the tree should look like this:
							10
						   /  \
						  3	   13
						   \    
						    4    
			*/


			Assert::AreEqual(10, testTree.GetFirstNode()->value);
			Assert::AreEqual(13, testTree.GetFirstNode()->right->value);
			Assert::AreEqual(3, testTree.GetFirstNode()->left->value);
			Assert::AreEqual(4, testTree.GetFirstNode()->left->right->value);
			
			Assert::IsNull(testTree.GetFirstNode()->left->left);
			Assert::IsNull(testTree.GetFirstNode()->right->right);
		}
		
		TEST_METHOD(RemoveTest2)
		{
			BinaryTree testTree = BinaryTree();

			testTree.Add(100);
			testTree.Add(10);
			testTree.Add(13);
			testTree.Add(3);

			testTree.Add(122);
			testTree.Add(119);

			testTree.Add(2);
			testTree.Add(4);

			testTree.Add(123);
			testTree.Add(110);
			/* Based on this order of adding, the tree should look like this:
							 100
						    /   \
						  10	 122 
			             / \     /  \
			            3   13  119 123
					   / \		/	   
					  2   4   110        

			*/
			testTree.Remove(100);
			testTree.Remove(2);
			testTree.Remove(10);
			testTree.Remove(123);
			/* After removing, the tree should look like this:
							 110
							/   \
						  13	 122
						 /       /  
						3      119 
					     \		
					      4   

			*/

			Assert::AreEqual(110, testTree.GetFirstNode()->value);
			Assert::AreEqual(13, testTree.GetFirstNode()->left->value);
			Assert::AreEqual(3, testTree.GetFirstNode()->left->left->value);
			Assert::AreEqual(4, testTree.GetFirstNode()->left->left->right->value);

			Assert::AreEqual(122, testTree.GetFirstNode()->right->value);
			Assert::AreEqual(119, testTree.GetFirstNode()->right->left->value);
			
			

			Assert::IsNull(testTree.GetFirstNode()->left->left->left);
			Assert::IsNull(testTree.GetFirstNode()->right->left->left);
			Assert::IsNull(testTree.GetFirstNode()->right->right);
			

		}


		TEST_METHOD(RemoveTest3)
		{
			BinaryTree testTree = BinaryTree();

			testTree.Add(100);
			testTree.Add(10);
			testTree.Add(13);
			testTree.Add(3);
			testTree.Add(122);
			testTree.Add(119);
			testTree.Add(2);
			testTree.Add(4);
			testTree.Add(123);
			testTree.Add(110);
			/* Base on this order of adding, the tree should look like this:
							 100
							/   \
						  10	 122
						 / \     /  \
						3   13  119 123
					   / \		/
					  2   4   110

			*/
			testTree.Remove(100);
			testTree.Remove(110);
			testTree.Remove(119);
			testTree.Remove(122);
			testTree.Remove(123);
			testTree.Remove(10);
			testTree.Remove(13);
			/* Base on this order of removing, the tree should look like this:
							 3
							/ \
						   2   4
			*/

			Assert::AreEqual(3, testTree.GetFirstNode()->value);
			Assert::AreEqual(2, testTree.GetFirstNode()->left->value);
			Assert::AreEqual(4, testTree.GetFirstNode()->right->value);

			Assert::IsNull(testTree.GetFirstNode()->left->left);
			Assert::IsNull(testTree.GetFirstNode()->left->right);
			Assert::IsNull(testTree.GetFirstNode()->right->right);
			Assert::IsNull(testTree.GetFirstNode()->right->left);

		}


		TEST_METHOD(RemoveAddTest)
		{
			BinaryTree testTree = BinaryTree();

			testTree.Add(100);
			testTree.Add(10);
			testTree.Add(13);
			testTree.Add(3);

			testTree.Add(122);
			testTree.Add(119);

			testTree.Add(2);
			testTree.Add(4);

			testTree.Add(123);
			testTree.Add(110);

			/* Base on this order of adding, the tree should look like this:
							 100
							/   \
						  10	 122
						 / \     /  \
						3   13  119 123
					   / \		/
					  2   4   110

			*/


			testTree.Remove(100);
			testTree.Remove(110);
			testTree.Remove(119);
			testTree.Remove(122);
			testTree.Remove(123);

			testTree.Remove(10);
			testTree.Remove(13);

			/* Base on this order of removing, the tree should look like this:
							 3
							/ \
						   2   4
			*/

			testTree.Add(6);
			testTree.Add(5);
			testTree.Add(7);
			testTree.Add(0);
			testTree.Add(1);
			/* Base on this order of removing, the tree should look like this:
							 3
							/ \
						   2   4
						  /		\
						 0		 6
						  \	    / \
						   1   5   7
			*/



			Assert::AreEqual(1, testTree.GetFirstNode()->left->left->right->value);
			Assert::AreEqual(7, testTree.GetFirstNode()->right->right->right->value);
			Assert::AreEqual(5, testTree.GetFirstNode()->right->right->left->value);


		}
	};
}
