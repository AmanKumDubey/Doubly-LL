#include<bits/stdc++.h>
using namespace std;

// Insert the in at any position in Doubly LL


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
    ~Node(){
        cout<<"Node with value "<<this->data<<" deleted "<<endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data){

        if(head==NULL){
            Node* newNode=new Node(data);
            head=newNode;
            tail=newNode;

            return;
        }
        Node* newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;

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
int getlength(Node* &head){
    
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;


}

void insertAtPosition(Node* &head, Node* &tail,int data, int position){

        if(head==NULL){
            Node* newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;

        }
        if(position==1){
            insertAtHead(head,tail,data);
            return;
        }
        int len=getlength(head);
        if(position>len){
            insertAtTail(head, tail,data);
            return;
        }
        int i=1;
        Node* PrevNode=head;
        while(i<position-1){
            PrevNode=PrevNode->next;
            i++;
        }
        Node* curr=PrevNode->next;

        Node* newNode=new Node(data);

        PrevNode->next=newNode;
        newNode->prev=PrevNode;
        curr->prev=newNode;
        newNode->next=curr;
}

void DeleteAtpostion(Node* head, Node* tail, int position){

    if(head==NULL){
        cout<<"Can't be Deleted ! "<<endl;
        return;
    }
    int len=getlength(head);
    if(position>len){
        cout<<"Enter a valid Position "<<endl;
        return;
    }
    //first
    if(position==1){
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
        return;
    }

    //if only one LL
    if(head->next==NULL){

        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    //last
    if(position==len){
        Node*temp=tail;
        tail=tail->prev;
        temp->prev=NULL;
        tail->next=NULL;
        delete temp;
        return;
    }

    //delete from postion
    int i=1;
    Node* left=head;
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
    delete curr;
    return;
}



void print(Node* &head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
}
int main(){

    Node* head=NULL;
    Node* tail=NULL;
    // insertAtHead(head, tail ,101);

   
    // print(head);
    //  cout<<endl;
    insertAtTail(head, tail, 102);
    insertAtTail(head, tail, 103);
    // print(head);
    // cout<<endl;
    insertAtPosition(head, tail,104,1);
    print(head);
    cout<<endl;
    DeleteAtpostion(head , tail, 3);
    print(head);

    


    return 0;
}
