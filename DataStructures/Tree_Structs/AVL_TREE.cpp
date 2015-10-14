#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;
	struct *parent;

	int height;
};


int height_of_tree(struct node *root)
{
	if (root == NULL)
	return 0;
	
	return root->height;
}


struct node* create_new_node(int key)
{
	struct node* node = new node();
	
	node->key = key;
	node-> left = NULL;
	node->right = NULL;
	node->height = 1;

	return (node);
}


struct node *rotate_right(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	// perform rotation
	x->right = y;
	y-> left = T2;


	// update the new heights
	y->height = max(height_of_tree(y->left),height_of_tree(y->right)) + 1;
	x->height = max(height_of_tree(x->left),height_of_tree(x->right)) + 1;

	return x;
}

struct node *rotate_left(struct node *x)
{
	struct node *y = x->right;
	struct node T2 = y->left;

	//perform rotation
	y->left = x;
	x->right = T2;

	//update the heights
	x->height = max(height_of_tree(x->left), height_of_tree(x->right)) + 1;
	y->height = max(height_of_tree(y->left), height_of_tree(y->right)) + 1;	

	return y;
}

int getBalanceFactor(struct node* root)
{
	if (root == NULL)
		return 0;

	return height_of_tree(root->left)-height_of_tree(root->right);
}

struct node *insert(struct node* node, int key)
{
	if (node == NULL)
		return create_new_node(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->righ, key);

	// now the rebalancing is done here.
	// update height of this ancestor node
	node->height = max(height_of_tree(node->left), height_of_tree(node->right)) +1;

	// get the balance factor for this ancestor node to check if it is fine or needs rebalancing
	int balance = getBalanceFactor(node);

	// LL
	if(balance > 1 && key < node->left->key)
		return rotate_right(node);

	// RR
    	if (balance < -1 && key > node->right->key)
        	return rotate_left(node);
 
    	// LR
    	if (balance > 1 && key > node->left->key)
    	{
        	node->left =  rotate_left(node->left);
        	return rotate_right(node);
    	}
 
	    // RL
    	if (balance < -1 && key < node->right->key)
    	{
        	node->right = rotate_right(node->right);
        	return rotate_left(node);
    	}
 
    return node;
}

struct node* minValueNode(struct node* root)
{
	if (root == NULL)
		return NULL;

	struct node* tmp;

	while(tmp->left !=  NULL)
		tmp = tmp->left;

	return tmp;
}

struct node* deleteNode(struct node* root, int key)
{
	// Perform standard BST delete
	if (root == NULL)
		return NULL;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->right)
		root->right = deleteNode(root->right, key);
	else
	{
		// node with only one child or no child
		if(root->left == NULL || root->right == NULL)
		{
			struct node *tmp = root->right ? root->right : root->left;

			// no child
			if(tmp == NULL)
			{
				tmp = root;
				root = NULL;
			}
			else
				*root = *tmp;

			delete tmp;
		}
		else
		{
			struct node* successor = minValueNode(root->right);

			root->key = tmp->key;
			root->right = deleteNode(root->right, tmp->key);
		}

	}

	if (root == NULL)
		return NULL;


	// Step 2 here: update height of node = root
	root->height = max(height_of_tree(root->left), height_of_tree(root->right))+1;

	// get the balance fctor
	int balance = getBalanceFactor(root);

	// LL
	if (balance > 1 && getBalanceFactor(root->left) >= 0)
		return rotate_right(root);

	// LR
    	if (balance > 1 && getBalance(root->left) < 0)
    	{
        	root->left =  rotate_left(root->left);
        	return rotate_right(root);
    	}
 
	// RR
    	if (balance < -1 && getBalance(root->right) <= 0)
       		return rotate_left(root);
 
    	// RL
   	if (balance < -1 && getBalance(root->right) > 0)
    	{
        	root->right = rotate_right(root->right);
        	return rotate_left(root);
    	}


return root;
}


int main()
{

 // Fill in testing code here.

return 0;
}
