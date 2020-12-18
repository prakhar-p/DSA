#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
class Stack {
public:
	char a[MAX];
	int top;
	Stack() { 
		top = -1;
    }
	void push(char x);
	void pop();
	char peek();
};

void Stack::push(char x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
	}
	else {
		a[++top] = x;
	}
}
void Stack::pop(){
	if (top < 0) {
		cout << "Stack Underflow";
	}
	else {
		 a[top]=0;
		 top--;
	}
}
char Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return '0';
	}
	else {
		char x = a[top];
		return x;
	}
}

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

string infixTOpostfix(Stack s,string infix){
	s.push('N');
	string postfix;
	for(int i=0;i<infix.length();i++){
		if((infix[i]>='A' and infix[i]<='Z') or (infix[i]>='a' and infix[i]<='z')){
			postfix+=infix[i];
		}else if(infix[i]=='('){
			s.push(infix[i]);
		}else if(infix[i]==')'){
			while((s.peek()!='(') and (s.peek()!='N')){
				char temp=s.peek();
				postfix+=temp;
				s.pop();
			}
			if(s.peek()=='('){
				s.pop();
			}
		}else{
			while(s.peek() != 'N' && pre(infix[i]) <= 
				pre(s.peek())) 
			{ 
				char c = s.peek(); 
				s.pop(); 
				postfix+= c; 
			} 
			s.push(infix[i]);
		}
	}
	while(s.peek()!='N'){
		postfix+=s.peek();
		s.pop();
	}
	return postfix;
}
int main(){
	string infix,postfix;
	cout<<"Enter the infix Expression"<<endl;
	cin>>infix;
	Stack s;
	postfix=infixTOpostfix(s,infix);
	cout<<"The output Expression is:"<<endl<<postfix<<endl;
//	cout<<endl<< "DONE BY PRAKHAR (196032)";
	return 0;
}
