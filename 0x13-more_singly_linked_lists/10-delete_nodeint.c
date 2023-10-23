#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked list
 * @head: double pointer to the head of the list
 * @index: the index of the node that should be deleted, starting at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *current, *temp;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
    {
        return (-1);
    }

    current = *head;

    if (index == 0)
    {
        *head = current->next;
        free(current);
        return (1);
    }

    while (current != NULL && i < index - 1)
    {
        current = current->next;
        i++;
    }

    if (current == NULL || current->next == NULL)
    {
        return (-1);
    }

    temp = current->next->next;
    free(current->next);
    current->next = temp;
    return (1);
}
