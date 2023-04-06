#include <iostream>
#include <chrono>
using namespace std;

// implementing stack using array
class Stack
{
    int *stack;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        stack = new int[size];
        top = 0;
        capacity = size;
    }

    // insert element
    void push(int el)
    {
        if (top == capacity)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[top] = el;
        top++;
    }

    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        top--;
        return stack[top];
    }

    bool isEmpty()
    {
        return top == 0;
    }

    bool isFull()
    {
        return top == capacity;
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return stack[top - 1];
    }

    void display()
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    auto start_time = chrono::steady_clock::now();

    // implementing stack and methods
    Stack myStack(10);
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

    auto end_time = chrono::steady_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Time taken : " << time_taken << " nanoseconds" << endl;
    return 0;
}