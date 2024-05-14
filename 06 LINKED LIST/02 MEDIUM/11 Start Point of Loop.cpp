//* https://leetcode.com/problems/linked-list-cycle-ii/solutions/5149081/approach-and-proof-of-solution-using-pointers-slow-fast/
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
* APPROACH 1: USING HASHMAP


* APPROACH 2: POINTERS (slow & fast) 
* Video PROOF: https://youtu.be/2Kd0KKmmHFc?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&t=939
* My article proof: https://leetcode.com/problems/linked-list-cycle-ii/solutions/5149081/approach-and-proof-of-solution-using-pointers-slow-fast/

* APPROACH 2 AND PROOF: 
[ start node: the starting node of the loop ]

when slow reaches the start node by travelling L1, 
the fast have moved L1 away from slow, 
(since fast moves twice the distance of slow)
let the distance for fast to catch slow be “d”

so the total length of loop will be (L1: slow to catch fast + d: fast to catch slow)

now the slow will move d node and then fast and slow will collide/meet

so slow have travelled “d” distance away from start node
since fast and slow collided
=>hence fast is also “d” distance away from start node

but we know that length of loop is L1 + d

hence fast will move L1 distance to reach to start node

also L1 is the distance from the head to the start node

hence put the slow pointer to the head 
and keep moving slow and the fast pointers both by 1 step

and after travelling L1 distance they will meet at the start node

return the start node 
 */
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    // Move the slow pointer one step and the fast pointer two steps at a time through the linked list,
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        // If the pointers meet, means there is a cycle
        // Reset the slow pointer to the head of the linked list
        // after L1 distance the both will meet at the start node
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }

    // if fast pointer encounters a NULL endpoint
    // hence no cycle, hence return false or 0 or NULL or nullptr
    return nullptr;
  }
};