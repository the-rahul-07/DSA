#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    //constructors;
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
    
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

int main() {
    vector<int>arr = {
        2,3,5,6
    };
    
    //Creating an Object;
    Node y = Node(arr[2], nullptr);
    // cout<<y;        //shows error coz y is object;
    cout<<y.next<<endl;       //valid
    cout<<y.data<<endl;       //valid

    //
    Node* x = new Node(arr[3], nullptr);
    cout<<x<<endl;          //gives address/pointer
    cout<<x->data<<endl;          //gives value;
    // cout<<x.next;       //invalid
    // cout<<x.data;       //invalid
    return 0;
}