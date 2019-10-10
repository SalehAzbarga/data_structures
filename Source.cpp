// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>

struct node
{
	int data;
	struct node *next;
};

void print_list(node* head)
{
	node* tmp = head;
	while (tmp != NULL)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("%s", "\n");
}

void remove_node(int n, node*& head, node*& tail)
{
	node* tmp;
	tmp = head;

	if (head == NULL)
		return; //empty list
	if (head->data == n)
	{
		head = tmp->next;
		delete tmp;
	}
	else
	{
		while (tmp->next != NULL)
		{
			if (tmp->next->data == n)
			{
				node* node_to_delete = tmp->next;
				tmp->next = node_to_delete->next;
				delete node_to_delete;
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
}

void add_node(int n, node*& head, node*& tail)
{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
		tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tail->next;
	}
}



int main()
{
	node *head = NULL;
	node *tail = NULL;

	for (int i = 0; i < 5; i++)
	{
		add_node(i + 1, head, tail);
	};
	print_list(head);
	remove_node(3, head, tail);
	print_list(head);
}