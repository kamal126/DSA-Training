#include<bits/stdc++.h>
using namespace std;

class StackQueue{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
};

void StackQueue::push(int B) {
    if(s1.empty()) s2.push(B);
    else s1.push(B);
}

int StackQueue::pop() {
    int val = -1;
    
    if(s1.empty() && s2.empty()) return -1;
    else 
        if(s1.empty()){
            while(s2.size()>1){
                s1.push(s2.top()); s2.pop();
            }
            val = s2.top(); s2.pop();
        }else if(s2.empty()){
            while(s1.size()>1){
                s2.push(s1.top()); s1.pop();
            }
            val = s1.top(); s1.pop();
        }
    return val;
}