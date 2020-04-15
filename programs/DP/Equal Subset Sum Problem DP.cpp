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
        cin>>n;
        int arr[n];
        int sum = 0;
        f(i,0,n){
            cin>>arr[i];
            sum += arr[i];
        }
        if(sum%2 == 1){
            printf("NO\n");
            break;
        }
        bool dp[n+1][sum+1];
        //dp[i][j] = 1 if using 1-i elements we can generate a subset having sum = j
        f(i,0,n+1){
            f(j,0,sum+1){
                if(i==0) dp[i][j] = 0;
                else if(j==0) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i-1][j]; //excluding ith element
                    if(arr[i-1] <= j){
                        dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                    }
                }

            }
        }
        if(dp[n][sum/2] == true) printf("YES\n");
        else printf("NO\n");
    }
}
