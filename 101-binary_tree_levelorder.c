#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: Binary tree node for the new node to contain.
 * Return: If error occurs, NULL.
 * Else, pointer to new node.
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
 * free_queue - Frees levelorder_queue_t queue.
 * @head: Pointer to the head of the queue.
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
 * pint_push - Runs func on given binary tree node and
 * pushes children into levelorder_queue_t queue.
 * @node: Binary tree node to print and push.
 * @head: Double pointer to the head of queue.
 * @tail: Double pointer to the tail of queue.
 * @func: Pointer to func to call on @node.
 * Description: malloc failure = exit with status code 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new1;

	func(node->n);
	if (node->left != NULL)
	{
		new1 = create_node(node->left);
		if (new1 == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new1;
		*tail = new1;
	}
	if (node->right != NULL)
	{
		new1 = create_node(node->right);
		if (new1 == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new1;
		*tail = new1;
	}
}

/**
 * pop - Pops head of levelorder_queue_t queue.
 * @head: Double pointer to head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 * level-order traversal.
 * @tree: Pointer to root node of tree to traverse.
 * @func: Pointer to func to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
