/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>
#include<stdlib.h>

void insert(int a);
struct node {
	int num;
	struct node *next;
};
struct node * numberToLinkedList(int k) {
	struct node *b;
	b = NULL;
	if (k < 0)
		k = k*-1;
	else if (k<10 && k>-1)
	{
		struct node *a;
		a = (struct node*)malloc(sizeof(struct node));
		a->num = k;
		b = a;
		a->next = NULL;
	}
	while (k>0)
	{
		struct node *a;
		a = (struct node*)malloc(sizeof(struct node));
		a->num = k % 10;
		if (b == NULL)
		{
			b = a;
			a->next = NULL;
		}
		else
		{
			a->next = b;
			b = a;
		}
		k = k / 10;
	}
	return b;
	//return NULL;
}
