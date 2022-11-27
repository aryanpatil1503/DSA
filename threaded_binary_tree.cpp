//============================================================================
// Name        : threaded_binary_tree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node{
	int data;
	Node* lchild;
	Node* rchild;
	int lbit,rbit;
public:
	Node(){
		data=0;
		lchild=NULL;
		rchild=NULL;
		lbit=0;
		rbit=0;
	}
	Node(int d){
		this->data=d;
		lchild=rchild=NULL;
		lbit=rbit=0;
	}
	friend class TBST;
};

class TBST{
	Node* root;
	Node* header;
public:
	TBST(){
		root=NULL;
		header=NULL;

	}
	void insert(int);
	void inorder();
	void preorder();
	void search(int,Node*& ,Node*&);
	void delete_element(int);
	Node* get_root(){
		return root;
	}
};

void TBST::insert(int d){
	if(root==NULL){
		header=new Node(-99);
		header->rchild=header;
		root=new Node(d);
		root->lchild=header;
		root->rchild=header;
		header->lchild=root;
		header->lbit=1;


	}
	else{
		Node* ptr;
		ptr=root;
		Node* temp=new Node(d);
		while(1){
			if(ptr->data>d){
			if(ptr->lbit!=0){
				ptr=ptr->lchild;
			}
			else{
				temp->lchild=ptr->lchild;
				temp->rchild=ptr;
				ptr->lbit=1;
				ptr->lchild=temp;
				return;
			}
			}
			if(ptr->data<d){
				if(ptr->rbit!=0){
					ptr=ptr->rchild;
				}
				else{
					temp->lchild=ptr;
					temp->rchild=ptr->rchild;
					ptr->rchild=temp;
					ptr->rbit=1;
					return;
				}
			}

		}
	}
};
void TBST:: inorder(){
	Node* t=root;
	while(t->lbit!=0){
		t=t->lchild;
	}
	while(t!=header){
		cout<<t->data<<" ";
		if(t->rbit!=0){
			t=t->rchild;
			while(t->lbit!=0){
				t=t->lchild;
			}
			}
		else{
			t=t->rchild;

		}
	}
};
void TBST:: preorder(){
	Node* t=root;
	int flag =0;

	while(t!=header){
		if (flag==0){
		cout<<t->data<<" ";
		}
		if(t->lbit==1 && flag==0){
			t=t->lchild;
		}
		else{
			if(t->rbit==1){

			flag=0;
			}
			else{
				flag=1;
			}
			t=t->rchild;
		}
	}


};

void TBST::search(int num,Node*& loc,Node*& par){
	loc=par=NULL;
	if(!root){
		return;
	}
	Node* temp=root;
	while(temp->lbit!=0 || temp->rbit!=0){
		if(temp->data==num){
			loc=temp;
			break;
		}
		else if(temp->data>num){
			par=temp;
			temp=temp->lchild;
			loc=temp;
		}
		else{
			par=temp;
			temp=temp->rchild;
			loc=temp;
		}
	}
};

void TBST::delete_element(int d){

	Node* par=NULL;
	Node* loc=NULL;
	search(d,loc,par);

	if(loc->lbit==0 && loc->rbit==0){
		if(par->lchild==loc){
			par->lchild=loc->lchild;
			par->lbit=0;
		}
		else{
			par->rchild=loc->rchild;
			par->rbit=0;
		}
		delete loc;
	}
	else if(loc->lbit==1 && loc->rbit==0){
		Node* child = loc->lchild;
		if(par->lchild==loc){
				par->lchild=child;
		}
		else{
				par->rchild=child;
		}
		while(child->rbit==1){
			child=child->rchild;
		}
		child->rchild=loc->rchild;
		delete(loc);
	}
	else if(loc->rbit==1 && loc->lbit==0){
			Node* child = loc->rchild;
			if(par->lchild==loc){
					par->lchild=child;
			}
			else{
					par->rchild=child;
			}
			while(child->lbit==1){
				child=child->lchild;
			}
			child->lchild=loc->lchild;
			delete(loc);
		}
	else if(loc->lbit==1 && loc->rbit==1){
		Node* temp = loc->rchild;
		while(temp->lbit==1){

			temp=temp->lchild;
		}
		int d=temp->data;
		delete_element(temp->data);
		loc->data=d;
	}
}



int main() {
	TBST t;
	int c;
	while(true){
		cout<<"\n\n Menu \n1. insert element \n2. inorder traversal \n3. preorder traversal \n4. delete elemnt \n5.exit"<<endl;
		cin>>c;
		switch(c){
		case 1:
			int a;
			cout<<"Enter data to be inserted: "<<endl;
			cin>>a;
			t.insert(a);
			break;
		case 2:
			cout<<"\n Following is inorder traversal: "<<endl;
			t.inorder();
			break;
		case 3:
			cout<<"\n Following is preorder traversal: "<<endl;
			t.preorder();
			break;
		case 4:
			int b;
			cout<<"\n Enter element to be deleted"<<endl;
			cin>>b;
			t.delete_element(b);

			break;
		case 5:
			exit(0);



		}
	}


	return 0;
}
