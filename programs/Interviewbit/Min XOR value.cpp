#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(long long i=a;i<b;i++)

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans = INT_MAX;
    f(i,0,A.size()-1){
       
            ans = min(ans,A[i]^A[i+1]);
    }
    return ans;
}
