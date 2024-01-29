#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(!s1.size()){
            s1.push(x);
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        if(s1.size()) {
            int x= s1.top();
            s1.pop();
            return x;
        }

        return 0;
    }
    
    int peek() {
        if(s1.size()) return s1.top();
        return 0;
    }
    
    bool empty() {
        if(s1.size()) return false;
        return true;
    }

};