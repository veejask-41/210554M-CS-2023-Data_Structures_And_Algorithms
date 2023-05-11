#include <iostream>
using namespace std;

struct Node {

    /* data */
    string user_name;
    string password;
    Node *link;
};

struct LinkedList{

    Node * head = NULL;
    Node * tail = NULL;

    int length = 0;

    void insert(string user_name,string password){
        Node * temp = new Node;
        temp->user_name = user_name;
        temp->password = password;
        temp->link = NULL;

        if (head == NULL){
            head = temp;
            tail = temp;
            length++;
        }
        else{
            tail->link = temp;
            tail = temp;
            length++;
        }
    }

    void search(string user_name){
        // output password
        Node * temp = head;
        bool found = false;
        while (temp != NULL){
            if (temp->user_name == user_name){
                cout<<temp->password<<endl;
                found = true;
                break;
            }
            temp = temp->link;
        }
        if (!found){
            cout<<"User not found\n";
        }
    }

    void print_list(){
        if (head == NULL){
            cout<<"[]"<<endl;
        }
        else{
            Node * temp = head;
            cout<< "[";
            while (temp != NULL){
                cout<<temp->user_name<<", ";
                temp = temp->link;
            }
             cout<< "]"<<endl;
        }
    }
};
