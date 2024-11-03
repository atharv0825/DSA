#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {

private:
    Node * clone(Node * &head , Node * &tail , int data){
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        return tail;
    }

public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
       
        // Step 1 : Make clone of list without Random pointer
        Node * cloneHead = NULL;
        Node * cloneTail = NULL;

        Node * temp = head;

        while(temp!=NULL){
            clone(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }

        // Step 2 : Make Mapping of old list with new list

        unordered_map<Node*,Node*>oldToNewNode;
        Node * originalNode = head;
        Node * cloneNode = cloneHead;
            
        while(originalNode != NULL and cloneHead != NULL){
            oldToNewNode[originalNode] = cloneNode;
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
         
        // step 3 : Assign random pointers to the newNode;
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode->random = oldToNewNode[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        } 
        return cloneHead;
    }
};

// Function to print a linked list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "Node value: " << temp->val;
        if (temp->random) {
            std::cout << ", Random points to: " << temp->random->val;
        } else {
            std::cout << ", Random points to: NULL";
        }
        std::cout << std::endl;
        temp = temp->next;
    }
}

int main() {
    // Creating a sample linked list with random pointers
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    
    // Setting up next pointers
    node1->next = node2;
    node2->next = node3;

    // Setting up random pointers
    node1->random = node3;  // node1's random points to node3
    node2->random = node1;  // node2's random points to node1
    node3->random = node2;  // node3's random points to node2

    // Creating Solution object
    Solution solution;
    Node* copiedListHead = solution.copyRandomList(node1);

    // Printing original list
    std::cout << "Original list:" << std::endl;
    printList(node1);

    // Printing copied list
    std::cout << "\nCopied list:" << std::endl;
    printList(copiedListHead);

    // Free allocated memory
    delete node1;
    delete node2;
    delete node3;
    return 0;
}
