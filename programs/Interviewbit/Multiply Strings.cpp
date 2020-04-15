#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define ll long long 
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define printarray(A) for(long long i=0; i<A.size() ; i++) cout<<A[i]<<" "; cout<<"\n";
#define mod 1000000007


string multiply(string A, string B) {
    string s1 = max(A,B);
    reverse(s1.begin(), s1.end());
    string s2 = min(A,B);
    reverse(s2.begin(), s2.end());
    
    int n = s1.length(), m = s2.length(),mut,carry;
    vector<vector<int>> ans(m);

    f(j,0,m){
        carry = 0;
        f(k,0,j) 
            ans[j].pb(0);
        f(i,0,n){
            mut = (int)(s1[i]-'0') * (int)(s2[j]-'0') + carry;
            ans[j].pb(mut%10);
            carry = mut/10;
        }
        if(carry == 0) {
        	f(k,0,m-j-1)
            	ans[j].pb(0);
        }
        else {
        	ans[j].pb(carry);
        	f(k,0,m-j-1)
        		ans[j].pb(0);
        }
    }
    // f(i,0,m){
    // 	cout<<"\n";
    // 	for(int j=ans[i].size()-1;j >= 0;j--)
    // 		cout<<ans[i][j]<<"";
    // }
    // cout<<"\n\n";

    
    
    int len = ans[0].size();
    carry = 0;
    vector<int> res(len+1,0);
    f(i,0,m){
        // printarray(res);

         carry = 0;
        f(j,0,len){
            int sum = ans[i][j] + res[j] + carry;
            carry = sum/10;
            res[j] = sum%10;
        }
        // cout<<"\ncarry is "<<carry<<"\n";

        // printarray(res);

    }
    // cout<<ans[ans.size()-1].size()<<" "<<ans[0].size()<<"\n";
    // if(ans[ans.size()-1].size() > ans[0].size()){
    // 	res.pb( ans[ans.size()-1][len] );
    // }
 


    // printarray(res);

    len = res.size();
    // cout<<carry<<"\n";
    string finalans = "";

    f(i,0,len) 
        finalans += res[i]+'0';
    
    int temp = len-1;

    while(1){
    	if(finalans[temp] == '0') temp--;
    	else break;
    }
    finalans.erase(temp+1,len-1);
    // cout<<finalans<<"\n";

    if(ans[ans.size()-1].size() > ans[0].size()){
    	finalans += (char)(ans[ans.size()-1][ans[0].size()]+'0');
    }

    reverse(finalans.begin(),finalans.end());
    return finalans;
}


int main(){

	string s1,s2;
	cin>>s1>>s2;
	cout<<multiply(s1,s2);

}

 