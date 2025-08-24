#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


void QueueStack ::push(int x) {
    // code here
    if(q1.empty()){
        q2.push(x);
    }else{
        q1.push(x);
    }
}

int QueueStack ::pop() {
    int val = -1;
    
    if(q1.empty() && q2.empty()) return val;
    else if(q1.empty()){
        while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
        val = q2.front();
        q2.pop();
        return val;
    }else if(q2.empty()){
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        val = q1.front();
        q1.pop();
        return val;
    }
}