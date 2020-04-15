#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f(i,a,b) for(long long i=a;i<b;i++)
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define printarray(A) for(long long i=0; i<A.size() ; i++) cout<<A[i]<<" "; cout<<"\n";


struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

 bool mycomp(Interval a,Interval b){
     return a.start<b.start;
 }
 
vector<Interval> insert(vector<Interval> &old, Interval toadd) {
	vector<Interval> ans;
	old.pb(toadd);
	sort(old.begin(),old.end(),mycomp);
	ans.pb(old[0]);
	int n = old.size();
	f(i,1,n){
		//merging
		int anssize = ans.size()-1;
		if(old[i].start <= ans[anssize].end)
			if(old[i].end > ans[anssize].end){
				ans[anssize] =  old[i].end;
			}
			else ans[anssize] =  ans[anssize].end;
			
		else 
			ans.pb(old[i]);
	}

	return ans;

}


int main(){

	int n,a,b;
	cin>>n;
	struct Interval temp;
	vector<Interval> intervals;
	f(i,0,n){
		cin>>a>>b;
		temp = {a,b};
		intervals.pb(temp);

	}
	cin>>a>>b;
	temp = {a,b};
	vector<Interval> ans = insert(intervals,temp);
	
	f(i,0,ans.size()){
   		debug3(ans[i].start,ans[i].end,"");
	}
}

 