

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


