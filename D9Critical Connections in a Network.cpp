// Problem Link
// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    // 1st Approach ==>we'll go through all the connections and assume that a connection let say [0,1] is not there,then we'll try to find out how many nodes we can reach now. If reachable no. of nodes are equal to the n nodes then, that connection which we removed is not a critical connection otherwise that's a critival connection
    
    // 2nd Approach ==> Tarjan's Algorithm
    vector<vector<int>> bridges;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>> &adj) {
    vis[node] = 1; //marking as vis
    tin[node] = low[node] = timer++;//at each dfs call both will incre acc to timer 
    for(auto it: adj[node]) {
        if(it == parent) continue;//skip adj parent node
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); //incre vals till we gode down
            low[node] = min(low[node], low[it]); //min of neighbour
            if(low[it] > tin[node]) { //cond to be a bridge
                bridges.push_back({node,it});//taking in ans
            }
        } else {//when not visited
            low[node] = min(low[node], tin[it]); 
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>>adj(n);
        for(int i=0;i<c.size();++i)   //Make Adj list
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        vector<int> tin(n, -1);//time of insertion at dfs
        vector<int> low(n, -1);//lowest time of insertion
        vector<int> vis(n, 0); 
        int timer = 0; 
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj); //init parent -1
            }
        }
        return bridges;
    }
};
