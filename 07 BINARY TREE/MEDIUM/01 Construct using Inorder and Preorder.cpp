#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int data;
  TreeNode * left;
  TreeNode * right;

  TreeNode (int data) {
    this -> data = data;
    left = NULL;
    right = NULL;
  }
};

class Solution {
private:
    int search(vector<int> & arr, int key) {
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == key) 
                return i;
        }
        return -1; // dummy value, never executed
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end, int* idx) {

        if (start > end) // not a node
            return NULL;
            
        *idx = *idx + 1;
        TreeNode* node = new TreeNode(preorder[*idx]);

        if (start == end) // you are on the leaf node
            return node;
        
        int pos = search(inorder, preorder[*idx]);

        // root of left Subtree, then merget that with node (i.e. root of the Tree)
        TreeNode* leftSubtreeRoot  = build(preorder, inorder, start  , pos - 1, idx );
        TreeNode* rightSubtreeRoot = build(preorder, inorder, pos + 1, end    , idx );

        node -> left  = leftSubtreeRoot;
        node -> right = rightSubtreeRoot;

        return node;
    }
     
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = -1;
        TreeNode* root = build(preorder, inorder, 0, preorder.size() - 1, &idx);
        return root;
    }
};