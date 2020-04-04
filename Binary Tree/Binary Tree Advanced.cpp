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

int heightOfTree(node *root){
	if(root == NULL)
		return 0;
	int leftHeight = heightOfTree(root->left);
	int rightHeight = heightOfTree(root->right);
	return max(leftHeight, rightHeight) + 1;
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
	cout<<endl;
	cout<<"Height of Tree "<<heightOfTree(root)<<endl;
}

//5 2 7 -1 -1 9 3 -1 -1 -1 1 3 -1 6 -1 -1 4 -1 -1 (Sample Input)

//			5
//		  /  \
//		 2    1
//		/ \  / \
//	   7  9  3  4
//	     /   \
//	    3     6
