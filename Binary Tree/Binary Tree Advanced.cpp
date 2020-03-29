#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *left;
		node *right;
		
		node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};

node* buildTree(){
	int data;
	cin>>data;
	
	if(data == -1)
		return NULL;
	
	node *root = new node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

//print the kth level of a tree
void printKthLevel(node *root, int k){
	if(root == NULL){
		return;
	}
	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
}

int main(){
	node *root = buildTree();
	printKthLevel(root, 2);
}
