#include "binary_trees.h"

/**
 * is_bst_helper - Checks if binary tree is valid binary search tree.
 * @tree: Pointer to root node of tree to check.
 * @lo: Value of the smallest node visited thus far.
 * @hi: Value of largest node visited so far.
 * Return: If tree is valid BST 1, else, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
				is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if binary tree is valid binary search tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is valid BST, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
