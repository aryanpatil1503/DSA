//============================================================================
// Name        : hashtable_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class WordNode{
	string key,meaning;
	WordNode *next;
public:
	WordNode(){
		key=" ";
		meaning=" ";
		next=NULL;
	}
	WordNode(string k, string m){
		this->key=k;
		this->meaning=m;
		this->next=NULL;
	}
	friend class HashTable;
};

class HashTable{
	WordNode *ht[26];
public:
	HashTable(){
		for(int i=0;i<26;i++){
			ht[i]=NULL;
		}
	}
	int hashfunc(string);
	void  insert(string,string);
	void display();
	void search(string);
	void delete_word(string);

};

int HashTable::hashfunc(string key){
	int val=0;
	for(long unsigned int i=0;i<key.size();i++){
   	val+=(int(key[i])-key.size());
	}
	val=val%23;

/*	if(int(key[0])>=65 && int(key[0])<=90){
		 val=(26*(int(key[0])-65)/25);
	}
	else if(int(key[0])>=97 && int(key[0])<=122){
		 val=(26*(int(key[0])-97)/25);
	}*/

	return val;

};

void HashTable ::insert(string k,string m){
	int i=hashfunc(k);

	if( ht[i]==NULL){
		WordNode* temp= new WordNode(k,m);
		ht[i]=temp;
	}
	else{
		WordNode* ptr=ht[i];
		while(ptr->next!=NULL){
			if(ptr->key==k){
					break;
			}
			ptr=ptr->next;
		}
		if(ptr->key==k){
			cout<<"\n Word Already Present"<<endl;
		}
		else{
			WordNode* temp= new WordNode(k,m);
			ptr->next=temp;
		}
	}
};


void HashTable::display(){
	for(int i=0;i<26;i++){
		if(ht[i]!=NULL){
		WordNode *t=ht[i];

		while(t){
			cout<<t->key<<" : "<<t->meaning<<"  ";
			t=t->next;

		}
		cout<<endl;
		}
	}
};

void HashTable::search(string k){
	int index=hashfunc(k);

	WordNode* t=ht[index];
	while(t!=NULL &&t->key!=k){
		t=t->next;

	}
	if(t==NULL){
		cout<<"Word not present"<<endl;
	}
	else{
		cout<<"Meaning of word entered is:"<<t->meaning<<endl;
	}
};
void HashTable ::delete_word(string k){
	int index=hashfunc(k);
	WordNode* t=ht[index];
	if(t->key==k && t!=NULL){
		ht[index]=t->next;
		delete t;
		return;
	}
	WordNode* prev;
	while(t!=NULL && t->key!=k){
		prev=t;
		t=t->next;
	}
	if(t==NULL){
		cout<<"Word not present in dictionary"<<endl;
		return;
	}
	prev->next=t->next;
	delete t;

}



int main() {
	HashTable h;
	string k,m;
	int c;
	while(true){
		cout<<"\n\tMENU:\n1.insert word to dictionary\n2.search word\n3.delete word\n4.display\n5.exit "<<endl;
		cin>>c;
		switch(c){
		case 1:

			cout<<"Enter word to be added"<<endl;
			cin>>k;
			cout<<"enter its meaning"<<endl;
			cin>>m;
			h.insert(k,m);
			break;

		case 2:

			cout<<"Enter word to be searched:"<<endl;
			cin>>k;
			h.search(k);
			break;

		case 3:

			cout<<"Enter word to be deleted:"<<endl;
			cin>>k;
			h.delete_word(k);
			break;
		case 4:
			h.display();
			break;
		case 5:
			exit(0);
		}

	}
	/*h.insert("ant", "insect");
	h.insert("dog","animal");
	h.insert("apple","fruit");
	h.insert("Age","number");
	//h.insert("dog","animal");
	string g=h.search("apple");
	cout<<g<<endl;

	h.display();*/
	return 0;

}
