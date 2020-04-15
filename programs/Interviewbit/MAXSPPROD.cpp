#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define mod 1000000007

int Solution::maxSpecialProduct(vector<int> &A) {
    vector<ll> l,r;
    ll  n = A.size();

    stack<ll> temp;
    f(i,0,n){
        while(!temp.empty() && A[temp.top()] <= A[i]){
            temp.pop();
        }
        if(temp.empty())
            l.pb(0);
        else
            l.pb(temp.top());
        temp.push(i);
    }
    while(!temp.empty()) temp.pop();

    for(ll i= n-1;i>=0;i--){
        while(!temp.empty() && A[temp.top()] <= A[i]){
            temp.pop();
        }
        if(temp.empty())
            r.pb(0);
        else
            r.pb(temp.top());
        temp.push(i);
    }
    reverse(r.begin(),r.end());

    // debug3(l.size(),r.size(),"hey");
    ll ans = INT_MIN;
    f(i,0,n){
        ans = max(ans,l[i]*r[i]);
    }
    // printarray(l);
    // printarray(r);
    return ans;

}