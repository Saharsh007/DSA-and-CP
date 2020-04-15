#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"

void prettyPrint(int A) {
    
    vector<vector<int>> ans(2*A-1);
    int n = 2*A-1;
    f(i,0,n){
        f(j,0,n){
            ans[i].pb(0);
        }
    }
    
    f(i,0,A){
        f(j,i,n-i){
        	debug3(i,j,n-i);
            ans[i][j] = A-i;
            ans[j][i] = A-i;
            ans[n-i-1][j] = A-i;
            ans[j][n-i-1] = A-i;
        }
    }

    f(i,0,n){
    	cout<<"\n";
    	f(j,0,n){
    		cout<<ans[i][j]<<" ";
    	}
    }
    
}
int main(){

    int n;
    cin>>n;
    prettyPrint(n);

}

 