 
#include<bits/stdc++.h>
using namespace std;

class RecentCounter {
    queue<int>q;    // to store the timestamps of recent calls
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t); //   add the new call timestamp to the queue
        
         // Remove timestamps that are older than t-3000 milliseconds
        
        while(!q.empty() && q.front()<t-3000){
            q.pop();
        }
        
        return q.size();
    }
};