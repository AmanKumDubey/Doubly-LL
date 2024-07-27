#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail,int data){

    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    Node* newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void printDLL(Node* &head){

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<< " ";
        temp=temp->next;
    }
}
void insertAtTail(Node* &head, Node* &tail,int data){

        if(head==NULL){
            Node* newNode= new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }

        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        
}
int getLenght(Node* &head){

    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){

    if(position==1){
        insertAtHead(head, tail, data);
        return;
    }
    int len=getLenght(head);
    if(position>=len){
        insertAtTail(head,tail, data);
        return;
    }

    Node* prevNode=NULL;
    Node* currNode=head;
    int i=1;
    while(i<position){
        prevNode=currNode;
        currNode=currNode->next;
        i++;
    }

    Node* newNode= new Node(data);
    prevNode->next=newNode;
    newNode->prev=prevNode;
    newNode->next=currNode;
    
}
// void deleteAtPosition(Node* &head, Node* &tail, int position){

//     if(head==NULL){
//         return;
//     }
//     if(head->next==NULL){
//         Node* temp=head;
//         head=NULL;
//         tail=NULL;
//         delete temp;
//         return;
//     }

//     if(position==1){
//         Node* temp=head;
//         head=head->next;
//         head->prev=NULL;
//         temp->next=NULL;
//         delete temp;
//         return;
//     }
//     int len=getLenght(head);

//     if(position>len){
//         cout<<"Enter the valid position "<<endl;
//         return;
//     }
//     if(position==len){
//         Node* temp=tail;
//         tail=tail->prev;
//         tail->next=NULL;
//         temp->prev=NULL;
//         delete temp;
//         return;
//     }

//     // delete from position

//     int i=1;
//     Node* leftNode=head;

//     while(i<position-1){
//         leftNode=leftNode->next;
//         i++;
//     }
//     Node* currNode=leftNode->next;
//     Node* rightNode=currNode->next;

//     leftNode->next=rightNode;
//     rightNode->prev=leftNode;

//     currNode->next=NULL;
//     currNode->prev=NULL;
//     delete currNode;
// }
void deleteAtPosition(Node* &head, Node* & tail,int position){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        Node* temp=head;
        head=NULL;
        head->next=NULL;
        delete temp;
    }

    if(position==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    int len=getLenght(head);
    if(position>len){
        cout<<"Enter valid Number"<<endl;
        return;
    }
    if(position==len){
        Node* temp=tail;
        tail=tail->next;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }

    Node* left=head;
    int i=1;
    while(i<position-1){
        left=left->next;
        i++;
    }
    Node* curr=left->next;
    Node* right=curr->next;

    left->next=right;
    right->prev=left;
    curr->next=NULL;
    curr->prev=NULL;

}
int main(){

    Node* first= new Node(10);
    Node* second=new Node(30);
    Node* third=new Node(50);

    Node* head=first;
    Node* tail=third;
   
    first->next=second;
    second->prev=first;

    second->next=third;
    third->prev=second;

    insertAtHead(head, tail,100);
    insertAtHead(head, tail, 200);
    insertAtHead(head, tail,90);

    printDLL(head);
    cout<<endl;
    insertAtTail(head, tail,400);
    insertAtTail(head, tail, 500);
    insertAtTail(head, tail, 600);

    printDLL(head);
    cout<<endl;
    insertAtPosition(head, tail,10, 5);
    printDLL(head);
    cout<<endl;

    

    
         deleteAtPosition(head, tail, 1);
         printDLL(head);
         cout<<endl;
          deleteAtPosition(head, tail, 1);
         printDLL(head);
          cout<<endl;
          deleteAtPosition(head, tail, 1);
         printDLL(head);
          cout<<endl;
          deleteAtPosition(head, tail, 1);
         printDLL(head);
          cout<<endl;
          deleteAtPosition(head, tail, 1);
         printDLL(head);
         cout<<endl;
         deleteAtPosition(head, tail, 2);
         printDLL(head);
         cout<<endl;
         deleteAtPosition(head, tail, 1);
         printDLL(head);
         cout<<endl;

    return 0;
}