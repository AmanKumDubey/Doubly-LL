#include<bits/stdc++.h>

using namespace std;

// Reverse a LL

 class Node{
        public:
        int data;
        Node* next;

        Node(){
            this->data=0;
            this->next=NULL;
        }

        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};



void insertAthead(Node* &head, Node* &tail,int data){


    if(head==NULL){
        Node * newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    //Create a node
    //step 1
    Node* newNode=new Node(data);
    //initialise
    newNode->next=head;
    
    head=newNode;
}

//insert at tail

void insertAtTail(Node* &head, Node* &tail, int data){
  
    if(head==NULL){
        //first node ab add hone wali h
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode=new Node(data);
    tail->next=newNode;
    tail=newNode;

    
}
int findlength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtposition(int position, int data, Node* &head, Node* &tail){

        if(head==NULL){
            Node* newNode=new Node(data);
            head=newNode;
            tail=newNode;
            return;
        }

        // insert at head
        if(position==0){
            insertAthead(head, tail,data);
        }

        //insert at tail
    int len=findlength(head);
    if(position>=len){
        insertAtTail(head, tail, data);
        return;
    }

        // Step. 1  Find Position
        int i=1;
        Node* prev=head;
        while(i<position){
            prev=prev->next;
            i++;
        }
        Node* curr=prev->next;

        // Step 2 
        Node*newNode=new  Node(data);
        //step 3
        newNode->next=curr;

        // Step 4
        prev->next=newNode;

}



Node* reverse(Node* &prev, Node* &curr){
    if(curr==NULL){
        return prev;
    }

    Node* forward=curr->next;
    curr->next=prev;

   return reverse(curr, forward);
}

Node* reverseUseLoop(Node* &head){
    Node* prev=NULL;
    Node* curr=head;

    while(curr!=NULL){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
Node* ReverseuseRecursion(Node* prev, Node* curr){
    if(curr==NULL)
    {
        return prev;
    }
    Node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;

    return ReverseuseRecursion(prev,curr);
}

void print(Node* &head){

    Node*temp=head;
    while(head!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){

    Node* head=NULL;
    Node* tail=NULL;

    // insertAthead(head, tail, 20);
    // insertAthead(head, tail, 40);
    // insertAthead(head, tail, 60);
    // insertAtTail(head, tail,22);
    // insertAtTail(head, tail,87);

    insertAtposition(1,12,head, tail);
    insertAtposition(2,22,head, tail);
    insertAtposition(3,32,head, tail);
    insertAtposition(4,42,head, tail);
    insertAtposition(5,52,head, tail);
    

        print(head);
        
   
        cout<<endl;
    Node* prev=NULL;
    Node* curr=head;
    // head=reverse(prev,curr);
   // head=reverseUseLoop(head);
   head= ReverseuseRecursion(prev,curr);
        
    cout<<endl;
    print(head);
    cout<<endl;


    return 0;
}