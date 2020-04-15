#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)


int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        int sum = 0;
        f(i,0,n){
            cin>>arr[i];
            sum += arr[i];
        }
        bool dp[n+1][sum+1];
        //dp[i][j] = 1 if using 1-i elements we can generate a subset having sum = j
        f(i,0,n+1){
            f(j,0,sum+1){
                if(i==0 && j!=0) dp[0][j] = 0;
                else if(j==0) dp[i][0] = 1;
                else {
                    dp[i][j] = dp[i-1][j]; //excluding ith element
                    if(arr[i-1] <= j){
                        dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
                    }
                }

            }
        }
        for(int val = sum/2; val>=0; val--){
            // debug4(sum,sum/2,val,dp[n][val]);

            if(dp[n][val]){
                //answer
                cout<<sum-2*val<<"\n";
                break;
            }
        }
    }
}
