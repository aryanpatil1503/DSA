//============================================================================
// Name        : assignment11_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node * next ;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class Queue{
    public:
    Node *front, *rear;
    Queue(){
        front = NULL;
        rear = NULL;
    }
    void add(int d){
        Node *toAdd = new Node(d);

        if(front == NULL){
            front = toAdd;
            rear = toAdd;
        }else{
            rear->next = toAdd;
            rear = rear->next;
        }

    }
    int size(){
        Node *temp = front;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;

        }
        return count;
    }

    void remove(){
        if(front == NULL){
            cout<<"There are no elements in the queue.";
            return;
        }
        else if(front->next == NULL){
            front = NULL;
            rear = NULL;
            return;
        }
        front = front->next;
    }

    void print(){
        Node * temp = front;

        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q = Queue();
    bool conti = true;
    int queueSize;
    cout<<"Enter queue size: ";
    cin>>queueSize;
    cout<<endl;
    while(conti){
        cout<<"Enter 1 to add jobs."<<endl;
        cout<<"Enter 2 to delete jobs."<<endl;
        cout<<"Enter 3 to display."<<endl;
        cout<<"Enter 4 to exit."<<endl;

        int n ;
        cout<<"Enter: ";
        cin>>n;
        cout<<endl;


        if(n == 1){
            int size;
            cout<<"Enter number of jobs you wish to add: ";
            cin>>size;
            cout<<endl;
            for(int i=0;i<size;i++){

                if(q.size() < queueSize){
                    int a;
                    cout<<"Enter job value to add: ";
                    cin>>a;
                    cout<<endl;
                    q.add(a);
                }
                else{
                    cout<<"Queue is full!!"<<endl;
                    break;
                }

            }
        }

        else if(n == 2){
            q.remove();
        }

        else if(n==3){
            q.print();
        }

        else if (n==4){
            conti = false;
        }

        else{
            cout<<"Please enter correct input!"<<endl;
        }

    }
    return 0;
}
