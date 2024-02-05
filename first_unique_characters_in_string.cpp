#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
        unordered_map<char,int>mp(26);
        for(auto it:s){
            mp[it]++;
        }
        int ans=-1;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1) {
                ans=i;
                break;
            }
        }
        return ans;
    }