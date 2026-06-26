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

//REMOVING HEAD OF 2DLL;
Node* deleteHead(Node* head){
    if(head == NULL) return NULL;

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr; 
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL)
        return NULL;

    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    delete tail;
    return head;
}

// Delete Kth ele of DLL
Node* deleteKthEle(Node* head, int k){
    if(head == NULL) return NULL;
    Node* kNode = head;
    
    int cnt = 0;
    while(kNode != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        kNode = kNode->next;
    }
    
    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }else if(prev == NULL){
        head = deleteHead(head);
        return head;
    }else if(front == NULL){
        head = deleteTail(head);
        return head;
    }else{
        prev->next = front;
        front->back = prev;

        kNode->next  = nullptr;
        kNode->back = nullptr;

        delete kNode;
        return head;
    }
}

Node* deleteNode(Node* head, int ele){
    if(head == NULL) return NULL;

    if(head->next == NULL && head->back == NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == ele){
            break;
        }
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }else{
        prev->next = front;
        front->back = prev;

        temp->next = temp->back = nullptr;

        delete temp;
        return head;
    }
}

// OR

void deleteNode2(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;

        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
}

int main() {
    vector<int>arr = {3,6,8,9,1,4};
    Node* head = convertTo2DLL(arr);
    print(head);

    cout<<endl;

    cout<<"deleting head"<<endl;
    head = deleteHead(head);
    print(head);
    
    cout<<endl;

    cout<<"deleting tail"<<endl;
    head = deleteTail(head);
    print(head);

    cout<<endl;

    cout<<"deleting Kth Node"<<endl;
    head = deleteKthEle(head, 2);
    print(head);

    cout<<endl;

    cout<<"delete node"<<endl;
    head = deleteNode(head, 1);
    print(head);

    cout<<endl;

    cout<<"delete node (striver)"<<endl;
    deleteNode2(head->next);
    print(head);
    return 0;
}