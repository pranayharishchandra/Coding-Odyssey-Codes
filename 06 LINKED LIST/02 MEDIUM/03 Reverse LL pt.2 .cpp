// https://leetcode.com/problems/reverse-linked-list-ii/description/
// followup question of REVERSE LINKED LIST 1
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

// SOLUTION - 1 - (dummy as reference type)
class Solution {
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if list is empty or noting to reverse
        if (!head || left == right)
            return head;
        
        // dummy node to handle corner cases of reversing of head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; ++i)
            prev = prev->next;

        ListNode* const beforeLeft = prev;
        ListNode* const leftNode   = prev->next;
        ListNode* rightNode = leftNode;
        
        for (int i = left; i < right; ++i)
            rightNode = rightNode->next;

        ListNode* const afterRight = rightNode->next;

        rightNode->next  = nullptr;

        // reversing list from left to right
        beforeLeft->next = reverseList(leftNode);
        leftNode->next   = afterRight;

        return dummy.next;
    }
};

// SOLUTION - 2 -- dummy as pointer variable
class Solution {
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // if list is empty or noting to reverse
        if (!head || left == right)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next     = head;
        ListNode* prev  = dummy;

        for (int i = 1; i < left; ++i)
            prev = prev->next;

        ListNode* const beforeLeft = prev;
        ListNode* const leftNode   = prev->next;
        ListNode* rightNode = leftNode;
        
        for (int i = left; i < right; ++i)
            rightNode = rightNode->next;

        ListNode* afterRight = rightNode->next;

        rightNode->next = nullptr;

        // reversing the list from leftNode to rightNode
        beforeLeft->next = reverseList(leftNode);

        leftNode->next   = afterRight;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};


// SOLUTION - 3 - ITERATIVE SOLUTION
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to the node before the sublist to be reversed
        for (int i = 1; i < left; ++i)
            prev = prev->next;

        ListNode* const beforeLeft = prev;
        ListNode* const leftNode   = prev->next;
        ListNode* rightNode = leftNode;
        
        // Move rightNode to the last node of the sublist to be reversed
        for (int i = left; i < right; ++i)
            rightNode = rightNode->next;

        ListNode* const afterRight = rightNode->next;

        // Reverse the sublist iteratively
        ListNode* prevNode = afterRight;  // prevNode points to the node after the sublist
        ListNode* current  = leftNode;
        ListNode* nextNode;

        while (current != afterRight) {
            nextNode      = current->next;
            current->next = prevNode;
            prevNode      = current;
            current       = nextNode;
        }

        // Connect the reversed sublist with the rest of the list
        beforeLeft->next = rightNode;
        leftNode->next   = afterRight;

        return dummy.next;
    }
};

