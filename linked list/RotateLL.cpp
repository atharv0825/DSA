#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

class Solution{

    public:
        ListNode* rotateRight(ListNode* head , int k){
            if(head == NULL || head->next == NULL)
                return head;

            ListNode *current = head;
            int length = 0;

            while(current){
                length++;
                current = current->next;
            }

            k = k%length;

            if(k==0)
                return head;

            ListNode *fast = head;
            ListNode *slow = head;
                
            while(k--){
                fast = fast->next;
            }    

            while(fast->next){
                slow = slow->next;
                fast = fast->next;
            }

            ListNode * newHead = slow->next;
            fast->next = head;
            slow->next = nullptr;

            return newHead;
        }
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    
    // Create a linked list from an array of values
    std::vector<int> values = {1, 2, 3, 4, 5,6};
    ListNode* head = createList(values);
    
    int k = 3;  // Number of rotations

    std::cout << "Original List: ";
    printList(head);
    
    ListNode* rotatedHead = solution.rotateRight(head, k);

    std::cout << "Rotated List by " << k << " positions: ";
    printList(rotatedHead);

    return 0;
}