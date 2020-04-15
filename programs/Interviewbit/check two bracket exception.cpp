#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"
#define f(i,a,b) for(long long i=a;i<b;i++)


queue<char> getsimpleeqn(string s){
    queue<char> ans;
    int i = -1, flag = 0, n = s.length();
    while(i < n){
        i++;
        // if(ans.empty() == 1) ans.push(s[i]);
        if(s[i] == '-' && i+1 < n && s[i+1] == '('){
            flag = 1-flag;
            i++;
        }
        else if(s[i] == ')'){
            flag = 1-flag;
        }
        else if(flag == 1) {
            if(s[i] == '+') ans.push('-');
            else if(s[i] == '-') ans.push('+');
        }
        else if(s[i] == '(' || s[i] == ')') continue;
        else ans.push(s[i]);
        
    
        // debug3(i,n,flag);
    }
    return ans;
}

int Solution::solve(string A, string B) {
    
    queue<char> check;
    string other;
    if(A.length() > B.length()) check = getsimpleeqn(A),other = B;
    else check = getsimpleeqn(B),other = A;
    
    int i = 0;
    while(check.empty() == 0 || i < other.length()){
        // debug3(check.front(),other[i],  "hey");
        if(check.front() != other[i]) return 0;
    
        check.pop();
        i++;
    }
    return 1;
}
