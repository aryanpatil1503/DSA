//============================================================================
// Name        : assignment7_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node{
public:
char status;
int seatno;
int rowno;
Node* prev;
Node* next;


};

class DCLL{												//for theatre

Node * head[10],*tail[10];
public:
DCLL(){


	for (int j=1;j<=10;j++)
	{
	head[j]=tail[j]=NULL;
	Node *new_node;

	for(int i=1;i<=7;i++)
   {
    new_node=  new Node();
    new_node->prev=new_node->next=NULL;
    new_node->rowno=j;
    new_node->seatno=i;
    new_node->status='-';
    if(head[j]== NULL)
      {
        head[j] = new_node;tail[j]=new_node;
        head[j]->next=head[j];
        head[j]->prev=head[j];
      }
    else
    	{
    	tail[j]->next=new_node;
    	new_node->prev=tail[j];
    	new_node->next=head[j];
    	head[j]->prev=new_node;
    	tail[j]=new_node;
    	}

      }

    }

}
void print();
void book(int,int);
void cancel();
};
void DCLL::book(int y,int x){


	Node* temp=head[x];
	for(int i=1;i<=7;i++){
		if(temp->seatno==y){
			if(temp->status=='-'){
				temp->status='B';
			}
			else {
				cout<<"Sorry. Already booked";
		}
	}
		temp=temp->next;
}

}

void DCLL::cancel(){
	int y;int x;

	cout<<"\n Enter row no of seat to cancel";
	cin>>x;
	cout<<"\n Enter column no of seat to cancel";
	cin>>y;

	Node* temp=head[x];
	for(int i=1;i<=7;i++){
		if(temp->seatno==y){
			if(temp->status=='B'){
				temp->status='-';
			}
			else {
				cout<<"Cannot cancel seats are not booked!!"<<endl;
		}
	}
		temp=temp->next;

}

}

void DCLL::print(){

	Node* temp;
	for (int j=1;j<=10;j++)
	{
	    temp=head[j];
	    for (int i=1;i<=7;i++){
	        while(temp->next != head[j]) {
	        cout<<j<<temp->seatno<<" "<<temp->status<<" ";
		    temp=temp->next;  }

 	  } cout<<j<<temp->seatno<<" "<<temp->status<<"  ";
	    cout<<endl;

   }
}





int main(){
int n,m,c;
DCLL ll ;

ll.book(1,1);
ll.book(5,2);
ll.book(3,5);
ll.book(4,2);
ll.book(5,3);

while (1){
	cout<<"1.Print seats.\n2.Book seats\n3.Cancel seats\n4.Stop."<<endl;
	cout<<"Enter choice";
	cin>>c;
switch (c){
case 1:
	ll.print();
	break;
case 2:
	cout<<"Number of seats to be booked "<<endl;
	cin>>n;
	int y;int x;
	cout<<"Enter row number "<<endl;
	cin>>x;
	cout<<"from seat  number"<<endl;
		cin>>y;

	for (int i=0;i<n;i++){

		if(y+i>7){
			ll.book(y+i-7,x+1);
			}
		else{
			ll.book(y+i,x);
		}

	}
	cout<<"Seats are booked!";
	cout<<endl;
	break;
case 3:
	cout<<"HOW MANY SEAT DO YOU WANT TO CANCEL?"<<endl;
	cin>>m;
	for (int i=0;i<m;i++){
	ll.cancel();}
	cout<<"Seats canceled!!!";
	cout<<endl;
	break;
case 4:

	exit(0);
}
}

return 0;
}
