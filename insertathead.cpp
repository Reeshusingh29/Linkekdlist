#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;   
		
		//constructor
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};

void Insertathead(Node* &head,int d){
	//new node create
	Node*temp=new Node(d);
	temp->next=head;
	head=temp;
}
void print(Node* &head){
	Node* temp=head;
	
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	Node* node1=new Node(10);
	/*cout<<node1 -> data<<endl;
	cout<<node1 -> next<<endl;*/
	
	//head pointed to new node
	Node* head=node1;
	print(head);
	
	Insertathead(head,12);
	print(head);
	
	Insertathead(head,14);
	print(head);
	
	return 0;
}
