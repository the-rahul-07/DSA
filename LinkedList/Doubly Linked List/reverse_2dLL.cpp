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

Node* convertArr2dLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// BRUTE FORCEM TC = O(2N), SC = O(N);
Node* reverse2DLL1(Node* head){
    Node* temp = head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    Node* temp2 = head;
    while(temp2!=NULL){
        temp2->data = st.top();
        st.pop();
        temp2 = temp2->next;
    }
    return head;
}

// OPTIMAL SOLN TC = O(N), SC = O(1);
Node* reverse2DLL2(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* current = head;
    while(current!=NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }

    return last->back;
}

int main() {
    vector<int>arr = {2,4,6,8,9,10};
    Node* head = convertArr2dLL(arr);
    print(head);

    cout<<endl;

    cout<<"revesed LL"<<endl;
    head = reverse2DLL2(head);
    print(head);
    return 0;
}