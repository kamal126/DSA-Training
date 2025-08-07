#include<bits/stdc++.h>
using namespace std;

class SortedStack{
    public:
    stack<int>s;
    void sort();
};

void SortedStack :: sort(){

    stack<int>helper;

    while(s.empty()){
        int tmp = s.top(); s.pop();

        while(!helper.empty() && helper.top() < tmp){
            s.push(helper.top());
            helper.pop();
        }
        helper.push(tmp);
    }

    while(!helper.empty()){
        s.push(helper.top());
        helper.pop();
    }
}