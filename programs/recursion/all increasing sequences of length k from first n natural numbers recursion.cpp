#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)

int arr[1000][100];
int n,k;


void choose(int from,int no_of_elements_choosen,queue<int> q,int last_pushed)
{
    q.push(last_pushed);
    
    if(no_of_elements_choosen >= k) {
        while(q.empty() == 0){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<"\n";
        return ;
    } 
    f(i,from,n+1){
        if(i+k-no_of_elements_choosen>n+1) continue;
        choose(i+1,no_of_elements_choosen+1,q,i);

    }
}
int main(){
    cin>>k>>n;
    queue<int> q;
    f(i,1,n+1){
        if(i+k>n+1) continue;
        choose(i+1,1,q,i);
    }

}
