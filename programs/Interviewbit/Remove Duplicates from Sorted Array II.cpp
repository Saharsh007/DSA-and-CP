#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)

int Solution::removeDuplicates(vector<int> &A) {
    if(A.size() == 0 ) return 0;
    vector<int> ans;
    int n = A.size(),count = 1;
    ans.pb(A[0]);
    f(i,1,n){
        if(A[i] == ans[ans.size()-1]){
            if(count >= 1 ) 
                count++;
        }
        else {
            if(count > 1){
                ans.pb(ans[ans.size()-1]);
                count = 0;
            }

            ans.pb(A[i]);
            count = 1;
            
        }
                // debug4(i,A[i],ans[ans.size()-1],count);
    }

    if(count  > 1 ) 
        ans.pb(ans[ans.size()-1]);        
    A = ans;
    return ans.size();
}