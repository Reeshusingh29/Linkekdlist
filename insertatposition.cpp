#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node* next;
  
  node(int data){
      this->data=data;
      this->next=NULL;
      
  }
  //destructor
  ~node(){
  	int value=this->data;
  	if(this->next!=NULL){
  		delete next;
  		this->next=NULL;
	  }
	  cout<<"memory is free for node with data "<<value<<endl;
  }
};
void insertathead(node*&head,int d){
    node*temp=new node(d);
    temp->next=head;
    temp=head;
    
}
void insertattail(node*&tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    tail=temp;
}
void insertatposition(node*&tail,node*&head,int position,int d){
   /* if(position==1){
        insertathead(head,d);
        return;
    }*/
   /* if(len==position-1){
    	insertattail(tail,d);
	}*/
    node*temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    /*if(temp->next=NULL){
    	insertattail(tail,d);
    	return ;
	}*/
    
    node*noodetoinsert=new node(d);
    noodetoinsert->next=temp->next;
    temp->next=noodetoinsert;
    
}
void print(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deletenode(node*&head,int position){
	//deleting first or start node
	if(position==1){
		node*temp=head;
		head=head->next;
		//memory free start node
		temp->next=NULL;
		delete temp;
	}
	else{
		//deleting any middle node or last
		node*current=head;
		node*prev=NULL;
		
		int cnt=1;
		while(cnt<=position){
			prev=current;
			current=current->next;
			cnt++;
		}
		prev->next=current->next;
		current->next=NULL;
		delete current;
	}
}
int main(){
 node*node1=new node(10);
 
 node*head=node1;
 node*tail=node1;
 print(head);
 
 insertattail(tail,12);
 print(head);
 
 insertattail(tail,15);
 print(head);
 
 insertatposition(tail,head,1,22);
 print(head);
 cout<<"head"<<head->data<<endl;
 cout<<"tail"<<tail->data<<endl;
 deletenode(head,1);
 print(head);
 cout<<"head"<<head->data<<endl;
 cout<<"tail"<<tail->data<<endl;
}
    

