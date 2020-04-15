#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

//brute force recursion code
// int edit(string s1,string s2,int i,int j){
//     if(i>=s1.length()) return (s2.length() - j);
//     else if(j>=s2.length()) return (s1.length() -i);

//     else if(s1[i] == s2[j]) return edit(s1,s2,i+1,j+1);
//     else{
//         //delete, insert and replace respecively
//         return 1 + min(edit(s1,s2,i+1,j), min( edit(s1,s2,i,j+1), edit(s1,s2,i+1,j+1) ) );
//     }
// }
int main(){
    int t,n,m;
    cin>>t;
    string s1,s2;
    while(t--){
        cin>>n>>m;
        cin>>s1>>s2;
        // cout<<edit(s1,s2,0,0)<<"\n";
        int dp[n+1][m+1];
        /* dp[i][j] means no of operations to make string s1 of length
        i and s2 of length j equal.*/
        f(i,0,n+1){
            f(j,0,m+1){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    //delete, insert,  replace
                    dp[i][j] = 1+ min(dp[i-1][j] , min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }

        cout<<dp[n][m];
    }

}
