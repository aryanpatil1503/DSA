//============================================================================
// Name        : assignment10_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;

template <typename T>
class stack
{
	T arr[20];
	int index=-1;
public:
	void push(T x)
	{
		if (index > 20) {
		        cout << "\n Stack Overflow";
		    }
		    else {
		        arr[++index] = x;
		    }
	}
	void pop()
	{
		if(index<0){
			cout<<"\n Stack Underflow";
		}
		else{
			index--;
		}
	}
	int top()
	{
		if(index<0){

		    return 0;
		}
		else{
			int x= arr[index];
			return x;
		}
	}
	int isEmpty()
	{
		if(index<0){
			return true;
		}
		else{
			return false;
		}
	}
};

class check
{
	string str;
	char array[30];
	int size=0;
public:
	void accept()
	{
		cout<<"\nEnter a expression :";
		cin>>str;
	}

	bool isBalanced()
	{
		stack<char>S;
		char x;
		for (int i = 0; i < str.length(); i++)
		    {
		        if (str[i] == '(' || str[i] == '['
		            || str[i] == '{')
		        {
		            S.push(str[i]);

		        }
		        if ((str[i] == ')' || str[i] == ']'
		        	            || str[i] == '}')&& S.isEmpty()==true)
		        	        {
		        	            return false;
		        	        }
		        switch (str[i]) {
		        case ')':
		            x = S.top();
		            if (x == '{' || x == '[')
		                return false;
		            S.pop();
		            break;

		        case '}':
		            x = S.top();

		            if (x == '(' || x == '[')
		                return false;
		            S.pop();
		            break;

		        case ']':
		            x = S.top();

		            if (x == '(' || x == '{')
		                return false;
		            S.pop();
		            break;
		        }
		    }
		return (S.isEmpty());
	}

	void infix_to_postfix()
	{
		stack<char>S;
		char arr[20];								//to store the postfix expression
		int j=0;
		for(int i=0; i<str.length(); i++)
		{
	        if (str[i] == '(' || str[i] == '['
	            || str[i] == '{')
	        {
	            S.push(str[i]);
	        }
	        else if(str[i] == '+' || str[i] == '-')
	        {
	        	while(S.top()=='+'|| S.top() == '-'
    	            || S.top() == '*'|| S.top() == '/')
	        	{
	        		arr[j]=S.top();
	        		j++;
	        		S.pop();

        	    }
        	    S.push(str[i]);
	        }
	        else if(str[i] == '*' || str[i] == '/')
	        {
	        	while(S.top() == '*'|| S.top() == '/'){
	        		arr[j]=S.top();
	        			        		j++;
	        			        		S.pop();
	        	}
	        	S.push(str[i]);
	        }
	        else if (str[i] == ')' || str[i] == ']'
	        	            || str[i] == '}')
	        {

	        	while(S.top()=='+'|| S.top() == '-'
	        	    	            || S.top() == '*'|| S.top() == '/')
	        	{
	        		arr[j]=S.top();
	        		j++;
	        		S.pop();
	        	}
	        	S.pop();
	        }
	        else{
	        	arr[j]=str[i];
	        	j++;
	        }

		}
		if(S.isEmpty()==false)
		{
			arr[j]=S.top();
			j++;
			S.pop();
		}
		cout<<endl;
		for(int k=0; k<j; k++){
				cout<<arr[k];
				array[k]=arr[k];
				size++;
		}
	}

	void evaluate()
	{
		int x,z;
		z=size;
		stack<int>N;
		for(int i=0; i<z; i++)
		{
			if (isdigit(array[i]))
			{
				N.push((int)array[i]-'0');
			}
			else{
				int n=N.top();
				N.pop();
				int m=N.top();
				N.pop();
			switch(array[i]){
			case '+':{
				x=m+n;
				break;
			}
			case '-':{
							x=m-n;
							break;
						}
			case '*':{
							x=m*n;
							break;
						}
			case '/':{
							x=m/n;
							break;
						}
			}
			N.push(x);
			}

		}
		cout<<"\n"<<x<<endl;
	}
};

int main()
{
	check expr;
	int ch;
	do{
		cout<<"\n1.Enter expression.";
		cout<<"\n2.Infix to postfix.";
		cout<<"\n3.Evaluate";
		cout<<"\n0. End";
		cout<<"\nEnter key :";
		cin>>ch;
		switch(ch){
		case 1:{
			expr.accept();
			break;
		}
		case 2:{
			if(expr.isBalanced()){
			expr.infix_to_postfix();
			}
			else{
				cout<<"\n expression is not balanced "<<endl;
			}
			break;
		}
		case 3:{
			expr.evaluate();
			break;
		}
		}
	}while(ch!=0);
	return 0;
}
