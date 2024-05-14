// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// slow and fast pointer -- single pass solution
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        auto slow = head;
        // to make sure the slow pointer is 1 
        auto fast = head;

        //    (odd: 3rd last node)      && (even: 2nd last node)
        while (fast->next->next != NULL && fast->next->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // skip the next node
        slow->next = slow->next->next;
        return head;
    }
};