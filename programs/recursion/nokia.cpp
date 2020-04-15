#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

int m,n,maxused = n;
int checkforall(int start,int end,int val){
    if(start <= 0 || end>n)  return 0;
    f(j,start,end+1){
        int temp1 = val + end-start + checkforall(start,j-1,val) + checkforall(j+1,end,val);
        if(m - temp1 >= 0 && m- temp1 < val) ans = m-temp1;
    }
} 

int main(){

    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        f(i,1,n+1){
            int temp =  n + checkforall(1,i-1,n) + checkforall(i+1,n);
            if(m - temp >=0 && temp > maxused) maxused = temp;
        }
    }
}
