#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

//recursion way
int countways(int n){
    if(n < 0) return 0;
    else if(n == 0) return 1;
    else return countways(n-1) + countways(n-2) + countways(n-3);
}

int main(){
    int t,n,w;
    int dp[51];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    f(i,4,51) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    cin>>t;

    while(t--){
        cin>>n;
        cout<<dp[n]<<"\n";
        // cout<<countways(n)<<"\n";

    }
}
