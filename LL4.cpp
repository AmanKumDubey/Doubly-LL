#include<bits/stdc++.h>
using namespace  std;


class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

int getLENGTH(Node* head){

    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void InsertAtHead(Node* &head, Node* &tail, int data){

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
void InserAtTail(Node* head, Node* tail,int data){

    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    newNode->prev=tail;
    tail->next=newNode;
    tail= newNode;

}


// insert at any position

void InsertAtanyposition(Node* head, Node* tail, int postion, int data){

    if(postion==1){
        InsertAtHead(head, tail,data);
        return;
    }
    int len=getLENGTH(head);
    if(postion>len){
        InserAtTail(head,tail,data);
        return;
    }

    int i=1;
    Node* prevNode=head;
    while(i<postion-1){
        prevNode=prevNode->next;
        i++;
    }
    Node* newNode=new Node(data);
    Node* curr=prevNode->next;

    prevNode->next=newNode;
    newNode->prev=prevNode;

    newNode->next=curr;
    curr->prev=newNode;
}

void deleteAtAnyPosition(Node* head, Node* tail, int position){

    if(head==NULL){
        cout<<"Cant be deelted "<<endl;
        return;
    }
    int len=getLENGTH(head);
    if(position>len){
        cout<<"Enter valid position "<<endl;
        return;
    }

    if(postion==1){
        Node* temp=head;
        head=head->next;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }

    // if only one ll
    if(head->next==NUL){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return ;
    }
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
    Node* second= new Node(20);
    Node* third=new Node(30);


    Node* head= first;
    Node* tail=third;

    first->next=second;
    second->prev=first;

    second->next=third;
    third->prev=second;

    print(first);

    InsertAtHead(head, tail, 5);
    cout<<endl;
    print(head);
    
    InserAtTail(head, tail, 35);
    cout<<endl;
    print(head);

   
   
    cout<<endl<<"The LL length is : "<< getLENGTH(head)<<endl;

    InsertAtanyposition(head, tail, 3, 25);
    print(head);




    return 0;
}