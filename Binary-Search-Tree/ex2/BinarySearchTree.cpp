#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

//Public functions

/*
* Initializes the bst to empty.
*/
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

/*
* Determines whether the bst is empty
*
* Returns true if the bst is empty, false otherwise
*/
bool BinarySearchTree::isEmpty()
{
	return root == NULL;
}

/*
* Prints the bst elements using inorder traversal. This method invokes the
* private method inorderDisplay, passing to it the root of the actual tree.
*/
void BinarySearchTree::display()
{
	inorderDisplay(root);
	cout << endl;
}

/*
* Determines if an item exists in the bst. This method invokes the private
* method search, passing to it the element to be found and the root
* of the actual tree.
* 
* x: element to be found.
*
* Returns true if x is found in the bst, false otherwise.
*/
bool BinarySearchTree::search(int x)
{
	return search(x, root);
}

/*
* Adds the element x to the bst. This method invokes the private method
* add, passing to it the element to be added to the bst and the root
* of the actual tree.
*
* x: element to be added to the bst.
*/
void BinarySearchTree::add(int x)
{
	add(x, root);
}

/*
* Finds the smallest value in the bst. This method invokes the overloaded
* method getMinimum, passing to it the root of the tree.
*
* Returns the smallest value in the bst.
*/
int BinarySearchTree::getMinimum()
{
	return getMinimum(root)->info;
}

/*
* Destructor. Invokes the method deallocateMemory, passing to it the root
* of the tree.
*/
BinarySearchTree::~BinarySearchTree()
{
	deallocateMemory(root);
}

//Private functions

/*
* Prints the elements of the subtree whose root is pointed to by p. Uses
* inorder traversal.
*
* p: root of subtree.
*/
void BinarySearchTree::inorderDisplay(TreeNode *p)
{
	if (p != NULL)
	{
		if (p->left != NULL)
			inorderDisplay(p->left);
		cout << p->info << " ";
		if (p->right != NULL)
			inorderDisplay(p->right);
	}
}

/*
* Adds x to the subtree pointed to by p. The search for the location to
* insert the new node is conducted recursively, using the bst property:
* keys in the left subtree of a node are smaller than or equal to the key
* in the node, while the keys in the right subtree of the node are greater.
*
* x: element to be added to the subtree.
* p: root of subtree.
*/
void BinarySearchTree::add(int x, TreeNode* & p)
{
	if (p == NULL)
	{
		p = new TreeNode;
		p->info = x;
		p->left = p->right = NULL;
	}
	else
	{
		if (x <= p->info) add(x, p->left);
		else add(x, p->right);
	}
}

/*
* Finds if x is present in the subtree whose root is pointed to by p. The
* search is conducted recursively, using the bst property: keys in the left
* subtree of a node are smaller than or equal to the key in the node, while
* the keys in the right subtree of the node are greater.
*
* x: element to be found.
* p: root of subtree.
*
* Returns true if x is found in this subtree, false otherwise.
*/
bool BinarySearchTree::search(int x, TreeNode* p)
{
	if (p == NULL) return false;
	else
		if (x == p->info) return true;
		else 
			if (x < p->info) return search(x, p->left);
			else return search(x, p->right);
}

/*
* Recursively finds the smallest value in the subtree pointed to by p.
* The method uses this property of BSTs: the smallest value is stored in
* the leftmost node.
*
* p: root of subtree.
*
* Returns smallest value in the subtree pointed to by p.
*/
TreeNode* BinarySearchTree::getMinimum(TreeNode* p)
{
	if (p->left == NULL) return p;
	else return getMinimum(p->left);
}

/*
* Recursively deallocates the memory of the subtree pointed to by p.
*
* p: root of subtree.
*/
void BinarySearchTree::deallocateMemory(TreeNode* & p)
{
	if (p != NULL)
	{
		deallocateMemory(p->left);
		deallocateMemory(p->right);
		delete p;

		p = NULL;
	}
}

void BinarySearchTree::clear()
{
	clear(root);
	root = NULL;
}

void BinarySearchTree::clear(TreeNode* p)
{
	if (p == NULL) return;

	clear(p->left);
	clear(p->right);

	delete p;
	p = NULL;
}

void BinarySearchTree::count(TreeNode* p, int item, int& ct)
{
	if (p == NULL)
		return;

	if (item == p->info)
		ct++;

	if (p->left == NULL && p->right == NULL)
		return;

	if (p->left != NULL)
		count(p->left, item, ct);

	if (p->right != NULL)
		count(p->right, item, ct);
}

int BinarySearchTree::count(int item)
{
	int ct = 0;
	count(root, item, ct);
	return ct;
}
string BinarySearchTree::to_string()
{
	string str = "";
	to_string(root, str);
	 return str;
}

void BinarySearchTree::to_string(TreeNode* p, string& str)
{
	if (p == NULL)
		return;

	str = str + std::to_string(p->info);

	if (p->left == NULL && p->right == NULL)
		return;

	if (p->left != NULL)
		to_string(p->left, str+= ", ");

	if (p->right != NULL)
		to_string(p->right, str += ", ");
}