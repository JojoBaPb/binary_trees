#include "binary_trees.h"

/**
 * array_to_avl - Builds AVL tree from array.
 * @array: Pointer to 1st element of array to be converted.
 * @size: Nnumber of elems in @array.
 * Return: Pointer to root node of created AVL, else NULL if fail.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
