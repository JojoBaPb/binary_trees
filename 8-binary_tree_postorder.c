#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses binary tree using post-order traversal.
 * @tree: Pointer to root node of the tree for traversal.
 * @func: Pointer to a func to call each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
