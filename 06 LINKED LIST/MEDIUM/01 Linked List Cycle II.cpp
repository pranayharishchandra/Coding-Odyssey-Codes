#include <vector>
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// EASY - just tell true or false
// https://leetcode.com/problems/linked-list-cycle/
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
                return true; // Cycle detected, slow and fast pointers meet.
            }

            slow = slow->next; // Move slow pointer one step.
            fast = fast->next->next; // Move fast pointer two steps.
        }

        return false; // No cycle found.
    }

};


// MEDIUM - TELL THE INDEX THEY MEET
// https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    // Initialize two pointers, slow and fast, to the head of the linked list.
    ListNode* slow = head;
    ListNode* fast = head;

    // Move the slow pointer one step and the fast pointer two steps at a time through the linked list,
    // until they either meet or the fast pointer reaches the end of the list.
    while (fast && fast->next) {

      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) {
        // If the pointers meet, there is a cycle in the linked list.
        // Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
        // until they meet again. The node where they meet is the starting point of the cycle.
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }

    // If the fast pointer reaches the end of the list without meeting the slow pointer,
    // there is no cycle in the linked list. Return nullptr.
    return nullptr;
  }
};