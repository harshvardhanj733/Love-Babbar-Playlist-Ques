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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> ans;
        if(root == NULL){
            return res;
        }

        queue<TreeNode*> q;
        bool flag = true;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            if(t == NULL){
                if(q.size() > 0){
                    q.push(NULL);
                }
                if(flag == true){
                    res.push_back(ans);
                    flag = false;
                }
                else{
                    reverse(ans.begin(), ans.end());
                    res.push_back(ans);
                    flag = true;
                }
                ans.clear();
            }
            else{
                ans.push_back(t->val);
                if(t->left != NULL){
                    q.push(t->left);
                }
                if(t->right != NULL){
                    q.push(t->right);
                }
            }
        }

        return res;
    }
};

//TC: O(n);
//SC: O(n);