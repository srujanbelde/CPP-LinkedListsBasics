/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *temp,*ptr;
	int k;
	if (head==NULL)
		return NULL;
	else
	{
		for (ptr = head; ptr->next != NULL; ptr=ptr->next)
		{
			for (temp = ptr->next; temp!= NULL;temp=temp->next)
			{
				if (ptr->num > temp->num)
				{
					k = ptr->num;
					ptr->num = temp->num;
					temp->num = k;
				}
			}
		}
	}
	return head;
}