#include <vector>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

/*
 -> you may use "&&" "and"

 *> if you are given: Node** head_ref => just extract head from it => Node* head = (*head_ref); => and solve normally.

 *> don't use dummy in DDL for CRUD operations 
 since prev of head does exist i.e. NULL which helps handling corner cases realated to head which occured in Single LinkedList
*/


// solution 1 - wrong
class wrong_Solution_DontUseDummyInDDL {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        
        Node* head = (*head_ref);

        if (head==NULL) return ;

        // adding dummy node in front, since delete (CRUD) operations involved
        Node* dummy = new Node (0);
        head -> prev = dummy;
        dummy-> next = head;
        head = dummy;
        
        // iterating over LL and deleting nodes
        Node* temp = head->next; // means original head, after skipping dummy

        while(temp!=NULL){
          if (temp -> data == x) {
            // delete the temp node
            temp -> prev = temp -> next;
            temp -> next = temp -> prev;
          }
          temp = temp -> next;
        }

        // deleting dummy node
        head = dummy -> next;
        dummy -> next = NULL; // unlink dummy

        if (head == NULL)
        head -> prev = NULL; // unlink head with dummy

        delete dummy;
    }
};


// solution 2 - wrong
class wrong_Solution_segmentation_fault {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        if (temp == NULL) return;

        while (temp != NULL) {
            if (temp->data == x) {
                if (temp->prev) temp->prev->next = temp->next; // Adjust previous node's next pointer
                if (temp->next) temp->next->prev = temp->prev; // Adjust next node's previous pointer
                Node* deleteMe = temp;
                temp = temp->next;
                free(deleteMe);
            } else {
                temp = temp->next;
            }
        }
    }
};

// solution 1 - correct implementation of solution 2
// using current and NextNode (NextNode for better code readability & deletion of current)
class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* current = *head_ref;
        Node* nextNode;

        while (current != NULL) {

            nextNode = current->next;

            if (current->data == x) {
                if (current == *head_ref) //* NOTE: VIMP: If the node to delete is the head
                    *head_ref = nextNode;

                if (current->prev) current->prev->next = nextNode; // Adjust previous node's next pointer

                if (nextNode) nextNode->prev = current->prev; // Adjust next node's previous pointer

                delete current; // Delete the node
            }
            current = nextNode;
        }
    }
};
