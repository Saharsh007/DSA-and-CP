#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"

void solve(int A) {
    vector<vector<int>> ans(A);
    if(A == 0) return ;
    int n = A;
    f(i,1,n+1){
        
        f(j,1,i+1){
            ans[i-1].pb(0);
        }
    }
    ans[0][0] = 1;
    if(A == 1) { cout<<"1"; return ;}
    ans[1][0] = 1;
    ans[1][1] = 1;
    if(A == 2) {cout<<"1\n1 1\n"; return ;}
    
    f(i,2,n){
        ans[i][0] = 1;
        ans[i][i] = 1;
    }
    
    f(i,2,n){
        f(j,1,i){
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1]; 
        }
    }
    
    f(i,0,n){
    	cout<<"\n";
    	f(j,0,i+1){
    		cout<<ans[i][j]<<" ";
    	}
    }
    
}



int main(){

    int n;
    cin>>n;
    
    solve(n);
    // f(i,0,n){
    // 	cout<<"\n";
    // 	f(j,0,i+1){
    // 		cout<<ans[i][j]<<" ";
    // 	}
    // }
}

 