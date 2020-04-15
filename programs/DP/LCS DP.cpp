#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

int n,m,ans = 0;


//recursive brute force
int match(string A, string B, int i, int j){
    if(i>=n || j>=m) {
        // ans = max(ans,val);
        return 0;
    }
    if(A[i] == B[ j]) {
        return 1+match(A,B,i+1,j+1);
    }
    else{
        return max(match(A,B,i+1,j) , match(A,B,i,j+1) );
        // match(A,B,i++,j++,val);
    }
}

int main(){
   
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;

    // ans = match(a,b,0,0);
    // cout<<ans;
    int dp[n+1][m+1];
    //dp[i][j] means till jth character of B and ith character of A , max subsequence that matches
    f(i,0,n+1){
        f(j,0,m+1){
            if(i==0 || j==0) dp[i][j] = 0;
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
            }
        }
    }
    cout<<dp[n][m]<<"\n";
  }

}
