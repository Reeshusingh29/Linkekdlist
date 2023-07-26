#include<bits/stdc++.h>
using namespace std;
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

Node* floyddetectloop(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*fast=head;
    Node*slow=head;

    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
Node*startingnode(Node*head){
    if(head==NULL){
        return NULL;
    }
    Node*intersection=floyddetectloop(head);

    if(intersection==NULL){
        return NULL;
    }
    Node*slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL){
        return head;
    }
    Node*startofloop=startingnode(head);

    if(startofloop==NULL){
        return NULL;
    }
    Node*temp=startofloop;
    while(temp->next!=startofloop){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}
int main() {
    // Creating the linked list with a loop
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = head->next->next; // Creating the loop

    // Detect and remove the loop
    head = removeLoop(head);

    // Print the linked list after removing the loop
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

