#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - Measures height of a binary tree.
 * @tree: Pointer to root node of tree for height measure.
 * Return: If tree is NULL, func must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Measures balance factor of a binary tree.
 * @tree: Pointer to root node of tree to measure balance factor.
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Insert value into AVL tree recursively.
 * @tree: Double pointer to root node of the AVL tree.
 * @parent: Parent node of current working node.
 * @new: Double pointer to store new node.
 * @value: Value to insert into the AVL tree.
 * Return: Pointer to new root after insertion, else NULL on fail.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int w8;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	w8 = balance(*tree);
	if (w8 > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (w8 < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (w8 > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (w8 < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts value into AVL tree.
 * @tree: Double pointer to root node of AVL tree.
 * @value: Value we want to insert into the AVL tree.
 * Return: Pointer to inserted node, else NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
