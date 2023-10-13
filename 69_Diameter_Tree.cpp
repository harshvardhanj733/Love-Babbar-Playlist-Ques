//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
  
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left, right)+1;
    }
  
    // Function to return the diameter of a Binary Tree.
    
    pair<int, int> diameterFast(Node* root){
        if(root == NULL){
            pair<int, int> p;
            p.first = 0; p.second = 0;
            return p;
        }
        
        pair<int, int> ansLeft; pair<int, int> ansRight;
        ansLeft = diameterFast(root->left);
        ansRight = diameterFast(root->right);
        
        int op1 = ansLeft.first;
        int op2 = ansRight.first;
        int op3 = ansLeft.second + ansRight.second + 1;
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(ansLeft.second, ansRight.second) + 1;
        
        return ans;
    }
    
    int diameter(Node* root) {
        // Your code here
        // if(root == NULL){
        //     return 0;
        // }
        
        // int ansBoth = height(root->left) + height(root->right) + 1;
        
        // int ansLeft = diameter(root->left);
        // int ansRight = diameter(root->right);
        // if(root->left != NULL){
        //     ansLeft = height(root->left->left) + height(root->left->right) + 1;
        // }
        // if(root->right != NULL){
        //     ansRight = height(root->right->left) + height(root->right->right) + 1;
        // }
        
        // return max(ansLeft, max(ansRight, ansBoth));
        
        return diameterFast(root).first;
        
        
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends