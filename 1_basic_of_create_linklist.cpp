#include<bits/stdc++.h>
using namespace std;

struct link_list
{
	int val;
	struct link_list* address;
};

int main()
{
	struct link_list* Head = NULL;
	struct link_list* first = NULL;
	struct link_list* second = NULL;
	struct link_list* third = NULL;


	Head = (struct link_list*) malloc(sizeof(struct link_list));
	first = (struct link_list*)malloc(sizeof(struct link_list));
	second = (struct link_list*)malloc(sizeof(struct link_list));
	third = (struct link_list*)malloc(sizeof(struct link_list));


	Head->val = 0;
	Head->address = first;

	first->val = 1;
	first->address = second;


	second->val = 2;
	second->address = third;

	third->val = 3;
	third->address = NULL;



}

