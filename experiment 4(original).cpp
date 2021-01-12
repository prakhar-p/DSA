/*#include<bits/stdc++.h>
using namespace std;
class snode{
	public:
	
		char data;
		snode* next;
	snode(char d){
		data=d;
		next=NULL;
	}
};
void push(snode* &head,snode* &tail,char d){
	snode* n=new snode(d);
	if(head==NULL){
		head=tail=n;
	}else{
		tail->next=n;
		tail=n;
	}
}




void pop(snode* &head,snode* &tail){
	if(head==NULL){
		cout<<"Stack is empty"<<endl;
	}
    else if(head == tail){
        delete tail;    //
        head = tail = NULL; //
    }
    else{
		snode* temp=head;
		while(temp!=tail){
			if(temp->next==tail){
				snode *t = tail; //
                tail=temp;
				temp->next=	NULL;
                delete t;   //
				break;
			}
			temp=temp->next;
		}
	}
}
int peek(snode* tail){
	if(tail==NULL){
		cout<<"NO Element is Present"<<endl;
		return -1;
	}
	return tail->data;
}


void display(snode* head){
	if(head==NULL){
		cout<<"No Element To Show"<<endl;
	}else{
		while(head){
			cout<<head->data<<" ";
			head=head->next;
		}
		cout<<endl;
	}
}

/*
int pre(char c){
	if(c=='^'){
		return 3;
	}else if(c=='*' or c=='/'){
		return 2;
	}else if(c=='+' or c=='-'){
		return 1;
	}else{
		return -1;
	}
}
*/
/*string infixTOpostfix(string infix){
	snode* head=NULL,*tail=NULL;
	push(head,tail,'N');
	string postfix;
	for(int i=0;i<infix.length();i++){
		if((infix[i]>='A' and infix[i]<='Z') or (infix[i]>='a' and infix[i]<='z')){
			postfix+=infix[i];
		}else if(infix[i]=='('){
			push(head,tail,infix[i]);
		}else if(infix[i]==')'){
			while((peek(tail)!='(') and (peek(tail)!='N')){
				char temp=peek(tail);
				postfix+=temp;
				pop(head,tail);
			}
			if(peek(tail)=='('){
				pop(head,tail);
			}
		}else{
			while(peek(tail) != 'N' && pre(infix[i]) <= 
				pre(peek(tail))) 
			{ 
				char c = peek(tail); 
				pop(head,tail); 
				postfix+= c; 
			} 
			push(head,tail,infix[i]);
		}
	}
	while(peek(tail)!='N'){
		postfix+=peek(tail);
		pop(head,tail);
	}
	return postfix;
}*/

/*
void infixTOpostfix(string infix){
	snode* head=NULL,*tail=NULL;
	for(int i=0;i<infix.length();i++){
		char ch=infix[i];
		if(ch>='0' and ch<='9'){
			push(head,tail,ch-'0');
		}else{
			int b=pop(head,tail);
			int a=pop(head,tail);
			int res;
			switch(ch){
				case '+':
					res=a+b;
					break;
				case '-':
					res=a-b;
					break;
				case '*':
					res=a*b;
					break;
				case '/':
					res=a/b;
					break;
				default:
					exit(0);
			}
			push(head,tail,res);
		}
	}
	int a=peek(tail);
	cout<<a;
}






int main(){
	
	string infix;
	cin>>infix;
	infixTOpostfix(infix);
	return 0;
}*/


#include<iostream>
#include<conio.h>
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

class stack{
	public:
		node* top;
		int h;
	stack(){
		top=NULL;
		h=0;
	}
	void push(int n){
		node* nn=new node(n);
		if(!top){
			top=nn;
		}else{
			nn->next=top;
			top=nn;
		}
		h++;
	}
	
	int pop(){
		if(h==0){
			cout<<"Stack is Empty"<<endl;
			return -1;
		}
		h--;
		int n=top->data;
		node* temp=top;
		top=top->next;
		delete temp;
		return n;
	}
	
	int size(){
		return h;
	}
	
	int peek(){
		return top->data;
	}
};
int main(){
	cout<<"ENTER THE EXPRESSION"<<endl;
	string postfix;
	cin>>postfix;
	stack* s=new stack();
	cout<<"ENTER THE EXPRESSION"<<endl;
		for(int i=0;i<postfix.length();i++){
		char ch=postfix[i];
		if(ch>='0' and ch<='9'){
			s->push(ch-'0');
		}else{
			int b=s->pop();
			int a=s->pop();
			int res;
			switch(ch){
				case '+':
					res=a+b;
					break;
				case '-':
					res=a-b;
					break;
				case '*':
					res=a*b;
					break;
				case '/':
					res=a/b;
					break;
				default:
					exit(0);
			}
			s->push(res);
		}
	}
	if(s->size()>1){
		cout<<"Wrong Expression\n";
	}else{
		cout<<"The Sol is :  "<<s->pop();
	}
	getch();
	return 0;
}
