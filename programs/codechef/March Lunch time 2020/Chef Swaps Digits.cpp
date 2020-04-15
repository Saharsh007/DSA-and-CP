#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define ll long long 
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define printarray(A) for(long long i=0; i<A.size() ; i++) cout<<A[i]<<" "; cout<<"\n";
#define mod 1000000007



int main(){
    int t,a,b,temp;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int ans = a+b;
        string aa = to_string(a),bb = to_string(b);
        int as = aa.length(),bs = bb.length();
        
        f(i,0,bs){
            swap(aa[0],bb[i]);
            ans = max(ans,stoi(aa)+stoi(bb));
            swap(aa[0],bb[i]);
        }

        f(i,0,as){
            swap(bb[0],aa[i]);
            ans = max(ans,stoi(aa)+stoi(bb));
            swap(bb[0],aa[i]);
        }

        cout<<ans<<"\n";
    }   

}

 