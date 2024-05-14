// https://leetcode.com/problems/linked-list-cycle/description/
//* TUF: https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class ListNode
{
public:
  int data;
  ListNode *next;

  ListNode(int data1, ListNode *next1)
  {
    data = data1;
    next = next1;
  }

  ListNode(int data1)
  {
    data = data1;
    next = nullptr;
  }
};

/*
*APPROACH 1: using hashset (unordered_map) 
if same node found again, it's the start of cycle

*APPROACH 2 - SLOW AND FAST POINTER 
*INTUTION:

d (distance between slow and fast pointer)
s (slow pointer)
f (fast pointer)
d = |s - f| = 1
which means the distance between the slow and the fast pointer
reduces every time by 1, 
hence we can conlude that fast will catch slow

* NOTE: it's not nessary that till will meet at the start of the loop
they can meet at any node in the loop
*/


//* SOLUTION - 2
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // No node or only one node, so no cycle possible.
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true; // Cycle detected, slow and fast pointers met
            }

            slow = slow->next;        // Move slow pointer one step.
            fast = fast->next->next;  // Move fast pointer two steps.
        }

        // in case of a cycle, there should be no endpoint (NULL)
        // if NULL found, hence no cycle
        return false; 
    }

};