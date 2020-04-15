#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

int n;

void GS(int i,int flag,string s){
    if(i >= n){
        cout<<s<<"\n";   
        return ;
    }
    if(flag == 1){
        GS(i+1,0,s+"0");
    }
    else{
        GS(i+1,0,s+"0");
        GS(i+1,1,s+"1");

    }
}

int main(){

  cin>>n;
  GS(1,0,"0");
  GS(1,1,"1");

}
