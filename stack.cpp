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
        if (isEmpety())
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
}