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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBSTHelper(const vector<int>& nums, int start, int end) {

        if (start > end) 
            return nullptr;
        
        int mid = start + (end - start) / 2;

        // middle element will be root
        TreeNode* root = new TreeNode(nums[mid]);

        // smaller elements of the mid will be part of it's left subtree
        root->left  = sortedArrayToBSTHelper(nums,   start, mid - 1);
        // elements right of mid, will be paret of right subtree
        root->right = sortedArrayToBSTHelper(nums, mid + 1,     end);

        return root;
    }
};