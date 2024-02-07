#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,char>a,pair<int,char>b){
        if(a.first!=b.first) return a.first>b.first;
        return true;
    }

    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        string ans="";
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pair<int,char>New=make_pair(it.second,it.first);
            pq.push(New);
        }

        while(pq.size()){
            int x=pq.top().first;
            char c=pq.top().second;
            while(x--){
                ans+=c;
            }
            pq.pop();
        }
        return ans;
    }