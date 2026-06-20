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

// REMOVE HEAD FROM LL
Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node*temp = head;
    head = head->next;
    // free(temp);  //if we allocate node using MALLOC() then use free(temp);
    // or
    delete temp;    //if we use 'new' to allocate node then use 'delete'
    return head;
}

// REMOVE TAIL FORM LL
Node* removeTail(Node* head){
    if(head == NULL || head->next==NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}


// DELETE KTH ELEMENT OF LL -> TC = O(k)
Node* deleteKthEle(Node* head, int k){
    if(head == NULL) return head;

    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;
    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}

// DELETE ELEMENT BASED UPON VALUE;
Node* deleteByVal(Node*head, int val){
    if(head == NULL) return head;

    if(val == head->data){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while(temp){
        if(val == temp->data){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int>arr1 = {1,2,3,4,5,6};
    Node* head = convertArr2LL(arr1);

    cout<<"Head Remove"<<endl;
    cout<<"Before"<<endl;
    print(head);
    
    cout<<"After"<<endl;
    head = removeHead(head);
    print(head);

    cout<<endl;

    cout<<"Tail Remove"<<endl;
    cout<<"Before"<<endl;
    print(head);

    cout<<"After"<<endl;
    head = removeTail(head);
    print(head);

    cout<<endl;

    cout<<"Delete Kth Ele"<<endl;
    head = deleteKthEle(head, 3);
    print(head);

    cout<<endl;

    cout<<"Delete by val"<<endl;
    head = deleteByVal(head, 3);
    print(head);

    cout<<"hello";
    return 0;
}
