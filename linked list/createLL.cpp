#include<bits/stdc++.h>
using namespace std;

class LinkedList{
    public:
        int data;
        LinkedList *next;

        LinkedList(int data){
            this->data = data;
            this->next = NULL;
        }   
};

void InsertAtHead(LinkedList * &head,int d){
        LinkedList * temp = new LinkedList(d);
        temp->next = head;
        head = temp;
}

void InsertAtTail(LinkedList *&head,int d){
    LinkedList * temp = new LinkedList(d);
    
    if(head == NULL){
        head = temp;
        return;
    }

    LinkedList *tail = head;

    while (tail->next != NULL){
        tail = tail->next;
    }

    tail->next = temp; 
}

void insertAtIndex(LinkedList* &head, int d, int index){
    
    if(index == 1){
        InsertAtHead(head , d);
        return;
    }

    LinkedList* temp = head;
    int count = 1;

    while (count < index-1 && temp != NULL){
        temp = temp->next;
        count++;
    }
    
    LinkedList *nodeToInsert = new LinkedList(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deletionAtStart(LinkedList* &head){

    if(head == NULL)
        return;

    LinkedList *temp = head;
    head = head->next;
    delete(temp);
}

void deleteAtEnd(LinkedList* &head){

    if(head == NULL)
        return ;

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }    

    LinkedList *temp = head;

    while (temp->next->next != NULL){
        temp = temp->next;   
    }

    free(temp->next);
    temp->next = NULL;      
}

void deleteAtAnyPosition(LinkedList * &head , int index){
    if(head == NULL)
        return;

    LinkedList * temp = head;

    if(index == 1){
        head = temp->next;
        free(temp);
        return;
    }   

    for(int i = 1 ; temp != NULL && i<index-1 ; i++){
        temp = temp->next;
    }

    LinkedList *del = temp->next;
    temp->next = del->next;
    free(del);
   
}
void print(LinkedList *head){
    LinkedList * temp = head;
    while(temp!=NULL){
        cout<<" "<<temp->data;
        temp = temp->next;
    } 
}


int main(){
    LinkedList *head = NULL;

    InsertAtHead(head, 10);
    InsertAtHead(head, 20);
    InsertAtHead(head, 30);
    InsertAtTail(head, 40);

    print(head);

    // insertAtIndex(head , 5, 2);
    // deletionAtStart(head);
    // deleteAtEnd(head);
    deleteAtAnyPosition(head , 3);
    cout<<endl;
    print(head);
}
