class Solution {
public:
     //here topological order represents the topological order of the DAG
    //If it is not a DAG ,let us say A directed graph with cycles then 
    //there topological ordering is not possible and topological_order here 
    //contains the nodes leaving the nodes present in cycle .
    //This topological ordering represents a path through which each node is visited once.
    bool cycle_detect(int n, vector<int> &topological_order, vector<vector<int> > &adj) {
        vector<int> degree(n, 0);
        for (vector<int> p: adj)
            for(int node: p)
                degree[node]++;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) 
        {
            int curr = q.front(); q.pop(); n--;
            topological_order.push_back(curr);
            for (auto next: adj[curr])
                if (--degree[next] == 0) q.push(next);
        }
        return n == 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        vector<int> topologicalOrder;
        vector<vector<int> > adj(numCourses);
        for(vector<int> v: prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        if(!cycle_detect(numCourses, topologicalOrder, adj))
            return vector<int>(0);
        return topologicalOrder;
    }
};
