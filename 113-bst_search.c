#include "binary_trees.h"

/**
 * bst_search - Searches for value in a binary search tree.
 * @tree: Pointer to root node of BST.
 * @value: Value to search for in BST.
 * Return: If tree is NULL or value not found, NULL.
 * Else, pointer to node containing said value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
