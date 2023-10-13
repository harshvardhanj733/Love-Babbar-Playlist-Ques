void dfs(int num, map<int, bool>& visited, map<int, list<int>> m, vector<int>& component){
    // if(visited[num]){
    //     return;
    // }

    component.push_back(num);
    visited[num] = true;
    for(auto i: m[num]){
        if(!visited[i])
            dfs(i, visited, m, component);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    
    //creating an adjacency matrix
    map<int, list<int>> m;
    for(int i = 0; i<edges.size(); i++){
        m[edges[i][0]].push_back(edges[i][1]);
        m[edges[i][1]].push_back(edges[i][0]);
    }

    //creating a visited map
    map<int, bool> visited;
    for(int i = 0; i<V; i++){
        visited[i] = false;
    }

    vector<vector<int>> ans;
    for(int i = 0; i<V; i++){
        if(!visited[i]){
        vector<int> component;
        dfs(i, visited, m, component);
        ans.push_back(component);
        }
        // if(component.size() > 0)
        //     ans.push_back(component);
    }

    return ans;
}