#include<bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        if(n==0) return 0;
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0]) return 0;

        int score=0,maxi=INT_MIN;
        int left=0,right=n-1;
        while(left<=right){
            if(power>=tokens[left]){
                score+=1;
                power-=tokens[left];
                left++;
                maxi=max(maxi,score);
            }
            else if(power<tokens[left] && score>0){
                score-=1;
                power+=tokens[right];
                right--;
            }
            else break;
        }
        return maxi;
    }