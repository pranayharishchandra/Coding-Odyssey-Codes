// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=remove-duplicates-from-a-sorted-doubly-linked-list
#include <vector>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
public:
    Node* removeDuplicates(struct Node* head) {
        
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* current = head;
        
        while (current->next != nullptr) {
            // duplicate node (curr and nextNode)
            // deleting the next node after curr, if same
            
            if (current->data == current->next->data) {
                
                Node* duplicate = current->next;
                current->next   = duplicate->next;
                
                if (current->next != nullptr)
                    current->next->prev = current;
                    
                delete duplicate;
                
            } else {
                current = current->next;
            }
        }

        return head;
    }
};