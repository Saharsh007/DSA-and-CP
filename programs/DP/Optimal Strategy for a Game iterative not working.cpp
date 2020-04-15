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
        f(i,0,n){
            cin>>arr[i];
        }
        int dp[n][n];
        // dp[i][j] = max value that can be choosen from elements from i-j;


        f(i,0,n){
            f(j,0,n){
                //not possible case
                if(i>j) dp[i][j] = 0;
                //both are the same so , no option but to select the only one element
                else if(i == j) dp[i][j] = arr[i];
                //only 2 element , choose the max one
                else if(i == j-1) dp[i][j] = max(arr[i],arr[j]);
                //for further processing this is needed
                else dp[i][j] = -1;
            }
        }

        f(i,0,n){
            f(j,0,n){
                if(dp[i][j] == -1){

                    int op1 = 0, op2 = 0, op3 = 0;
                    if(j-1 >= 0 && i+1 <= n-1)
                        op1 = dp[i+1][j-1];
                    if(i+2 <= n-1)
                        op2 = dp[i+2][j];
                    if(j-2 >= 0)
                        op3 = dp[i][j-2];
                    
                    dp[i][j] = max(arr[i]+min(op1,op2) , arr[j]+min(op1,op3) );
                    // this is equivalnent to 
                    //dp[i][j] = max(arr[i] + min(dp[i+1][j-1],dp[i+2][j]) , arr[j] + min(dp[i+1][j-1],dp[i][j-2]))
                }
                 
            }
        }
        cout<<dp[0][n-1]<<"\n";
        f(i,0,n){
            cout<<"\n";
            f(j,0,n){
                cout<<dp[i][j]<<"\t";
            }
        }

    }
        
}
/*
Wrong Answer. !!!Wrong Answer

Possibly your code doesn't work correctly for multiple test-cases (TCs).

The first test case where your code failed:

Input:
42
4993 4883 8894 7241 1476 8226 1207 5674 6967 6766 8371 1467 3169 2228 297 288 4300 4194 4689 1155 3934 5209 4342 2916 2808 2067 5467 8012 1855 1894 2684 9266 5705 3578 4775 578 1546 216 395 7883 720 9476

Its Correct output is:
93217

And Your Code's output is:
9475
*/