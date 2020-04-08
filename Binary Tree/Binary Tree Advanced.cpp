#include<iostream>
#include<queue>
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

//Level Order Traversal of Binary Tree
//with each level on a new line
void levelOrder(node *root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* queue_front = q.front();
		if(queue_front == NULL){
			cout<<"\n";
			q.pop();
			if(!q.empty()) //if not on last level
				q.push(NULL);
		}
		else{
			q.pop();
			//print the current value
			cout<<queue_front->data<<" ";
			
			//push left and right children if they exist
			if(queue_front->left != NULL)
				q.push(queue_front->left);
			if(queue_front->right != NULL)
				q.push(queue_front->right);
		}
	}
}

//diameter of binary tree
//inefficient because calls height function every time
int diameterOfTree(node *root){
	if(root == NULL)
		return 0;
	int option_1 = heightOfTree(root->left) + heightOfTree(root->right);
	int option_2 = max(diameterOfTree(root->left), diameterOfTree(root->right)) + 1;
	return max(option_1, option_2);
}

int main(){
	node *root = buildTree();
	printKthLevel(root, 2);
	cout<<endl;
	cout<<"Height of Tree "<<heightOfTree(root)<<endl;
//	levelOrder(root);
	cout<<"Diameter of Tree "<<diameterOfTree(root)<<endl;	
}

//5 2 7 -1 -1 9 3 -1 -1 -1 1 3 -1 6 -1 -1 4 -1 -1 (Sample Input)

//			5
//		  /  \
//		 2    1
//		/ \  / \
//	   7  9  3  4
//	     /   \
//	    3     6
