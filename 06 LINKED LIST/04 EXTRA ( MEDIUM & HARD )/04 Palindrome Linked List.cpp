// https://leetcode.com/problems/palindrome-linked-list/description/
//* TUF: https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/

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


// BRUTE 1: USING STACK - (stack for comparing elements in reverse order)

// OPTIMAL 1: ITERATIVE, BY REVERSING (prev, curr nodes)

//* Function to reverse a linked list, using the recursive approach
class Solution {
private:
  ListNode* reverseLinkedList(ListNode* head) {
      if (head == NULL || head->next == NULL) 
          return head; 

      ListNode* newHead = reverseLinkedList(head->next);

      ListNode* front = head->next;
      front->next = head;
      head->next = NULL;
      return newHead;
  }

public:
  bool isPalindrome(ListNode* head) {

      if (head == NULL || head->next == NULL) {
          // It's a palindrome by definition
          return true; 
      }
      
      // Initialize two pointers, slow and fast,
      // to find the middle (even: M1, odd: M) of the linked list
      ListNode* slow = head;
      ListNode* fast = head;
      
      // Traverse the linked list to find the
      // middle (even:M1 or M) using slow and fast pointers
      //* (last node - odd) && (2nd last node - even)
      while (fast->next != NULL && fast->next->next != NULL) {
          slow = slow->next;  
          fast = fast->next->next;  
      }
      
      //* Reverse the second half of the, linked list starting from the middle
      ListNode* newHead = reverseLinkedList(slow->next);
      
      ListNode* first  = head;    // Pointer to the first half
      ListNode* second = newHead; // Pointer to the reversed second half
      
      //* (odd LL: 2nd half shorter), (even LL: 2nd half same len)
      //* therefore, if second ends, means both half same, hence pallindrome
      while (second != NULL) { 
          
          // comparing 2 LL, if not equal then not palindrome
          if (first->data != second->data) {
              
              // Reverse the second half, back to it's original state
              reverseLinkedList(newHead);  
              
              return false; // Not a palindrome
          }

          first = first->next; 
          second = second->next;  
      }
      
      // Reverse the second half, back to it's original state
      reverseLinkedList(newHead);  
      
      return true;  // The linked list is a palindrome
  }
};
