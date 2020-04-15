#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)




int main(){
    int t,n,w;
    cin>>t;
    while(t--){
        cin>>n>>w;
        vector<pair<int,int> > v(n);
        f(i,0,n) cin>>v[i].second;
        f(i,0,n) cin>>v[i].first;
        sort(v.begin(),v.end());
        // f(i,0,n){
        //     cout<<v[i].first<<" "<<v[i].second<<"\n";
        // }
        //first is weight and second is value
        int dp[n+1][w+1];

        f(i,0,n+1){
            f(j,0,w+1){
                if(i==0 || j == 0) dp[i][j] = 0;
                else if(v[i].first > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(v[i-1].second + dp[i-1][j- v[i-1].first] , dp[i-1][j]);
                }
            }
        }
        cout<<dp[n][w]<<"\n";
    }

    
}
