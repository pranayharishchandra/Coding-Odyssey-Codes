#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/*
* APPROACH 1 - USING HASHMAP (unordered_map) : (Node, timer)
if you find the same node again, 
=> reduce current timer with timer it was previously visited
you will get the time it took to again come back to the same node
and that will be number of nodes in the cycle

* APPROACH 2 - POINTERS (slow & fast, ptr)
- just detect the cycle using (slow & fast)
- then use ptr to calculate number of nodes in the cycle

* NOTE: it's not nessary that till will meet at the start of the loop
they can meet at any node in the loop
*/

//* SOLUTION 2 - POINTERS (slow & fast, ptr)
int countNodesinLoop(struct Node *head)
{
    Node* slow = head, *fast = head;
    if(head==NULL || head->next == NULL) return 0; // No cycle
    
    slow = slow->next;
    fast = fast->next->next;

    while(fast!=NULL && fast->next != NULL){
        int count = 1;

        // if fast == slow, cycle detected, 
        // now time to check the length of the loop
        // ptr will travel over the loop and 
        // count will track how many nodes in cycle
        if(slow == fast){
            Node* ptr = slow->next;
            while(ptr!=slow){
                count++;
                ptr = ptr->next;
            }
            return count;
        }
        // 
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // if fast encounted a NULL endpoint
    // means there is no cycle, return false or 0
    return 0;
}