#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 * of another in a binary tree.
 * @parent: Pointer to node to insert left-child in.
 * @value: Value to be stored in new node.
 *
 * Return: If parent is NULL or error occurs - NULL.
 * Otherwise - point to new node.
 *
 * Description: If parent already has left-child, new node
 * takes its place and the old left-child is set as
 * the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
