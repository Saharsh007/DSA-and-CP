#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define mod 1000000007
int Solution::hammingDistance(const vector<int> &A) {
    
    ll ans = 0,count = 0,n = A.size();
    f(i,0,31){
        count = 0;
        f(j,0,n){
            if( A[j]&(1<<i)){
                count++;
            }
        }
        // count elements have same bit
        // n-count have different 
        ans += (count*(n - count)*2) % mod;
    }
    return (int)ans;
}
