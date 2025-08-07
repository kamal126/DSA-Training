#include<bits/stdc++.h>
using namespace std;

bool pairWiseConsecutive(stack<int> s) {
    if(s.size()%2!=0) s.pop();

    while(s.size()>1){
        int x = s.top(); s.pop();
        int y = s.top(); s.pop();

        if(abs(x-y)!=1) return false;
    }

    return true;
}

// Second Approach 

bool pairWiseConsecutive(stack<int> s) {
    stack<int> temp;

    while(s.size() > 1) {
        int x = s.top(); s.pop();
        int y = s.top(); s.pop();

        if(abs(x - y) != 1) return false;

        temp.push(x);
        temp.push(y);
    }

    // Original stack remains unchanged since passed by value
    return true;
}
