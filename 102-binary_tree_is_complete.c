#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates new levelorder_queue_t node.
 * @node: Binary tree node for new node to contain.
 * Return: If error occurs, NULL Else, pointer to new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new1;

	new1 = malloc(sizeof(levelorder_queue_t));
	if (new1 == NULL)
		return (NULL);

	new1->node = node;
	new1->next = NULL;

	return (new1);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: Pointer to head of queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes node to back of a levelorder_queue_t queue.
 * @node: Binary tree node to print and push.
 * @head: Double pointer to head of queue.
 * @tail: Double pointer to tail of queue.
 * Description: Malloc failure, exits with status code 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new1;

	new1 = create_node(node);
	if (new1 == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new1;
	*tail = new1;
}

/**
 * pop - Pops head of a levelorder_queue_t queue.
 * @head: Double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to root node of tree to traverse.
 * Return: If tree is NULL or NOT complete then 0. Else 1.
 * Description: Malloc failure, exits with status code 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char fla = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (fla == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			fla = 1;
		if (head->node->right != NULL)
		{
			if (fla == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			fla = 1;
		pop(&head);
	}
	return (1);
}
