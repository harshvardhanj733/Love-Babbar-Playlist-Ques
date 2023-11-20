class Solution {
  public:
  
    void traverse(Node* root, map<Node*, Node*>& m, int target, Node* tar){
        if(root == NULL){
            return;
        }
        
        if(root->data == target){
            tar = root;
        }
        
        m[root->left] = root;
        m[root->right] = root;
        
        traverse(root->left, m, target, tar);
        traverse(root->right, m, target, tar);
    }
  
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //s1: find parents for each node;
        //s2: find the target node;
        map<Node*, Node*> parents;
        parents[root] = NULL;
        Node* tar = NULL;
        traverse(root, parents, target, tar);
        
        //s3: create a visited map and a queue;
        map<Node*, bool> visited;
        queue<pair<Node*, int>> q;
        
        //s4: push tar in queue and set it as visited;
        q.push({tar, 0});
        visited[tar] = true;
        
        //s5: iterate while q is not zero.
        int time = 0;
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node* node = p.first;
            int t = p.second;
            time = max(time, t);
            
            if(node->left != NULL && !visited[node->left]){
                q.push({node->left, t + 1});
                visited[node->left] = true;
                // time = max(time, t+1);
            }
            if(node->right != NULL && !visited[node->right]){
                q.push({node->right, t + 1});
                visited[node->right] = true;
                // time = max(time, t+1);
            }
            if(parents[node] != NULL && !visited[parents[node]]){
                q.push({parents[node], t + 1});
                visited[parents[node]] = true;
                // time = max(time, t+1);
            }
        }
        
        return time;
    }
};

//TC: O(n);
//SC: O(n);