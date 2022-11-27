//============================================================================
// Name        : binarytree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
const int n=10;

class Node{
	int data;
	Node* lchild;
	Node* rchild;
public:
	Node(){
		data=0;
		lchild=NULL;
		rchild=NULL;
	}
	Node(int d){
		data=d;
		lchild=NULL;
		rchild=NULL;
		}
	friend class Binarytree;
	friend class Queue;
	friend class Stack;
};

class Queue{
	Node* queue[n];
	int rear,front,size;
public:
	Queue(){
		rear=-1;
		front=-1;
		size=0;
	};
	bool isfull(){
		return(rear==n-1);
	};
	bool isempty(){
		if(front==-1||front==rear+1){
			return true;
		};
		return false;


		};

	void push(Node* d){
		if(isfull()){
			cout<<"Queue is full"<<endl;
		}
		if(front==-1){
			front=0;
		}
		rear++;
		queue[rear]=d;
		size++;

	};
	Node* pop(){
		Node* a=NULL;
		if(front==-1 && rear==-1){
			cout<<"queue is empty"<<endl;
		}
		else if(front==rear){
			a=queue[front];
			front=rear=-1;
		}
		else{
			front++;
			a=queue[front];
			size--;
		}
		return a;

	}
	int size_of(){
		return(rear-front+1);
	}


};

class Stack{
	Node* stack[n];
	int top;
public:
	Stack(){
		top=-1;
	}
	void push(Node* x){
		if(isfull()){
			cout<<"\nStack overflow";
			}
		else{
			top=top+1;
			stack[top]=x;
		}
	}
	Node* pop(){
		if(isempty()){
			cout<<"\nStack Underflow";
		}
		else{
			Node* x=stack[top--];
			return x;
		}
	}
	bool isempty(){
		return(top<0);
	}
	bool isfull(){
		return(top>=n-1);
	}
};

class Binarytree{
	Node* root;
public:
	Binarytree(){
		root=NULL;
	}
	Node* getroot(){
				return root;
			}
	void create(){
		Queue q;
		Node*parent,*left,*right;
		int data,ldata,rdata,c1,c2;
		cout<<"Enter value of root"<<endl;
		cin>>data;
		Node* temp=new Node(data);
		if(root==NULL){
			root=temp;
			q.push(root);
		}
		while(!q.isempty()){
			parent=q.pop();
			cout<<"enter 1 if u want to enter left child of "<<parent->data<<" or else enter 0"<<endl;
			cin>>c1;
			if(c1==1){
			cout<<"Enter data of left child of "<<parent->data<<endl;
			cin>>ldata;
			if (ldata!=-1){

				left=new Node(ldata);
				parent->lchild=left;
				q.push(left);}
			}
			cout<<"enter 1 if u want to enter right child "<<parent->data<<" or else enter 0"<<endl;
			cin>>c2;
			if(c2==1){
			cout<<"Enter data of right child of "<<parent->data<<endl;
				cin>>rdata;
				if (rdata!=-1){

					right=new Node(rdata);
					parent->rchild=right;
					q.push(right);
				}
				}
			}}
	void set_root(Node* t){
		root=t;
		if(root==NULL){
			cout<<"\n Tree is empty"<<endl;
		}
	}
	Node* create_rec(){
		Node* p;
		int d;
		cout<<"Enter data or -1 for no data"<<endl;
		cin>>d;
		if(d==-1){
			return NULL;
		}
		p=new Node(d);
		cout<<"Enter left child data"<<endl;
		p->lchild=create_rec();
		cout<<"Enter right child data"<<endl;
		p->rchild=create_rec();
		return p;
	}

	void inorder(Node* temp){

		if(temp!=NULL){

			inorder(temp->lchild);
			cout<<temp->data<<" ";
			inorder(temp->rchild);
		}
	}
	void inorder_iterative(){
		Stack s;
		Node* current=root;
		do{
			while(current!=NULL){
				s.push(current);
				current=current->lchild;
			}
			if(current==NULL && s.isempty()==false){
			current=s.pop();
			cout<<current->data<<" ";
			current=current->rchild;
		}}while(current!=NULL|| !s.isempty());
	}
	void preorder(Node* temp){
		if(temp!=NULL){
			cout<<temp->data<<" ";
			preorder(temp->lchild);
			preorder(temp->rchild);
		}
	}
	void preorder_iterative(){
		Stack s;
		Node* temp;
		s.push(root);
		while(!s.isempty()){
			temp=s.pop();
			cout<<temp->data<<" ";
			if(temp->rchild){
				s.push(temp->rchild);
			}
			if(temp->lchild){
				s.push(temp->lchild);
			}
		}
	}
	void postorder(Node* temp){
		if(temp!=NULL){
			postorder(temp->lchild);
			postorder(temp->rchild);
			cout<<temp->data<<" ";
		}
	}
	void postorder_iterative(){
		Stack s1,s2;
		s1.push(root);
		while(!s1.isempty()){
			Node* temp=s1.pop();
			s2.push(temp);
			if(temp->lchild){
				s1.push(temp->lchild);
			}
			if(temp->rchild){
				s1.push(temp->rchild);
			}
		}
		while(!s2.isempty()){
			Node* t=s2.pop();
			cout<<t->data<<" ";
		}
	}

	void levelwisetraversal(){
		Queue q;
		Node* temp;
		if(!root){
			return;
		}
		q.push(root);
		while(!q.isempty()){
			temp=q.pop();
			cout<<temp->data<<" ";
			if(temp->lchild){
				q.push(temp->lchild);
			}
			if(temp->rchild){
				q.push(temp->rchild);
			}
		}
	}

	int giveHight(){

		Queue q;
		int height = 0,node_count;

		if(!root) return -1;

		q.push(root);
		while(!q.isempty())
		{

			node_count = q.size_of();
			if(node_count == 0)
			{
				return height;
					}
			else
			{
				height++;
			}
			while(node_count>0)
			{
				Node* temp = q.pop();

				if(temp->lchild) q.push(temp->lchild);
				if(temp->rchild) q.push(temp->rchild);
				node_count--;
					}
				}

		return height;
		}
	int max(int a,int b){
		if(a>=b){
			return a;
		}
		else{
			return b;
		}
	}
	int height_rec(Node* temp){
		if(temp==NULL){
			return 0;
		}
		else{
			return(1+max(height_rec(temp->lchild),height_rec(temp->rchild)));
		}
	}
	void mirror(Node* temp){
		Node* temp1;
		temp1=temp->lchild;
		temp->lchild=temp->rchild;
		temp->rchild=temp1;
		if(temp->lchild) mirror(temp->lchild);
		if(temp->rchild) mirror(temp->rchild);
	}

	int num_leafnodes(Node* temp){

		if(temp==NULL){
			return 0;
		}
		else if(temp->lchild==NULL && temp->rchild==NULL){
			return 1;
		}
		else{
			return num_leafnodes(temp->lchild)+num_leafnodes(temp->rchild);
		}
	}

	int num_internalnodes(Node* temp){
		if(temp==NULL){
			return 0;
		}
		else if(temp->lchild || temp->rchild){
			return 1;
		}
		else{
			return num_internalnodes(temp->lchild)+num_internalnodes(temp->rchild);
		}
	}

	void operator =(Binarytree& t){
		root=copytree(t.root);
	}

	Node* copytree(Node *t1){
		Node* temp=NULL;
		if(t1){
			temp=new Node(t1->data);
			temp->lchild=copytree(t1->lchild);
			temp->rchild=copytree(t1->rchild);

		}
		return temp;
	}

	void deletenode(Node*temp){
		if(temp!=NULL){
			deletenode(temp->lchild);
			deletenode(temp->rchild);
			delete temp;
		}
	}




};

int main(){
	Binarytree b;
	int c1,c2,c3;
	while(true){
		cout<<"MENU \n1. create \n2. traverse \n3. height \n4. mirror\n5. number of leaf nodes\n6. number of internal nodes\n7. copy tree\n8. delete \n9. end";
		cin>>c1;
		switch(c1){
		case 1:
			cout<<"\n1.non recursive \n2. recursive ";
			cin>>c2;
			switch(c2){
			case 1:
				b.create();

				break;
			case 2:
				Node *temp=b.create_rec();
				b.set_root(temp);
				break;
			}
			break;
		case 2:
			cout<<"\n1. inorder \n2. preorder \n3. postorder \n4. inorder_iterative \n5. preorder_iterative \n6. postorder_iterative  \n7. levelwise";
			cin>>c3;
			switch(c3){
			case 1:
				b.inorder(b.getroot());
				cout<<endl;
				break;
			case 2:
				b.preorder(b.getroot());
				cout<<endl;
				break;
			case 3:
				b.postorder(b.getroot());
				cout<<endl;
				break;
			case 4:
				b.inorder_iterative();
				cout<<endl;
				break;
			case 5:
				b.preorder_iterative();
				cout<<endl;
				break;
			case 6:
				b.postorder_iterative();
				cout<<endl;
				break;
			case 7:
				b.levelwisetraversal();
				cout<<endl;
				break;
			}
			break;
		case 3:
			int c4;
			cout<<"\n 1. recursive \n 2. non recursive";
			cin>>c4;
			if(c4==2){
				cout<<b.giveHight()<<endl;}
			else if(c4==1){
				cout<<b.height_rec(b.getroot());
			}
			break;
		case 4:
			b.mirror(b.getroot());
			b.inorder(b.getroot());
			cout<<endl;
			break;
		case 5:
			cout<<b.num_leafnodes(b.getroot())<<endl;;
			break;
		case 6:
			cout<<b.num_internalnodes(b.getroot())<<endl;
			break;
		case 9:
			exit(0);
		case 8:
			b.deletenode(b.getroot());
			b.set_root(NULL);
			break;
		case 7:
			Binarytree t;
			t=b;
			t.inorder_iterative();
			break;



		}

	}





	return 0;
}
