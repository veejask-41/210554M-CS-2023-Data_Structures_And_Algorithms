#include <iostream>
#include <chrono>

using namespace std;

// node of linked list
struct Node
{
    int data;
    Node *next;
};

// implementing stack using linked list
class Stack
{
    Node *top;

    // constructor
public:
    Stack()
    {
        top = NULL;
    }

    // push to top
    void push(int el)
    {
        Node *temp = new Node;
        temp->data = el;
        temp->next = top;
        top = temp;
    }

    // popping from top
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        Node *temp = top;
        top = top->next;
        int el = temp->data;
        delete temp;
        return el;
    }

    // checking if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // checking if the stack is full
    bool isFull()
    {
        Node *temp = new Node;
        if (temp == NULL)
        {
            delete temp;
            return true;
        }
        delete temp;
        return false;
    }

    // finding the top element
    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return top->data;
    }

    // printing the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // start clock
    auto start_time = chrono::steady_clock::now();

    // implementing stack and methods
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    myStack.push(80);
    myStack.push(90);
    myStack.push(100);
    myStack.display();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.display();
    myStack.push(110);
    myStack.push(120);
    myStack.push(130);
    myStack.push(140);
    myStack.display();

    // end clock
    auto end_time = chrono::steady_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Time taken : " << time_taken << " nanoseconds" << endl;

    return 0;
}