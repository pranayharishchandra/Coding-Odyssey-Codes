// https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

//* struct NODE
struct ListNode {
    int val;
    ListNode *next;
    ListNode()                     : val(0), next(nullptr) {}
    ListNode(int x)                : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

/*
The time complexity of this solution is O(N), where N is the number of nodes in the linked list.

The first loop traverses through all nodes of the linked list once to build the stack, which takes O(N) time.
The second loop iterates over the stack to reconstruct the linked list in reverse order, which also takes O(N) time.
The space complexity is also O(N), where N is the number of nodes in the linked list.

The stack can contain at most N nodes, one for each node in the linked list.
Additionally, the space complexity of the input and output is O(1) as we are not using any additional space for them.
*/

class Solution {
public: 
    ListNode* removeNodes(ListNode* head) {
        // Initialize a stack to store nodes in non-decreasing order of their values
        stack<ListNode*> stack;

        //* STACK WILL BE STORING THE NUMBERS IN DECREASING ORDER, 
        //* since right has to be smaller than left in final LL
        
        // Traverse the linked list
        ListNode* cur = head;
        while (cur != nullptr) {
            //* Remove nodes from the stack whose values are 
            //* less than the current node's value
            //* "since: storing in stack in desc order (top - small, bottom - large)"
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            // Push the current node onto the stack
            stack.push(cur);
            // Move to the next node
            cur = cur->next;
        }
        
                                   //* Reconstruct the linked list in "reverse order" using nodes from the stack
        ListNode* prev = nullptr;  // Pointer to the next node in the reversed list
        while (!stack.empty()) {
            cur       = stack.top();  // Get the top node from the stack
            stack.pop();              // Pop the top node from the stack
            cur->next = prev;         // Set the next pointer of the current node to the next node in the reversed list
            prev      = cur;          // Update the pointer to the next node in the reversed list
        }
        
        return cur;  // Return the head of the reversed list
    }
};
