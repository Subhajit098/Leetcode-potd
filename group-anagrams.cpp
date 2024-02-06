#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            vector<string>ds;
            for(int i=0;i<it.second.size();i++){
                ds.push_back(it.second[i]);
            }
            ans.push_back(ds);
        }
        return ans;
    }