#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define printarray(A) for(long long i=0; i<A.size() ; i++) cout<<A[i]<<" "; cout<<"\n";

void solve(vector<int> &A) {
    int n = A.size();
    f(i,0,n){
    		A[i] += (A[A[i]]%n)*n;
    		// A[A[i]] = A[i]
    	}
 

    
    f(i,0,n){
    		A[i] /=n;
    }
 }


int main(){

	int n;
	cin>>n;
	vector<int> v(n);
	f(i,0,n){
		cin>>v[i];
	}
	 solve(v);
	// cout<<ans.size();
	printarray(v);
}	

 