#include<iostream>

using namespace std;

// This program is insert at head in doublly  LL

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;

    }
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

int getlength(Node* head){
   int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* head,Node* &tail, int data){
        if(head==NULL){
            Node* newNode= new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }

        Node* newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    Node* newNode=new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
void print(Node* head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){

        Node* first=new Node(10);
        Node* second=new Node(20);
        Node* third=new Node(30);


        Node* head=first;
        Node* tail=third;


        first->next=second;
        second->prev=first;

        second->next=third;
        third->prev=second;

        print(first);

        insertAtHead(head,tail,101);

        print(first);
        cout<<endl;
        insertAtHead(head,tail,101);

        cout<<endl;
        print(head);

        insertAtTail(head, tail,210);
        insertAtHead(head,tail,101);

        cout<<endl;
        print(head);
    

    return 0;
}