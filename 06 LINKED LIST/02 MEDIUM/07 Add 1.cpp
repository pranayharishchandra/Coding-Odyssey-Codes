// https://youtu.be/aXQWhbvT3w0?list=PLgUwDviBIf0rAuz8tVcM0AymmhTRsfaLU&t=1503
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

*approach 1: iterative (2 times reverse)
since when adding you need to go from once digit to 10s, 100s and so on. 

-hence we must reverse the LL in-order to do that.
-then it’s just simple, add 2 numbers (carry, temp)
-again reverse LL and return head



*approach 2: Recursion - backtracking (no reverse)
as in iterative solution we are reversing the List 2 times
it increases the time complexity
though the space complexity is O(1)

but as we need to reverse to times
going head to tail
then again coming from tail to head

we can use backtracking, keeping “carry” as variable to update the data in nodes of the LL from 1s, 10s, 100s,… or tail to head

while backtracking we can update the nodes
*/


//* SOLUTION 2 - bactracking
class Solution {
  //* This function will return what was extra in prev node i.e.carry
  int addHelper(ListNode *temp)
  {
    //* ADD 1 to the once digit (tail) return 1 (means carry 1)
    if (temp == NULL){
      int carry = 1;
      return carry;
    }

    int carry = addHelper(temp->next);

    // NOW adding 1 while backtracking
    temp->data += carry;           // add carry to current
    if (temp->data < 10) return 0; // if it's still less than 10 (nothing to carry for next)
    temp->data = (temp->data) % 10;// 0 always, as we are adding 1, (9 -> 10)
    return carry;                  // 1 always, since we are adding 1, max value of cartry can be 1 (9 -> 10)
  }

public:
  ListNode *addOne(ListNode *head)
  {
    int carry = addHelper(head);

    //* if there is some carry still left then we need to create a new node to add carry
    if (carry > 0)
    {
      ListNode *newNode = new ListNode(carry);
      newNode->next = head;
      head = newNode;
      return head;
    }
  }

};