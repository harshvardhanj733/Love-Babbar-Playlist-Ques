vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    map<int, list<int>> adjList;
    for(int i = 0; i < m; i++){
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    vector<vector<int>> res;
    vector<int> temp;

    for(int i = 0; i < n; i++){ // 4 -> 3   [[4 3], [1 2], [0 3], [2 3]]
        temp.clear();           // 1 -> 2
        temp.push_back(i);      // 0 -> 3
        for(auto j: adjList[i]){// 2 -> 3 
            temp.push_back(j);
        }
        res.push_back(temp);
    }

    return res;
}