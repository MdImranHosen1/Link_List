#include<bits/stdc++.h>
using namespace std;

struct node {

	int val;
	struct node* link;
};
//head->0->1->2->3->4
void updateFont(node *Header, int value)
{
	node *newNode;
	newNode = (node*)malloc(sizeof(node));

	newNode->link = Header->link;
	Header->link = newNode;
	newNode->val = value;
}
//head->0->1->2->3->4
void updateLast(node *Header, int value)
{
	node *newNode;
	newNode = (node*)malloc(sizeof(node));

	//temp node point to the last node
	node *temp = Header;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	newNode->link = temp->link;
	temp->link = newNode;
	newNode->val = value;
}

//head->0->1->2->3->4
void updateAt(node *Header, int value, int pos)
{
	node *newNode;
	newNode = (node*)malloc(sizeof(node));

	int currentPos = -1;
	node *temp = Header;
	while (currentPos - 1 < pos and temp->link != NULL)
	{
		temp = temp->link;
		currentPos++;
	}

	if (currentPos - 1 == pos)
	{
		newNode->link = temp->link;
		temp->link = newNode;
		newNode->val = value;
	}
}

//head->0->1->2->3->4
void updateBeforeValue(node *Header, int value, int valpos)
{
	node *newNode;
	newNode = (node*) malloc(sizeof(node));

	node *temp1 = Header, *temp2 = Header;
	temp1 = temp1->link;
	while (temp1->link != NULL and temp1->val != valpos)
	{
		temp1 = temp1->link;
		temp2 = temp2->link;
	}

	if (temp1->link != NULL)
	{
		newNode->link = temp2->link;
		temp2->link = newNode;
		newNode->val = value;
	}
}


int main()
{
	node* Header;
	Header = (node *)malloc(sizeof(node));
	Header->val = INT_MAX;
	Header->link = NULL;


	int n; cin >> n;
	while (n--)
	{
		int opn; cin >> opn;
		if (opn == 0)
		{
			int val; cin >> val;
			updateFont(Header, val);
		}
		else if (opn == 1)
		{
			int val; cin >> val;
			updateLast(Header, val);

		}
		else if (opn == 2)
		{
			int val, pos; cin >> val >> pos;
			updateAt(Header, val, pos);

		}
		else if (opn == 3)
		{
			int val, valpos; cin >> val >> valpos;
			updateBeforeValue(Header, val, valpos);
		}

	}

	node *temp = Header;
	temp = temp->link;
	while (temp->link != NULL)
	{
		cout << temp->val << " ";
		temp = temp->link;
		if (temp->link == NULL)
			cout << temp->val << " ";

	}
	cout << endl;
}