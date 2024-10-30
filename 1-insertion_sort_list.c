#include "sort.h"
/**
 * swap_nodes - function to swap nodes
 * @list - list
 * @node1 - first node
 * @node2 - second node
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *current;

	if (node1 == NULL || node2 == NULL)
		return;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	current = *list;
	while (current != NULL)
	{
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * insertion_sort_list - sorts the list
 * @list - the list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		listint_t *insert;
		
		insert = current->prev;
		while (insert != NULL && insert->n > current->n)
		{
			swap_nodes(list, insert, current);
			insert = current->prev;
		}
		current = current->next;
	}
}
