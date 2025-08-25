#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pb(deque<int>& dq, int x) {
        dq.push_back(x);
        
    }

    void ppb(deque<int>& dq) {
        if(!dq.empty()) dq.pop_back();
    }

        
    int front_dq(deque<int>& dq) {
        if(!dq.empty()) return dq.front();

        return -1;
    }
        

    void pf(deque<int>& dq, int x) {
        dq.push_front(x);
    }
};


/*class Solution {
  public:
    void pb(deque<int>& dq, int x) {
        // code here
        
    }

    void ppb(deque<int>& dq) {

        
        // code here
    }

        
    int front_dq(deque<int>& dq) {
        // code here
    }
        

    void pf(deque<int>& dq, int x) {
        // code here
    }
};*/