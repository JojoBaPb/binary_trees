#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: Pointer to root node of tree to rotate.
 * Return: Pointer to new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *roto, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	roto = tree->left;
	tmp = roto->right;
	roto->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = roto;
	roto->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = roto;
		else
			tmp->right = roto;
	}

	return (roto);
}
