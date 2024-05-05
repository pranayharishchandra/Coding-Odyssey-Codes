// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// BRUTE : O(2n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;
        
        // Step 1: Traverse the linked list to find its length
        while(temp != nullptr) {
            len++;
            temp = temp->next;
        }
        
        // Reset temp to the head of the list
        temp = head;
        ListNode* prev;
        int pos = len - n;
        
        // Special case: If the node to be removed is the head itself
        if(pos == 0) return head->next;
        
        // Step 2: Traverse the list again to reach the node
        //         just before the one to be removed
        for(int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        
        // Step 3: Update the pointers to remove the node
        prev->next = temp->next;
        
        // Step 4: Delete the removed node
        delete temp;
        
        return head;   
    }
};

// OPTIMAL: O(n)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        for (int i = 0; i <= n; ++i) {
            // if length of linked list is less than n value, 
            // don't remove anything
            if (first == NULL) return head;
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy->next;
    }
};