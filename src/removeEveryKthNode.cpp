/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.
INPUTS: A linked list and Value of K.
OUTPUT: Remove every Kth node in the linked list.
ERROR CASES: Return NULL for error cases.
NOTES:
*/

#include<stdlib.h>
#include <stdio.h>
struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int k) {
	int count = 0, m, c = 0;
	struct node *ptr, *pt, *temp;
	ptr = head;
	pt = ptr;
	temp = head;
	if (head == NULL || k <= 0 || k == 1)
		return NULL;
	else
	{
		while (ptr != NULL)
		{
			count++;
			m = count - 2 - c;
			if (count%k == 0)
			{
				pt = head;
				temp = head;
				while (m>0)
				{
					pt = pt->next;
					m--;
				}
				m = count - 1 - c;
				while (m>0)
				{
					temp = temp->next;
					m--;
				}
				if (ptr->next != NULL)
				{
					ptr = ptr->next;
					count++;
					pt->next = ptr;
					temp->next = NULL;
					c++;
				}
				else
				{
					pt->next = NULL;
					ptr = NULL;
					break;
				}
			}
			ptr = ptr->next;
		}
	}
	return head;
}