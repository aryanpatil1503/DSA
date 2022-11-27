//============================================================================
// Name        : assignment13_SEM3_dsl.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Deque
{
private:
    int front = -1,rear = -1;
public:
    void add_front(int myarr[], int n)
    {
        int x;
        cout << "\n Enter element to add: ";
        cin >> x;
        if (front == -1)
        {
            front = front + 1;
            rear = rear + 1;
            myarr[front] = x;
            cout << "Element added in front" << endl;
            cout << endl;
        }
        else if (front != 0)
        {
            front = front - 1;
            myarr[front] = x;
            cout << "Element added in front" << endl;
            cout << endl;
        }
        else
        {
            cout << "Element cannot be added" << endl;
            cout << endl;
        }
    }

    void add_back(int myarr[],int n)
    {
        int x;
        cout << "Enter element to add: ";
        cin >> x;
        if (rear >= n - 1)
        {
            cout << "Element cannot be added" << endl;
            cout << endl;
        }
        else
        {
            if (front == -1)
            {
                front++;
                rear++;
            }
            else
            {
            	rear++;
            }
            myarr[rear] = x;
            cout<<front<<endl;
            cout<<rear<<endl;
            cout << "Element added at end" << endl;
            cout << endl;
        }
    }

    void del_front(int myarr[], int n)
    {
        if (front == -1)
        {
            cout << "Deletion not possible" << endl;
            cout << endl;
            return;
        }
        else
        {
            cout << "Element deleted from front" << endl;
            cout << endl;
            if (front == rear)
            {
                front = rear = -1;
                return;
            }
            else
            {
                front = front + 1;
            }
        }
    }

    void del_back(int myarr[], int n)
    {
        if (front == -1)
        {
            cout << "Deletion not possible" << endl;
            cout << endl;
            return;
        }
        else
        {
            cout << "Element deleted from back" << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
            	rear = rear - 1;
            }
        }
    }

    void display(int myarr[],int n)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << myarr[i] << " ";
        }
    }

};

int main()
{
    int myarr[20];
    int n;
    cout << "Enter size of queue: ";
    cin >> n;

    Deque obj;

    while (true)
    {
        cout << "Enter 1 to add element in front" << endl;
        cout << "Enter 2 to add element at back" << endl;
        cout << "Enter 3 to delete element from front" << endl;
        cout << "Enter 4 to delete element from back" << endl;
        cout << "Enter 5 to display dequeue" << endl;
        cout << "Enter 6 to exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            obj.add_front(myarr, n);
            cout << endl;
        }
        else if (choice == 2)
        {
            obj.add_back(myarr, n);
            cout << endl;
        }
        else if (choice == 3)
        {
            obj.del_front(myarr, n);
            cout << endl;
        }
        else if (choice == 4)
        {
            obj.del_back(myarr, n);
            cout << endl;
        }
        else if (choice == 5)
        {
            obj.display(myarr, n);
            cout << endl;
        }
        else if (choice == 6)
        {
            cout << endl;
            cout << "Thank You!" << endl;
            break;
        }
        else
        {
            cout << "Enter valid choice" << endl; cout << endl;
        }

    }

}
