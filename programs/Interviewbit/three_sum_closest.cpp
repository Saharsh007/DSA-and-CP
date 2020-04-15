#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define ll long long 
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define printarray(A) for(long long i=0; i<A.size() ; i++) cout<<A[i]<<" "; cout<<"\n";
#define mod 1000000007

#define debug5(a,b,c,d,e) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"->"<<e<<"\n";


int threeSumClosest(vector<int> &A, int B) {
    int n = A.size(),closest=100000000,sum=0;
    if(A.size()==3) return A[0]+A[1]+A[2];
    sort(A.begin(),A.end());
    
    f(i,0,n-2){
        int l = i+1,r = n-1;
        while(l<r){
            sum = A[i]+A[l]+A[r];
            // debug5(abs(B-sum),abs(B-closest),i,l,r);
            if( abs(B-sum) < abs(B-closest)){
                closest = sum;
            }
            
            if(sum > B)
                r--;
            else
                l++;
        }
    }
    return closest;
}


int main(){

	int n;
	cin>>n;
	vector<int> v(n);

	f(i,0,n) 
		cin>>v[i];
	
	int val;
	cin>>val;

	// cout<<search(v,val,0,n-1);
	cout<<threeSumClosest(v,val);
	// printarray(ans);
}	

 