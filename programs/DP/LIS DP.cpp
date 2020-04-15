#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

int n;
int LIS(int arr[],int lastmax,int index){
    if(index >= n) return 0;
    if(arr[index]>lastmax){
        return max(1+LIS(arr,arr[index],index+1) , LIS(arr,lastmax,index+1));
    }
    else return LIS(arr,lastmax,index+1);
}

int main(){
   
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        f(i,0,n) cin>>arr[i];
        int dp[n];
        //1 means include and 0 is exclude
        // dp[0] = 0;
        int lastmax=INT_MIN;
        dp[0] = 1;
        f(i,0,n){
            dp[i] = 1;
            f(j,0,i){
                if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
        }
        cout<<*max_element(dp, dp + n)<<"\n";

    }
}
