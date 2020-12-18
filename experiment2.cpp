
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* next;
	node(int d){
		data=d;
		next=NULL;
	}
};
void insert(node* &head,int d){
	 node* temp;
	 node* n=new node(d);
	 if(head==NULL || head->data >=n->data){
	 	n->next=head;
	 	head=n;
	 }
	 else{
	 	temp=head;
	 	while(temp->next!=NULL && temp->next->data < n->data){
	 		temp=temp->next;
		 }
		 n->next=temp->next;
		 temp->next=n;
	 }
}
bool search(node* head,int x){
	while(head!=NULL){
		if(head->data==x){
			return true;
		}else{
			head=head->next;
		}
	}
	return false;
}
void del(node* &head,int x){
	if(head->data==x){
		head=head->next;
	}else{
		node* p=head;
		node* temp=head->next;
		while(temp!=NULL){
			if(temp->data==x){
				temp=temp->next;
				p->next=temp;
			}else{
				temp=temp->next;
				p=p->next;
			}
		}
	}
}
void display(node*  head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head=head->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	node* head=NULL;
	
	cout<<"HELLO USER"<<endl<<"Enter The Digit From The Given MENU"<<endl;
	cout<<"1) INSERT THE ELEMENT"<<endl;
	cout<<"2) DELETE THE ELEMENT"<<endl;
	cout<<"3) SEARCH THE ELEMENT"<<endl;
	cout<<"4) DISPLAY THE ELEMENT"<<endl;
	cout<<"5) QUIT"<<endl;
	int n;
	
	do{
		
	cin>>n;
	switch(n){
		case 1:
			cout<<"Enter The Element"<<endl;
			int d;
			cin>>d;
			insert(head,d);
			display(head);
			break;
		case 2:
			cout<<"Enter the Element You Want to delete"<<endl;
			int x;
			cin>>x;
			del(head,x);
			display(head);
			break;
		case 3:
			cout<<"Enter the Element You Want to Search"<<endl;
			int x1;
			cin>>x1;
			if(search(head,x1)==1){
				cout<<"TRUE"<<endl;
			}else{
				cout<<"FALSE"<<endl;
			}
			break;
		case 4:
			display(head);
			break;
		case 5:
			break;
		default:
			cout<<"Invalid Input";
	}
	cout<<"Please Enter AGAIN From The given MENU ABOVE"<<endl<<"[[[[[[ 	FOR QUIT PRESS 5	]]]]]]"<<endl;
}while(n!=5);
	return 0;
}
