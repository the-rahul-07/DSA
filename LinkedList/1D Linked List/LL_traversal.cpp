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

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        // or
        mover = temp;
    }
    return head;
}

//Length of linkedlist;
int lengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

//search in LL
int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data==val) return 1;
        temp = temp->next;
    }
    return 0;
}
int main() {
    vector<int>arr1 = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr1);
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;

    cout<<"length of linked list - "<< lengthOfLL(head);

    cout<<endl;

    cout<<checkIfPresent(head, 1);
    return 0;
}