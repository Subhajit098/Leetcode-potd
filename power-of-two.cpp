#include<bits/stdc++.h>
using namespace std;


// Method 1 , TC: O(log(n)), SC: O(1)
bool isPowerOfTwo(int n) {
        // 15 ->0   16 ->10000
        // 2->10, 4->100, 8-> 1000, 9-> 10000
        // x-> 
        if( n==0 ) return false;
        if(n==1) return true;
        bool neg=false;
        long long N=(1ll)*n;
        // n=(1ll)*n;
        if(N<0) {
            N*=-1;
            neg=true;
        }
        int count=0,last=-1,pos=0;
        while(N){
            last=N&1;
            pos++;
            if(last) count++;
            N=N>>1;
        }
        if(last==1 & count==1) {
            if(!neg) return 1;
            else if(pos%2==1 && neg){
                 return 0;
            }
        }
        return 0;
    }


// Method 2 , TC: O(1)  , SC: O(1)
bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(n-1)==0);
    }