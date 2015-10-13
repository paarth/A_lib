#include <iostream>
#include <cstdio>

using namespace std;;

typedef struct tree
{
	int item;
	struct tree *parent;
	struct tree *left;	
	struct tree *right;

} tree;


// Searching in a BST
tree *search_tree(tree *root, int value)
{
	if (root == NULL)
		return NULL;

	if (root->item == value)
		return root;

	if (value < root->item)
		return ( search_tree(root->left, value) );
	else
		return ( search_tree(root->right, value) );
}

// finding minimum in a BST
tree *find_min(tree *root)
{
	tree *min_tree;

	if (root == NULL)
		return NULL;

	min_tree = root;

	// iterate through all the elements of left chain and find out the min at the end
	while(min_tree->left != NULL)
		min_tree = min_tree -> left;

	return min_tree;
}

// traversing the BST
void traverse_tree(tree *root)
{
	if (root == NULL)
		return;

	traverse_tree(root->left);
	cout<<root->item<<"\n";
	traverse_tree(root->right);
}

// insertion in a BST
void insert_tree(tree **root, int value, tree *parent)
{
	tree *tmp;

	if (*root == NULL)
	{
		tmp = new tree();
		tmp->item = value;
		tmp->left = tmp->right = NULL;
		tmp->parent = parent;
		*root = tmp;
		return;
	}

	if (value < (*root)->item)
		insert_tree(&((*root)->left), value, *root);
	else
		insert_tree(&((*root)->right), value, *root);

}
tree *find_successor(tree *root)
{
	if (root == NULL)
		return NULL;

	return find_min(root->right);
}

// remove/delete a node from BST
void remove_tree_node(tree *root)
{
	if (root == NULL)
		return;

	// if current root is leaf node
	if (root->left == NULL && root->right == NULL)
	{
										// if cur_root is left child of parent
		if (root == root->parent->left)
		{
			tree *to_be_freed = root->parent->left;
			root->parent->left = NULL;
			delete to_be_freed;
		}	

		else 							// if cur_root is left child of parent
		{
			tree *to_be_freed = root->parent->right;
			root->parent->right = NULL;
			delete to_be_freed;
		}
	}
	else if (root->left != NULL && root->right != NULL) // cur_root have both children
	{
		tree *successor = find_successor(root); // successor will find the smallest value in right subtree
		root->item = successor->item;
		remove_tree_node(successor);
	}
	else 												// Current root have one child
	{
		// if cur root have right child
		if (root->right != NULL)
		{
			root->parent->right = root->right;
			delete root;
			return;
		}
		else // cur_root have left child
		{
			root->parent->left = root->left;
			delete root;
			return;
		}
	}
}



// Deletion from BST
void delete_tree(tree **root, int value, tree *parent)
{
	if (*root == NULL)
		return;

	tree *node_to_be_deleted = NULL;
	node_to_be_deleted = search_tree(*root, value);

	if (node_to_be_deleted == NULL)
		return;

	remove_tree_node(node_to_be_deleted);
}

int main()
{
	struct tree *root = NULL;
	// void insert_tree(tree **root, int value, tree *parent)
	insert_tree(&root, 50, root);
	insert_tree(&root, 70, root);
	insert_tree(&root, 30, root);
	insert_tree(&root, 20, root);
	insert_tree(&root, 40, root);		
	insert_tree(&root, 60, root);

	// print the traversal of tree right now
	traverse_tree(root);
	cout<<"\n======================\n";

	delete_tree(&root, 40, root);

	// print tree traversal now
	traverse_tree(root);
	cout<<"\n======================\n";

	delete_tree(&root, 60, root);

	// print tree traversal now
	traverse_tree(root);
	cout<<"\n======================\n";

	
	return 0;
}
