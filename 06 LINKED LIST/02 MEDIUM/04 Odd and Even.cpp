// https://leetcode.com/problems/odd-even-linked-list/solutions/1606963/c-simplest-solution-w-explanation-one-pass/

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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // if LL have less than 3 nodes - no need to do anything
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd  = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        // LOGIC:
        // head and even_start -> are the 'head'      of odd and even LL respectively
        // odd  and even       -> are the 'iterators' of odd and even LL respectively
        // "symultaneous" add in odd and even LL by skipping the next node 
        while(odd->next && even->next){
            odd->next  = even->next;       //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd        = odd->next;
            even       = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }
};