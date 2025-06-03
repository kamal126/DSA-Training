/**
 * @author: Kamal Chandra
 */

#include<bits/stdc++.h>
using namespace std;
    // 1. Create Ajcency List
    // 2. Apply Khan Algotithm (BFS topological Sort)
        // 1. Find Indeg of each node
        // 2. all 0 Indegree node push in queue
        // 3. while queue not empty Solve.....
    bool isPossible(int N, int P, vector<pair<int, int> >& pre) {
        // Code here
        vector<int>adj[N];
        vector<int>InDeg(N,0);
        
        for(int i=0;i<P;i++){
            adj[pre[i].second].push_back(pre[i].first);
            InDeg[pre[i].first]++;
        }
        queue<int>q;
        // khan algorithm
        for(int i=0;i<N;i++)
            if(!InDeg[i])
                q.push(i);
        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(int i=0;i<adj[node].size();i++){
                InDeg[adj[node][i]]--;
                
                if(!InDeg[adj[node][i]])
                    q.push(adj[node][i]);
            }
            
        }
        
        return count == N;
    }