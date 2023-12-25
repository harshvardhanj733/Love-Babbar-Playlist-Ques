/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int pre = -1, suc = -1;
    TreeNode* node = root;
    
    while(node != NULL && node->data != key){
        if(node->data > key){
            suc = node->data;
            node = node->left;
        }
        else{
            pre = node->data;
            node = node->right;
        }
    }

    TreeNode* left = NULL;
    if(node != NULL){
        left = node->left;
    }
    while(left != NULL){
        pre = left->data;
        left = left->right;
    }

    TreeNode* right = NULL;
    if(node != NULL){
        right = node->right;
    }
    while(right != NULL){
        suc = right->data;
        right = right->left;
    }

    return {pre, suc};
}

//TC: O(n);
//SC: O(1)