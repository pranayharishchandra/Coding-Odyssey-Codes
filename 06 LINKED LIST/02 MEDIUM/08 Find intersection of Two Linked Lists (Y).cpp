
//https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/1093014/c-four-different-solutions/

//*TUF: https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
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
*APPROACH 1: bruteforce
for every node in LL1, check if it present in LL 2
if it is present in LL2 then return that node
that node represent the Y intersection point of the LL

* APPROACH 2: HASHING - (optimising brute forct by rembering node we have visited)

store all the nodes of LL1 in the hashset <*ListNode>
then traverse on LL2, and check if the node is present in hashset
if the node is present, return that node

* APPROACH 3: Optimal - (checking the length of the LL1, LL2)
-check the length of the LL1 and LL2
-the greater of them, increase the pointer by |len(LL1) - len(LL2)|
-now both the nodes will be in a line
-now keep incresing pointer of both the LL by 1 and check if they are same
-if same: that node is intersection node (Y) your answer
-if different: keep increasing pointers by 1


* APPROACH 4: Optimal - (temp1, temp2)
https://youtu.be/0DYoPz2Tpt4?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&t=1015

- keep incerasing the pointers of LL1, LL2
- after the last node of LL1,
- in the next iteration temp1 should point at head of LL2
- same thing of LL2 as well
- if temp1 == temp2: then that node is your answer
- if (temp1 == temp2 == NULL) then there doesn't exist any intersection point and both the LL are different
*/

//* SOLUTION - 3  Length Difference Solution
class Solution {
public:

    int len(ListNode*& head) {

        int len = 0;

        ListNode* temp = head;

        while (temp) {
            len++;
            temp = temp->next;
        }

        return len;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* A = headA;
        ListNode* B = headB;

        int lenA = len(headA);
        int lenB = len(headB);

        // skip the staring nodes
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) {
                A = A->next;
            }
        } else {
            int diff = lenB - lenA;
            while (diff--) {
                B = B->next;
            }
        }

        // when A, B are same nodes, then stop
        while (A != B && A != NULL) {
            A = A->next;
            B = B->next;
        }

        return A;
    }
};

//* SOLUTION 4 - 2 pointers
class Solution2 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;

    // keep moving both the pointers together until you find the Y
    // after last node of LL1, point ptr1 to head of LL2
		while(ptr1 != ptr2){
      
			if(ptr1 == NULL) ptr1 = headB;
			else             ptr1 = ptr1 -> next;
			
			if(ptr2 == NULL) ptr2 = headA;
			else             ptr2 = ptr2 -> next;
			
		}
		return ptr1;
	}
};

// SOLUTION 2 - HASHMAP
#include <unordered_map>
class Solution3 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

		unordered_map<ListNode*, int> m;

		while(headA != NULL){
			m[headA]++; // frequency
			headA = headA -> next;
		}

		while(headB != NULL){
			if(m[headB] > 0){ // 2nd time exploring, Y node
				return headB;
			}
			headB = headB -> next;
		}

		return NULL; // no intersection node
	}
};

