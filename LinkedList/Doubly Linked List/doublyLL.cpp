#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

    public:
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* convertArrTo2DLL(vector<int>& arr){
    int n = arr.size();
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;

    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    
    return head;
}
 
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main() {
    vector<int>arr = {2,5,6,8,9};
    Node* head = convertArrTo2DLL(arr);
    print(head);
    return 0;
}