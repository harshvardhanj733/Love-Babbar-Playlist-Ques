class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node* curr = root;
        while(curr != NULL){
            if(curr->left){
                Node* pred = curr->left;
                while(pred->right != NULL){
                    pred = pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

//TC: O(n);
//SC: O(1);