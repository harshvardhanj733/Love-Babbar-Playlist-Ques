#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
void traverse(vector<int>& elements, BinaryTreeNode<int>* root){
    if(root != NULL){
        traverse(elements, root->left);
        elements.push_back(root->data);
        traverse(elements, root->right);
    }
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> elements;
    traverse(elements, root);

    int i = 0, j = elements.size() - 1;
    while(i < j){
        if(elements[i] + elements[j] == target){
            return true;
        }
        else if(elements[i] + elements[j] < target){
            i++;
        }
        else{
            j--;
        }
    }

    return false;
}

//TC: O(n);
//SC: O(n);