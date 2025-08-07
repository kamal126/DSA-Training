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