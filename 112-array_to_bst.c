#include "binary_trees.h"

/**
 * array_to_bst - Builds binary search tree from array.
 * @array: Pointer to 1st element of array to be converted.
 * @size: Number of elements in @array.
 * Return: Pointer to root node of created BST, NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (bst_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
