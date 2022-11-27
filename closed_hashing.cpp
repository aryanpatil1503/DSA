//============================================================================
// Name        : closed_hashing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

# define SIZE 10

class Entry
{
	long long int telno;
	string name;
public:
	Entry(){
		telno=-1;
		name=" ";
	}
	Entry(long long int t,string n){
		telno=t;
		name=n;
	}
	friend class HashTable;
};

class HashTable{
	Entry ht[SIZE];
public:
	int hashfunc(long long int);
	void insert_without_replacement(long long int ,string);
	void insert_with_replacement(long long int ,string);
	void display();
	int search(long long int);
	void delete_entry(long long int);
};

int HashTable::hashfunc(long long int key){
	int index=0;
	int temp=0;
	while(key>0){
		temp=key%100;
		index+=(temp%13);
		key=key/100;

	}
    index=index%SIZE;
	//index=key%10;

	return index;
};

void HashTable:: insert_without_replacement(long long int key, string value){
	int i=hashfunc(key);
	int index=i;
	if(ht[index].telno==-1){
		ht[index].telno=key;
		ht[index].name=value;
		}
	else{

		while(ht[index].telno!=-1 ){
			if(ht[index].telno==key){
				cout<<"\n\t Number :"<<ht[index].telno<<" already present.";
				return;
			}
			index=(index+1)%SIZE;
			if(index==i){
				cout<<"\n\t Hash Table full.";
				return;

			}
			}
		ht[index].telno=key;
		ht[index].name=value;

		}
}

void HashTable::display(){
	cout<<"\n\t SR NO.\t NAME \t TELEPHONE NUMBER";
	for(int i=0;i<SIZE;i++){
		if(ht[i].telno!=-1){
		cout<<"\n\t"<<i<<"\t"<<ht[i].name<<" \t "<<ht[i].telno;
		}
	};
}

int HashTable ::search(long long int key){
	int i=hashfunc(key);
	int count=0;
	if(ht[i].telno==key){
		cout<<"\n Number found after "<<count<<" collisions.";
		cout<<"\n SR NO.\t"<<i;
		cout<<"\n NAME \t"<<ht[i].name;
		cout<<"\n TELEPHONE NUMBER \t"<<ht[i].telno;
		return 1;

	}
	else{
		int n=i+1;
		while(n!=i-1 && ht[n].telno!=key){
			n=(n+1)%SIZE;
			count++;
		}
		if(ht[i].telno==key){
			cout<<"\n Number found after "<<count<<" collisions.";
			cout<<"\n SR NO.\t"<<i;
			cout<<"\n NAME \t"<<ht[i].name;
			cout<<"\n TELEPHONE NUMBER \t"<<ht[i].telno;
			return 1;

		}
		else{
			return -1;
		}

		}
	return -1;
}

void HashTable:: insert_with_replacement(long long int key, string value){
	int i=hashfunc(key);
	int index=i;
	if(ht[i].telno!=-1 && hashfunc(ht[i].telno)!=i){
		long long int k=key;
		string n=value;
		key=ht[i].telno;
		value=ht[i].name;
		ht[i].telno=k;
		ht[i].name=n;
		i=hashfunc(key);
		index=i;
	}

	while(ht[i].telno!=-1){
		if(ht[i].telno==key){
			cout<<"\n Number :"<<ht[i].telno<<" already present.";
			return;
		}
		i=(i+1)%SIZE;
		if(index==i){
			cout<<"\n\t Hash Table is full";
			return;
		}
	}
	ht[i].telno=key;
	ht[i].name=value;

}

void HashTable ::delete_entry(long long int key){
	int idx =hashfunc(key);
	if(ht[idx].telno==key){
		int i=idx;
		i++;
		while(hashfunc(ht[i].telno)!=idx && i!=idx){
			i=(i+1)%SIZE;
		}
		if(hashfunc(ht[i].telno)==idx && i!=idx){
			ht[idx]=ht[i];
			ht[i].name="";
			ht[i].telno=-1;
		}
		else{
			ht[idx].name="";
			ht[idx].telno=-1;
		}
	}
	else{
		int i=idx;
		i++;
		while(ht[i].telno!=key && i!=idx){
			i=(i+1)%SIZE;
		}
		if(ht[i].telno==key ){
			ht[i].name="";
			ht[i].telno=-1;
		}
		else{
			cout<<"Number not present";
		}

	}

}

int main() {
	HashTable t;
	int c;
	long long int tel;
	string name;
	while(true){
		cout<<"\n\t MENU: \n1.Insert entry \n2. Display Telephone book \n3. Search entry \n4. Delete entry \n5. Exit";
		cin>>c;
		switch(c){
		case 1:
			int ch;
			cout<<"\n1. without replacement\n2. with replacement"<<endl;
			cin>>ch;
			if(ch==1){
			cout<<"enter name of client"<<endl;
			cin>>name;
			cout<<"Enter telephone number"<<endl;
			cin>>tel;
			t.insert_without_replacement(tel,name);

			}
			else{
				cout<<"enter name of client"<<endl;
				cin>>name;
   			    cout<<"Enter telephone number"<<endl;
				cin>>tel;
				t.insert_with_replacement(tel, name);


			}
			break;
		case 2:
			t.display();
			break;
		case 3:
			cout<<"Enter telephone number to be searched:"<<endl;
			cin>>tel;
			if(t.search(tel)==-1){
				cout<<"Entry is not present."<<endl;
			}
			break;
		case 4:
			cout<<"Enter telephone number to be deleted:"<<endl;
			cin>>tel;
			t.delete_entry(tel);
			break;
		case 5:
			exit(0);

		}
	}

	return 0;
}
