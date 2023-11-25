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
private:
    bool isBST(TreeNode* root, long long l, long long r){
        if(root == NULL){
            return true;
        }

        if(root->val <= l || root->val >= r){
            return false;
        }

        return isBST(root->left, l, root->val) && isBST(root->right, root->val, r); 

    }
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, 1LL*INT_MIN - 1, 1LL*INT_MAX + 1);
    }
};

//TC: O(n);
//SC: O(n);