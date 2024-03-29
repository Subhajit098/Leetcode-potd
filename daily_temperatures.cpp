#include<bits/stdc++.h>
using namespace std;


vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (st.size() == 0) {
                ans.push_back(0);
            } else {

                while (st.size() != 0 && st.top().first <= temperatures[i])
                    st.pop();
                // maybe the stack becomes empty
                if (st.size() == 0)
                    ans.push_back(0);
                else
                    ans.push_back(st.top().second - i);
            }
            st.push({temperatures[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }