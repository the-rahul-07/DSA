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
    cout<<endl;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp; 
}

Node* insertTail(Node* head, int val){
    if(head == NULL) return new Node(val, nullptr);

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertAtK(Node* head, int ele, int k){
    if(head == NULL){
        if(k==1){
            return new Node(ele);
        }else{
            return NULL;
        }
    }

    if(k==1){
        Node* temp = new Node(ele, head);
        return temp;
    }
    
    int cnt = 1;
    Node* temp = head;
    while(temp){
        if(cnt==k-1){
            Node* x = new Node(ele, temp);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;    
}

Node* insertBeforeVal(Node* head, int ele, int val){
    if(head == NULL){
        return NULL;
    }

    if(val==head->data){
        Node* temp = new Node(ele, head);
        return temp;
    }

    Node* temp = head;
    while(temp){
        if(temp->next->data == val){
            Node* x = new Node(ele, temp);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;    
}


int main() {
    vector<int>arr1 = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr1);

    print(head);
    cout<<endl;

    cout<<"inserting head"<<endl;
    head = insertHead(head, 9);
    print(head);

    cout<<endl;

    cout<<"inserting tail"<<endl;
    head = insertTail(head, 10);
    print(head);

    cout<<endl;

    cout<<"insert ele at kth"<<endl;
    head = insertAtK(head, 100, 4);
    print(head);

    cout<<endl;

    cout<<"insert ele by value"<<endl;
    head = insertBeforeVal(head, 200, 3);
    print(head);
    return 0;
}
