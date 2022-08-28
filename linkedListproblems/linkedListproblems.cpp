#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
}*Head=NULL;


//function declarations

struct Node* createLL(int a[], int n);

void DisplayLL(struct Node* head);

int countNode(struct Node* head);

int floor(int a);

int ceilValue(int a);

struct Node* MiddleNode1(struct Node* head);

struct Node* MiddleNode2(struct Node* head);

struct Node* MiddleNode3(struct Node* head);



//function definitions

struct Node* createLL(int a[], int n)
{
	//empty list
	if (n == 0)
		return NULL;

	//single node
	struct Node* head, * p;
	head = new Node;
	p = head;
	for (int i = 0;i < n;i++)
	{
		//first node
		if (i==0)
		{
			p->data = a[i];
		}
		else
		{
			struct Node* newnode = new Node;
			newnode->data = a[i];
			p->next = newnode;
			p = newnode;
		}
		p->next = NULL;
	}
	return head;
}

void DisplayLL(struct Node* head)
{
	if (!head)
	{
		cout << "Empty List ";
		return;
	}

	struct Node* p = head;

	while (p)
	{
		cout << p->data<<" ";
		p = p->next;
	}
}

int countNode(struct Node* head)
{
	if (!head)
		return 0;

	struct Node* p = head;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

int floor(int a)
{
	return a / 2;
}

int ceilValue(int a)
{
	if (a%2)
		return (a / 2) + 1;
	return a / 2;
}

struct Node* MiddleNode1(struct Node* head)
{
	//empty list
	if (!head)
	{
		cout << "Empty List -> no mid node. " << endl;
		return NULL;
	}

	//single node
	if (!head->next)
		return head;

	//more than node
	struct Node* p = head;

	int c = 0;

	while (p)
	{
		c++;
		p = p->next;
	}
	
	int mid = c%2 ? c / 2 + 1 : c / 2;
	c = 0;
	p = head;
	while (c < mid - 1)
	{
		c++;
		p = p->next;
	}
	return p;

}

struct Node* MiddleNode2(struct Node* head)
{
	int count = countNode(head);
	if (!count)
		return NULL;
	

	//single node  -> head itself mid node
	if (count == 1)
		return head;

	//more than one node
	struct Node* p = head;

	int mid = count % 2 ? ceilValue(count) : floor(count);
	for (int i = 0;i < mid - 1;i++)
		p = p->next;

	return p;
}

struct Node* MiddleNode3(struct Node* head) 
{
	if (!head)
		return NULL;

	//single node or more than one node
	struct Node* slow, * fast;
	slow = fast = head;

	while (fast)
	{
		fast = fast->next ? fast->next->next : NULL;
		slow = fast ? slow->next : slow;
	}
	return slow;

}

//using stack middle node finding should be done -> MiddleNode4 method

int main()
{
	int a[8] = { 10,20,30,40,50,60,70,80 };

	Head = createLL(a, 7);

	DisplayLL(Head);cout << endl;

	cout << "Number of Node : " << countNode(Head) << endl;

	cout << "floor value : " << floor(countNode(Head)) << endl;

	cout << "Ceil value : " << ceilValue(countNode(Head)) << endl;
	struct Node* midLoc;

	int midNodeVal;
	midLoc = MiddleNode2(Head);

	//check for valid mid node
	if (midNodeVal=midLoc?midLoc->data:0)
		cout << "Mid Node : " << midNodeVal << endl;
		
	else
		cout << "No Mid Node -> In empty list" << endl;
	


}
