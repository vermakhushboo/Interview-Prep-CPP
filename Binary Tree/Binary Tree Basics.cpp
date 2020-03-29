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

void preorderTraversal(node *root){ //Node Left Right (NLR)
	//base case
	if(root == NULL)
		return;
		
	//recursive case
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(node *root){ //Left Node Right (LNR)
	//base case
	if(root == NULL)
		return;
		
	//recursive case
	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}

void postorderTraversal(node *root){ //Left Right Node (LRN)
	//base case
	if(root == NULL)
		return;
	
	//recursive case
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" ";
}

int main(){
	node *root = buildTree();
	cout<<"Preorder Traversal of Tree is: \n";
	preorderTraversal(root);
	cout<<"\n";
	cout<<"Inorder Traversal of Tree is: \n";
	inorderTraversal(root);
	cout<<"\n";
	cout<<"Postorder Traversal of Tree is: \n";
	postorderTraversal(root);
	cout<<"\n";
}
