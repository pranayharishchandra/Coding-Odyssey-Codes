// https://leetcode.com/problems/reverse-linked-list/description/
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

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


// BRUTE 1: USING STACK - store all elements in the stack

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

    // if you have only 1 node, you can't reverse it and
    // then it itself if ur answer
    if (head == NULL || head->next == NULL) 
        return head;
    
    // head of the reversed LL, head of a LL always should  
    // be returned in any recursive LL question
    ListNode* newHead = reverseList(head->next); 

    // front has now become the 
    //* front of reversed LL
    ListNode* front   = head->next;

    // add current node (head) to the end of the reversed LL
    // i.e. after the front (end of reversed LL)
    front->next   = head;
    head->next    = NULL;
    
    return newHead;
}
