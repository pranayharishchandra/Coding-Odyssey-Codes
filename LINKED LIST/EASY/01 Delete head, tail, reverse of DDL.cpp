#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *back;

  Node(int data1, Node *next1, Node *back1) {
    data = data1;
    next = next1;
    back = back1;
  }

  Node(int data1) {
    data = data1;
    next = nullptr;
    back = nullptr;
  }
};

Node *convertArr2DLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void print(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
}

Node *deleteHead(Node *head) {
  if (head == nullptr || head->next == nullptr) 
    return nullptr;
  
  Node *prev = head;
  head       = head->next;
  head->back = nullptr;
  prev->next = nullptr;

  delete prev;
  return head;
}

Node *deleteTail(Node *head) {
  if (head == nullptr || head->next == nullptr) 
    return nullptr;
  
  Node *tail = head;
  while (tail->next != nullptr) 
    tail = tail->next;
  
  Node *newTail = tail->back;
  newTail->next = nullptr;
  tail->back = nullptr;

  delete tail;
  return head;
}

// ==================== REVERSE DDL ===================
// SOLUTION - 1: BRUTE (STACK) 
// Time Complexity : O(2N) During the first traversal, 
//                   each node's value is pushed into the stack once, which requires O(N) time
// Space Complexity : O(N) This is because we are using an external stack data structure. 
Node* reverseDLL(Node* head){
    if(head==NULL || head->next == NULL)
        return head;
    
    stack<int> st;
    Node* temp = head;
    
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    
    return head;
} 


// SOLUTION 2 : REVERSING POINTERS (swapping "back" and "next")
// Time Complexity : O(N) We only have to traverse the doubly linked list once, 
//                   hence our time complexity is O(N).
// Space Complexity : O(1), as the reversal is done in place.

Node* reverseDLL(Node* head) {
    if (head == NULL || head->next == NULL) 
        return head; 
    
    
    Node* prev = NULL;  
    Node* current = head;   

    while (current != NULL) {
        prev          = current->back; 
        current->back = current->next; 
        current->next = prev;          
        current       = current->back; 
    }
    
    return prev->back;
}



