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

// BRUTE FORCE TC = O(2N), SC = O(N)
Node* middleOfLL1(Node* head){
    Node* temp = head;
    int cnt = 0;

    while(temp){
        cnt++;
        temp = temp->next;
    }

    temp = head;
    int mid = cnt/2+1;
    while(temp){
        mid--;
        if(mid == 0){
            break;
        }
        temp = temp->next;
    }

    return temp;
}

// OPTIMAL SOLN 
// TORTOISE & HARE ALGORITHM
// SLOW & FAST
// TC = O(N), SC = O(1);
Node* middleOfLL2(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    vector<int>arr = {2,3,5,6,7,9};
    Node* head = convertArrToLL(arr);
    print(head);

    cout<<endl;

    // Node* temp = middleOfLL1(head);      //BRUTE FORCE
    Node* temp = middleOfLL2(head);     //OPTIMAL SOLN
    print(temp);
    return 0;
}