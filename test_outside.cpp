#include<bits/stdc++.h>
using namespace std;
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)
#define ll long long 


int main(){

    ll t,n,m,vv,u;
    scanf("%lld",&t);
    // cin>>t;
    while(t--){
        // cin>>n;
        scanf("%lld %lld",&n,&m);
        vector<vector<ll> > v(n);
        f(i,0,m){
            scanf("%lld %lld",&u,&vv);
            v[u].push_back(vv);
            v[vv].push_back(u);

        }
        // no of edges is odd
        if(m%2 == 0) {
            printf("1\n");
            f(i,0,n)    printf("1 ");
        }
        else{
            ll odd_degree_count = 0;
            f(i,0,n)
                if(v[i].size() % 2 == 1)
                    odd_degree_count++;
            //case2
            if(odd_degree_count > 0){
             	ll index;
             	f(i,0,n) {
             		if(v[i].size() % 2 == 1) {
             			index = i;
             			break;
             		}
             	}
             	printf("2\n");
             	f(i,0,n){
             		 if(i == index) printf("2 ");
             		 else printf("1 ");
             	}
            }
            //case 3
            else{
            	ll index1,index2;
            	f(i,0,n) {
             		if(v[i].size() > 0) {
             			index1 = i;
             			break;
             		}
             	}
             	printf("3\n");
             	index2 = v[index1][0];
             	f(i,0,n){
             		 if(i == index1) printf("2 ");
             		 else if(i == index2) printf("3 ");
             		 else printf("1 ");
             	}


            }
        }
    }
}
