#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

int n;

int traverse(int i,int j,int sum,int *arr){
    if(i==n-1) return sum;
    if(i<n-1 && j<n && *((arr+(i+1)*n) + j) > *((arr+i*n) + j) ){
        traverse(i+1,j,sum + *((arr+(i+1)*n) + j), arr);
    } 
    else if(i<n-1 && j<n-1 && *((arr+(i+1)*n) + j+1) > *((arr+i*n) + j) ){
        traverse(i+1,j+1,sum + *((arr+(i+1)*n) + j+1), arr);
    } 
    else if(i<n-1 && j>0 && *((arr+(i+1)*n) + j-1) > *((arr+i*n) + j) ){
        traverse(i+1,j-1,sum + *((arr+(i+1)*n) + j-1), arr);
    } 

}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n][n];
        f(i,0,n){
            f(j,0,n){
                cin>>arr[i][j];
            }
        }
        int maxans = 0;
        f(i,0,n){
            f(j,0,n){
               int ans = traverse(i,j,arr[i][j],(int *)arr);
               maxans = max(ans,maxans); 
            }
        }
        cout<<maxans<<"\n";        
    }   
}
