#include <iostream>
using namespace std;

//mode class representing a single node in the linked list
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

//stack class
class stack
{
private:
    Node *top; //pointer to the top node of the stack

public:
    stack()
    {
        top = NULL;
    }

    //push operation: insert an elemnt into the toop of the stack
    int push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Push value: " << value << endl;
        return value;
    }

    //pop operation : remove the topmost element from the stack
    void pop()
    {
        Node *temp = top;
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Popped value: " << temp->data << endl;
        top = temp->next;
        delete temp;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "List is Empty." << endl;
        }
        else
        {
            Node *current = top;
            while (current != NULL)
            {
                cout << current->data << " " << endl;
                current = current->next;
            }
            cout << endl;
        }
    }

    bool isEmpty()
    {
        return top == NULL; //return true is the top pointer is NULL, indicating an empty stack
    }
};

int main()
{
    stack stack;

    int choice = 0;
    int value;

    while (choice != 5)
    {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value); //push the entered  value onto the stack
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peek();
                break;
            
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}