//============================================================================
// Name        : assignment8_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdlib.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class linked_list
{
	Node* head;
	Node* last;
public:
	linked_list(){
		head=last=NULL;
	}
	void add(int x)
	{
		Node* new_node=new Node;

		new_node->data=x;
		new_node->next=NULL;
		if(head==NULL){
			head=new_node;
			last=new_node;
			return;
		}
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=new_node;
		return;
	}

	int len()
	{
		Node* n=head;
		int len=0;
		while(n!=NULL)
		{
			len++;
			n=n->next;
		}
		return len;
	}

	bool exist(int x)
	{
		Node* n=head;
		while(n!=NULL && n->data!=x)
		{
			n=n->next;
		}
		if(n==NULL){
			return false;
		}
		return true;
	}

    int data(){
    		return head->data;
    	}
    void next(){
    		head=head->next;
    	}

	void display()
	{
		Node* n=head;
		while(n!=NULL)
		{
			cout<<n->data<<" ";
			n=n->next;
		}
	}
};
class set
{
public:
	linked_list l3;
	void union_(linked_list l1,linked_list l2)
	{
		int n,n2;
		bool flag=true;
		linked_list temp1=l1;
		linked_list temp2=l2;

		n=l1.len();
		for(int j=0;j<n;j++)
		{
			l3.add(temp1.data());
			temp1.next();
		}
		n2=l2.len();
		for(int i=0; i<n2; i++){
				if(l3.exist(temp2.data())==true){
					flag = false;
				}
				else{
					flag = true;
				}
			if(flag==true){
				l3.add(temp2.data());
			}
			temp2.next();
		}
	}
	void intersection(linked_list l1, linked_list l2)
	{
	    int n1;
		n1=l1.len();
		linked_list temp=l1;
		for(int i=0; i<n1; i++)
		{
			if(l2.exist(temp.data())==true)
			{
				l3.add(temp.data());
			}
			temp.next();
		}
	}

	void difference(linked_list l1, linked_list l2)
	{
		 int n;
		 n=l1.len();
		 linked_list temp = l1;
		 for(int i=0; i<n; i++)
		 {
			 if(l2.exist(temp.data())==false)
			 {
				 l3.add(temp.data());
			 }
			 temp.next();
		 }
	}
	linked_list result(){
		return(l3);
	}
	void show()
	{
		l3.display();
	}

};
int main()
{
	int n,v,b,x,y;
	cout<<"Total no. of students : ";
	cin>>n;
	linked_list l,l1,l2;
	for(int i=1; i<=n; i++)
	{
		l.add(i);
	}
	cout<<"\nNo. of students who like vanilla: ";
	cin>>v;
	cout<<"\nRoll no. Students who like vanilla :";
	for(int i=1; i<=v; i++)
		{
		    cin>>x;
			l1.add(x);
		}
	cout<<"\nNo. of students who like Butterscotch: ";
	cin>>b;
    cout<<"\nRoll no. Students who like Butterscotch:";
	for(int i=1; i<=b; i++)
	{
		cin>>y;
		l2.add(y);
	}
	int ch;
	do
	{
		cout<<"\n1.Set of students who like both vanilla & butterscotch."<<endl;
		cout<<"2.Set of students who like either vanilla or butterscotch but not both"<<endl;
		cout<<"3.No. of students who like neither vanilla nor butterscotch"<<endl;
		cout<<"0.Press 0 to exit"<<endl;
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:{
			set U;
			U.intersection(l1,l2);
			U.show();
			break;
		}
		case 2:{
			set I,D;
			linked_list l3;
			I.intersection(l1,l2);
			l3=I.result();
			D.difference(l,l3);
            D.show();
            break;
		}
		case 3:{
			set u,D;
			linked_list l3,l4;
			u.union_(l1,l2);
			l3=u.result();
			D.difference(l,l3);
			l4=D.result();
			cout<<l4.len()<<endl;
			break;
		}
		case 0:{
			cout<<"\n!!! Exit !!!";
			break;
		}
		}

	}while(ch!=0);
	return 0;
}
