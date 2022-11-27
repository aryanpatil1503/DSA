//============================================================================
// Name        : assignment12_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
# define size 10
template<class T>
class Item
{

public:
	T data;
	int priority;
	bool operator <=(Item itm){
			if(priority<=itm.priority){
				return true;
			}
			else{
				return false;
			}
		}

};
template<class T>
class PriorityQueue
{
private:
	Item<T>PQ[size];
	int front, rear;
public:
	PriorityQueue()
{
		front=-1;
		rear=-1;

}
	void add(T d,int p)
	{
		Item<T>itm;
		itm.data=d;
		itm.priority=p;
		if( rear==size-1)
		{
			cout<<"Queue is full"<<endl;


		}
		if (front==-1)
		{
			front=0;
			rear=0;
			PQ[rear]=itm;

		}
		else
		{
		rear+=1;
		int j=rear-1;
		while(PQ[j]<=itm && j>=front){
						PQ[j+1]=PQ[j];
						j-=1;
					}
					PQ[j+1]=itm;
				}
			}
	void display()
	{
		cout<<"\n Items in the Queue are as follows: \n "<<endl;
				for(int i=front;i<=rear;i++){
					cout<<PQ[i].data<<" ";
				}
				cout<<"\n";
			}

	void pop(){
			if(front==-1 || front==rear+1){
				cout<<"Queue is empty!\n";
			}
			else{
				PQ[front].priority=0;
				front=front+1;
			}
		}


};
int main(){
	int data_type;
	cout<<"Enter what type of data you want to use:\n ";
	cout<<"1.integer \n2.character \n3.float\n";
	cin>>data_type;

	PriorityQueue<int> pq1;
	PriorityQueue<char>pq2;
	PriorityQueue<float>pq3;

	bool flag=true;
	while(flag){

		cout<<" 1.Insert an item. \n2.Delete an item. \n3.Display Queue. \n 4.stop\n";
		int choice;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
		case 1:
			if(data_type==1){
				int d,p;
				cout<<"Enter data value: ";
				cin>>d;
				cout<<"Enter its priority: ";
				cin>>p;
				pq1.add(d,p);
			}
			else if(data_type==2){
				char d;
				int p;
				cout<<"Enter data value: ";
				cin>>d;
				cout<<"Enter its priority: ";
				cin>>p;
				pq2.add(d,p);
			}
			else if(data_type==3){
				float d;
				int p;
				cout<<"Enter data value: ";
				cin>>d;
				cout<<"Enter its priority: ";
				cin>>p;
				pq3.add(d,p);
			}
			break;
		case 2:
			if(data_type==1)
				pq1.pop();
			else if(data_type==2)
				pq2.pop();
			else if(data_type==3)
				pq3.pop();
			break;
		case 3:
			if(data_type==1)
				pq1.display();
			else if(data_type==2)
				pq2.display();
			else if(data_type==3)
				pq3.display();
			break;
		case 4:
			flag=false;
			break;
		default:
			cout<<"Enter valid choice\n";
		}
	}
	return 0;
}
