#include<bits/stdc++.h>
using namespace std;
class qnode{
	public:
		int data;
		qnode* next;
	qnode(int d){
		data=d;
		next=NULL;
	}
};

void push(qnode* &head,qnode* &tail,int d){
	qnode* n=new qnode(d);
	if(head==NULL){
		head=tail=n;
		return;
	}
	tail->next=n;
	tail=n;
}
void pop(qnode* &head,qnode* tail){
	if(head==NULL){
		cout<<"Already Empty"<<endl;
		return;
	}
	head=head->next;
	if(head==NULL){
		tail=NULL;
	}
}
bool empty(qnode* head){
	if(head==NULL){
		return true;
	}
	return false;
}
int size(qnode* head){
	int count=0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
int front(qnode* head){
	if(head==NULL){
		cout<<"NO Element is Present"<<endl;
	}
	return head->data;
}
int back(qnode* tail){
	return tail->data;
}
void display(qnode* head){
	
	while(head!=NULL){
		cout<<head->data<<" ,";
		head=head->next;
	}
	cout<<"END"<<endl;
}
int main(){
	
	qnode* head=NULL;
	qnode* tail=NULL;
		cout<<"CHOOSE FROM THE GIVEN MENU"<<endl;
		cout<<"1. ENQUEUE"<<endl;
		cout<<"2. DEQUEUE"<<endl;
		cout<<"3. IS EMPTY"<<endl;
		cout<<"4. SIZE"<<endl;
		cout<<"5. FRONT ELEMENT"<<endl;
		cout<<"6. BACK ELEMENT"<<endl;
		cout<<"7. DISPLAY"<<endl;
		cout<<"8. QUIT"<<endl;
		int n,s;
	do{	
	cin>>n;
		switch(n){
		
			case 1:
				cout<<"Please enter the Number"<<endl;
				cin>>s;	
				push(head,tail,s);
				break;
			case 2:
				pop(head,tail);
				cout<<"Successfully Removed"<<endl;
				break;
			case 3:
				cout<<"Queue is Empty or Not"<<endl;
				if(empty(head)){
					cout<<"TRUE"<<endl;
				}else{
					cout<<"False"<<endl;
				}
				break;
			case 4:
				cout<<"size is : "<<size(head)<<endl;
				break;
			case 5:
				cout<<"Front Element is : "<<front(head)<<endl;
				break;
			case 6:
				cout<<"Back Element is : "<<back(tail)<<endl;
				break;
			case 7:
				cout<<"-------------------------------------"<<endl;
				display(head);
				cout<<"-------------------------------------"<<endl;
				break;
			case 8:
				break;
			default:
				cout<<"------------------WRONG MENU INPUT-------------"<<endl;
		}
	}while(n!=8);
return 0;
}
