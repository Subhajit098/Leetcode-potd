
//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    int helper(TreeNode* root,bool left_present){

        if(!root->left && !root->right) {
            return left_present ? root->val : 0;
        }

        int sum=0;

        if(root->left) sum+=helper(root->left,true);
        
        if(root->right) sum+=helper(root->right,false);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root,false);
    }

    
};