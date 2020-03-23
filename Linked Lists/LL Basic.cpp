#include<iostream>
using namespace std;

class node{
	public:
		int data = -1;
		node *next = NULL;
	
		node(int data){
			this->data = data;
			this->next = NULL;
		}
};

void insertAtHead(node *&head, int value){ //NOTE: passing head by reference
	if(head == NULL){
		head = new node(value);
		return;
	}
	node *newNode = new node(value);
	newNode->next = head;
	head = newNode;	
}

void printList(node *head){ //No modifications to value of head
	if(head==NULL)
		return;
	cout<<head->data<<" ";
	printList(head->next);
}

int main(){
	node *head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 2);
	printList(head);
}
