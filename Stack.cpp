//============================================================================
// Name        : assignment9_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

class Node{
	public:
	char data;
	Node* next;
	Node(char d){
		data = d;
		next = NULL;
	}
};

class Stack{
	Node * head, *tail;
	public:
	Stack(){
		head = NULL;
		tail = NULL ;
	}

    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        return false;
    }

	void push(char n)
    {
        Node *tmp = new Node(n);

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void pop(){
        Node * temp = head;

        if(head!=NULL)
        {
        	if(temp->next ==NULL){
        	head=NULL;
        	return;
        	}
        	while(temp->next->next!=NULL){
        	temp=temp->next;
        	}
        	temp->next=NULL;
        }
        else{
        	cout<<"\n stack is empty";
        }
    }

	char top(){
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        char top = temp->data;
        return top;
    }


	void print(){
		Node* temp = head;
		while(temp != NULL) {
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

};

class Expression
{
    string exp1;
public:
    Expression()
    {
        exp1 = "";
    }

    Expression(string str)
    {
        exp1 = str;
    }


    void validateExpression()
    {
        Stack S;


        for(int i = 0; i < exp1.length(); i++)
        {
           if (exp1[i]=='(' || exp1[i]=='[' || exp1[i]=='{')
           {
        	   S.push(exp1[i]);
           }
           else if(exp1[i]==')')
           {
                    if(S.top() == '(')
                    {
                    	S.pop();
                    }

           }

           else if(exp1[i]==']')
           {
                    if(S.top() == '[')
                    {
                    	S.pop();
                    }


           }

           else if (exp1[i]=='}')
           {
                    if(S.top() == '{')
                    {
                    	 S.pop();

                    }


            }
        }
        if( S.isEmpty())
        {
            cout<<"Valid parenthesis"<<endl;
        }
        else
        {
            cout<<"Invalid parenthesis"<<endl;
        }
    }
};


int main(){
	char ch = 'y';
	    do
	    {
	        string str;
	        cout<<"Enter expression to be validated : ";
	        cin>>str;

	        Expression e(str);

	        e.validateExpression();

	        cout<<"\nDo you want to continue?(y/n) ";
	        cin>>ch;
	    } while(ch == 'y');
	return 0;
}
