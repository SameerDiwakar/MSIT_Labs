#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(){

    }

};

Node* takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
        }else{
            Node*temp = head;
            while(temp->next != NULL){
                temp=temp -> next;
            }temp ->next = newNode;
            
            
        }
        cin >> data;
    }
    return head;


}
Node* takeInput_better(){
    int data;
    cin >> data;     
    Node *head = NULL;
    Node *tail = NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail-> next = newNode;
            tail = tail -> next;
            // or tail = newNode;
            
            
        }
        cin >> data;
    }
    return head;

}

Node* InsertNode(Node *head , int i , int data ){
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i==0){
        newNode->next= head;
        head = newNode;
        return head;
    }
    while(count <= i-1 && temp!=NULL){
        temp = temp->next;
        count++;
    }
    if (temp!=NULL){
        newNode -> next = temp->next;
        temp->next = newNode;
    }
    return head;

}


void print(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    } 
}

Node* delete_node(Node *head,int i){
    int count = 0 ;
    Node*temp = head;
    if (head == NULL){
        return head;
    }
    if (i == 0){
        return head->next;
    }
    while(count < i-1 &&temp!=NULL){
        temp = temp->next;
        count++;
    }
    if (temp!=NULL && temp->next!=NULL){
        Node *a = temp->next;
        temp->next = a->next;
        delete a;
    }
    return head;
}

int main(){
    Node *head = takeInput();
    print(head);
    head = InsertNode(head,0,4);
    cout << "\n";
    print(head);
    Node *bed = delete_node(head,5);
    print(bed);
    


}
