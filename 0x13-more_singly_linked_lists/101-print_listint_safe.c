#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *slow, *fast, *loop;

    if (head == NULL)
    {
        exit(98);
    }

    slow = head;
    fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            loop = find_loop(head, slow);
            break;
        }
    }

    if (loop == NULL)
    {
        return (print_list(head));
    }
    else
    {
        return (print_loop(head, loop));
    }
}

/**
 * find_loop - finds the starting node of a loop in a linked list
 * @head: pointer to the head of the list
 * @meet: pointer to the meeting point of slow and fast pointers
 * Return: pointer to the starting node of the loop, or NULL if no loop
 */
const listint_t *find_loop(const listint_t *head, const listint_t *meet)
{
    const listint_t *start, *end;

    start = head;
    end = meet;

    while (start != end)
    {
        start = start->next;
        end = end->next;
    }

    return (start);
}

/**
 * print_list - prints a list without a loop
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_list(const listint_t *head)
{
    size_t count = 0;

    while (head != NULL)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
        count++;
    }

    return (count);
}

/**
 * print_loop - prints a list with a loop
 * @head: pointer to the head of the list
 * @loop: pointer to the starting node of the loop
 * Return: the number of nodes in the list
 */
size_t print_loop(const listint_t *head, const listint_t *loop)
{
    size_t count = 0;
    const listint_t *current;

    current = head;

    while (current != loop)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
        count++;
    }

    printf("[%p] %d\n", (void *)current, current->n);
    current = current->next;
    count++;

    while (current != loop)
    {
        printf("-> [%p] %d\n", (void *)current, current->n);
        current = current->next;
        count++;
    }

    return (count);
}

