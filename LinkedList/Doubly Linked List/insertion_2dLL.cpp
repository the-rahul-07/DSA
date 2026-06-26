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

Node* convertTo2DLL(vector<int>&arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
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

Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}


//Insert before tail
Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL){
        return insertBeforeHead(head, val);  
    }
    Node* tail = head;

    while(tail->next != NULL){
        tail= tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// INSERT BEFORE Kth Element;
Node* insertBeforeKthEle(Node* head, int k, int val){
    if(k == 1){
        return insertBeforeHead(head, val);
    }
    Node* temp = head;  
    int cnt = 0;
    while(temp!=NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

// insert before node
void insertBeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

int main() {
    vector<int>arr = {3,6,8,9,1};
    Node* head = convertTo2DLL(arr);
    print(head);

    cout<<endl;

    cout<<"insert before head"<<endl;
    head = insertBeforeHead(head, 100);
    print(head);

    cout<<endl;

    cout<<"insert before tail"<<endl;
    head = insertBeforeTail(head, 200);
    print(head); 

    cout<<endl;

    cout<<"insert before Kth Element"<<endl;
    head = insertBeforeKthEle(head, 3, 400);
    print(head);

    cout<<endl;

    cout<<"insert before node"<<endl;
    insertBeforeNode(head->next, 200);
    print(head);
    return 0;
}