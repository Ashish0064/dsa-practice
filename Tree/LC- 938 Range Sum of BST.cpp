/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int summ(TreeNode* root, int l, int h){
        if(root == NULL){
            return 0;
        }

        int left = summ(root->left,l,h);
        int right = summ(root->right,l,h);
        int sum = 0;
        if(root->val >=l && root->val <= h){
            sum += root->val;
        }

        return sum+left+right;
    }


    int rangeSumBST(TreeNode* root, int low, int high) {
        return summ(root,low,high);
    }
};