 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy1(vector<int>& tickets, int k) {
        queue<pair<int, int>>q;

        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i], i});
        }

        int timer=0;
        while(!q.empty()){
            int val = q.front().first;
            int idx = q.front().second;
            q.pop();
            val--, timer++;
            if(idx==k && val==0) return timer;
            else if(val){
                q.push({val, idx});
            }
        }

        return timer;
    }

    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timer=0;
        for(int i=0;i<=k;i++){
            timer += min(tickets[i], tickets[k]);
        }
        for(int i=k+1;i<tickets.size();i++){
            timer += min(tickets[i], tickets[k]-1);
        }

        return timer;
    }
};