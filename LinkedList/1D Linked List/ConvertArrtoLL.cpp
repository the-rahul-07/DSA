#include<iostream>
#include<bits/stdc++.h>

using std :: cout;
using std :: cin;
using namespace std;

class Node{
    public:
        int data;
        Node* next;

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

Node* convertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=0; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        // or
        mover = temp;
    }

    return head;
}
int main() {
    vector<int>arr1 = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr1);
    cout<<head->data<<endl;
    return 0;
}