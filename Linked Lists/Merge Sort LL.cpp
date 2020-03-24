#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
		node(int data){
			this->data = data;
			this->next = NULL;
		}
};

node* mid(node *head){
	node *slow = head, *fast = head;
	while(fast->next!=NULL && fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* merge(node* first, node* second){
	if(first == NULL){
		return second;
	}
	if(second == NULL){
		return first;
	}
	
	//recursive case
	node *new_head;
	if(first->data <= second->data){
		new_head = first;
		new_head->next = merge(first->next, second);
	}else{
		new_head = second;
		new_head->next = merge(first, second->next);
	}
	return new_head;
}

node* mergeSort(node *head){
	if(head==NULL || head->next==NULL) //base case
		return head;
	node *middle = mid(head);
	node* first = head;
	node* second = middle->next;
	middle->next = NULL; //divide in two LL
	first = mergeSort(first); //recursive call
	second = mergeSort(second); //recursive call
	return merge(first, second);
}

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
	if(head==NULL){
		cout<<"\n";
		return;
	}		
	cout<<head->data<<" ";
	printList(head->next);
}

int main(){
	node *head = NULL;
	insertAtHead(head, 1);
	insertAtHead(head, 15);
	insertAtHead(head, 9);
	insertAtHead(head, 30);
	insertAtHead(head, 52);
	insertAtHead(head, 4);
	printList(head);
	head = mergeSort(head);
	printList(head);
}
