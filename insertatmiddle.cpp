#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    // Corrected constructor
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertatposition(node* &middle, int position, int d) {
    node* temp = middle;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void print(node* middle) {
    node* temp = middle;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(10);
    node* middle = node1;

    // Insert nodes at positions
    insertatposition(middle, 2, 12);
	cout<<"AA GAYA "<<endl;
	 // Insert 12 at position 2 (1-indexed)
    insertatposition(middle, 3, 15); // Insert 15 at position 3 (1-indexed)

    // Print the linked list
    print(middle); // Output: 10 12 15

    // Note: Make sure to free the memory by deleting the nodes when done.
    // In this example, you can add the following code to free the memory.
    // delete node1;
    // delete middle;
    // delete other nodes as well if you have more.
    
    return 0;
}

