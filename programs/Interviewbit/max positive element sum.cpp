#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"


vector<int> maxset(vector<int> &A) {
    ll sum=0,max_sum=INT_MIN;
    vector<int> ans,final_ans;
    f(i,0,A.size()){
        if(A[i]>=0){ 
            sum+= A[i];
            ans.pb(A[i]);
            // debug3(A[i],ans.size(),sum);
        }
        else{
            ans.clear();
            sum = 0;
        }
        if(max_sum < sum){
	        max_sum = sum;
	        final_ans.clear();
	        final_ans.assign(ans.begin(), ans.end()); 
        }
        if(max_sum == sum && ans.size() > final_ans.size()){
	        final_ans.clear();
	        final_ans.assign(ans.begin(), ans.end());	
        }
    }
    
    return final_ans;
}



int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    f(i,0,n){
    	cin>>v[i];
    }
    vector<int> ans = maxset(v);
    f(i,0,ans.size()){
    	cout<<ans[i];
    }
}

 