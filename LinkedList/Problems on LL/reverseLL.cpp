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

Node* convertArrToLL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr);
        mover->next = temp;
        mover = temp;
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

// BRUTE FORCE
Node* reverse1(Node* head){
    Node* temp = head;
    stack<int>st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// OPTIMAL SOLN TC = O(N), SC = O(1);
Node* reverse2(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// RECURSIVE
// TC = O(N), SC = O(N);
Node* reverse3(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverse3(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    vector<int>arr = {2,3,5,6,7,9};
    Node* head = convertArrToLL(arr);
    print(head);

    cout<<endl;

    // head = reverse1(head);       //brute force;
    head = reverse2(head);      //most optimal soln
    // head = reverse3(head);      //recursive soln 

    print(head);
    return 0;
}