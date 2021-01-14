/*#include<bits/stdc++.h>
using namespace std;
class BSTnode{
	public:
		int data;
		BSTnode* left;
		BSTnode* right;
	BSTnode (int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};
BSTnode* minRight(BSTnode* right){
	BSTnode* current=right;
	while(current->left!=NULL){
		current=current->left;
	}
	return current;
}
BSTnode* del(BSTnode* root,int val){
	BSTnode* temp=root;
	if(root==NULL){
		return root;
	}else if(temp->data<val){
		temp->right=del(temp->right,val);
	}else if(temp->data>val){
		temp->left=del(temp->left,val);
	}else{
		if(temp->left==NULL){
			BSTnode* r=temp->right;
			delete temp;
			return r;
		}else if(temp->right==NULL){
			BSTnode* r=temp->left;
			delete temp;
			return r;
		}else{
			BSTnode* r=minRight(temp->right);
			temp->data=r->data;
			temp->right=del(temp->right,r->data);
		}
	}
	return temp;
}
bool search(BSTnode* root,int s){
	BSTnode* temp=root;
	if(root==NULL){
		return false;
	}else{
		while(temp!=NULL){
			if(temp->data==s){
				return true;
			}else if(temp->data>s){
				temp=temp->left;
			}else if(temp->data<s){
				temp=temp->right;
			}
		}
		
	}
	return false;
}
void insert(BSTnode* root,int d){
	
	BSTnode* n=new BSTnode(d);
	if(root==NULL){
		root=n;
	}else{
		BSTnode* temp=root;
		while(temp!=NULL){
			if(n->data==temp->data){
				return;
			}else if((n->data<temp->data )and (temp->left==NULL)){
				temp->left=n;
				break;
			}else if((n->data>temp->data)and(temp->right==NULL)){
				temp->right=n;
				break;
			}else if(n->data<temp->data ){
				temp=temp->left;
			}else if(n->data>temp->data){
				temp=temp->right;
			}
		}
	}
}
void preorder(BSTnode* root){
	if(root ==NULL){
		cout<<"TREE IS NOT HAVING ANY NODE";
		return;
	}
	cout<< root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
/*void inorder(BSTnode* root){
	if(root ==NULL){
		cout<<"TREE IS NOT HAVING ANY NODE";
		return;
	}
	inorder(root->left);
	cout<< root->data<<" ";
	inorder(root->right);
}
void postorder(BSTnode* root){
	if(root ==NULL){
		cout<<"TREE IS NOT HAVING ANY NODE";
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}*//*
int main(){
	BSTnode* root=NULL;
	cout<<"SELECT NO. FROM GIVEN MENU :-"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"1) Insert in Binary Search Tree"<<endl;
	cout<<"2) Search in Binary Search Tree"<<endl;
	cout<<"3) Delete in Binary Search Tree"<<endl;
	cout<<"4) Display in Binary Search Tree"<<endl;
	cout<<"5) Quit"<<endl;
	int n;
	do{
		cin>>n;
		switch(n){
			case 1:
				cout<<"Enter the no. you want to insert"<<endl;
				int d;
				cin>>d;
				insert(root,d);
				break;
			case 2:
				cout<<"Enter the no. you want to Search"<<endl;
				int s;
				cin>>s;
				if(search(root,s)){
					cout<<"Element is Present"<<endl;
				}else{
					cout<<"Element is Not Present"<<endl;
				}
				break;
			case 3:
				cout<<"Enter the no. you want to Delete :-)"<<endl;
				int e;
				cin>>e;
				cout<<del(root,e)<<endl;
				break;
			case 4:
				cout<<"DISPLAY :-))"<<endl;
			/*	cout<<"SELECT FROM GIVEN DISPLAY "<<endl;
				cout<<"1)  inorder :-)"<<endl;
				cout<<"2)  preorder :-)"<<endl;
				cout<<"3)  postorder :-)"<<endl;
				int f;		
				cin>>f;
				switch(f){
					case 1:
						inorder(root);
						break;
					case 2:
						preorder(root);
						break;
					case 3:
						postorder(root);
						break;
					default:
						cout<<"Wrong input :--))"<<endl;
						break;
				}
				preorder(root);
				break;
			case 5:
				cout<<"YOU HAVE QUIT THE PROGRAM"<<endl;
				break;
			default:
				cout<<"Wrong input"<<endl;	
		}
	}while(n!=5);
return 0;
}*/











#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}
//preorder Traversal
void  preorder(struct node *root){
	if(root!=NULL){
		preorder(root->left);
		preorder(root->right);
		printf("%d ->", root->key);
	}
}
//postorder Traversal
void  postorder(struct node *root){
	if(root!=NULL){
		printf("%d ->", root->key);
		postorder(root->left);
		postorder(root->right);
	}
}


// Insert a node
struct node *insert(struct node *node, int key) {
  if (node == NULL){
  	return newNode(key);
  } 
  if (key < node->key){
  	node->left = insert(node->left, key);
  }
  else{
  	node->right = insert(node->right, key);	
  }
  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// finding min value
void min(struct node *root){
	struct node *temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	printf("\nMinimum Value is: ");
	printf("%d\n",temp->key);
}

//finding max value
void max(struct node *root){
	struct node *temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	
	printf("\nMaximum Value is: ");
	printf("%d\n",temp->key);
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
  	return root;
  }
  if (key < root->key){
  	root->left = deleteNode(root->left, key);
  }
  else if (key > root->key){
  	root->right = deleteNode(root->right, key);
  }
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
	 else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

//searching element
bool search(struct node *root,int key){
	struct node *temp=root;	
	while(temp!=NULL){
		if(temp->key==key){
			return true;
		}else if(temp->key<key){
			temp=temp->right;
		}else if(temp->key>key){
			temp=temp->left;
		
		}
	}
	return false;
}


int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
  printf("preorder traversal: ");
  preorder(root);
  printf("\n");
  printf("pstorder traversal: ");
  postorder(root);
  printf("\n");

  printf("\nsearching Element is 6\nIs Element is Present :");
  if(search(root,6)){
  	printf("True\n");
  }else{
  	printf("False\n");
  }
  
  
  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("\n");

    
  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");
  printf("preorder traversal: ");
  preorder(root);
  printf("\n");
  printf("pstorder traversal: ");
  postorder(root);
  printf("\n");
  
  min(root);
  max(root);
  printf("--------------------------------------\n DONE BY PRAKHAR 196032");
}


