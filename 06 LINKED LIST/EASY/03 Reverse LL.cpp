#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// brute - useing stack -- as already solved in "01"

class ListNode {
public:
    int data;   
    ListNode* next;      

    ListNode(int data1, ListNode* next1) {
        data = data1;
        next = next1;
    }

    ListNode(int data1) {
        data = data1;
        next = nullptr;
    }
};

// OPTIMAL 1: ITERATIVE, BY REVERSING (prev, curr nodes)
ListNode* reverseList(ListNode *head) {
   ListNode* temp = head;  
   ListNode* prev = NULL;  
   
   while(temp != NULL){  
       ListNode* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front;  
   }
   
   return prev;  
}

// OPTIMAL 2: RECURSIVE 
ListNode* reverseList(ListNode* head) {

    if (head == NULL || head->next == NULL) 
        return head;
    
    
    ListNode* newHead = reverseList(head->next);
    ListNode* front   = head->next;
    front->next   = head;
    head->next    = NULL;
    
    return newHead;
}
