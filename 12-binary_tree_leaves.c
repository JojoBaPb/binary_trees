#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts leaves in binary tree.
 * @tree: Pointer to root node of tree for leaves to be counted.
 * Return: Number of leaves in tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves0 = 0;

	if (tree)
	{
		leaves0 += (!tree->left && !tree->right) ? 1 : 0;
		leaves0 += binary_tree_leaves(tree->left);
		leaves0 += binary_tree_leaves(tree->right);
	}
	return (leaves0);
}
