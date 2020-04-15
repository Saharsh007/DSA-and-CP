#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back

int Solution::firstMissingPositive(vector<int> &A) {
    int i = A.size(),n=A.size();
    int j = 0;
    f(i,0,n){
        if(A[i]<=0){
            swap(A[i],A[j]);
            j++;
        }
    }
    A.erase (A.begin(),A.begin()+j);
    n = A.size();
    //at this point all negative elements are removed 
    // elements less than n, their position will be made negative
    // so first positive element's position will give the answer
    f(i,0,n){
         if(abs(A[i])-1<A.size() && A[abs(A[i])-1]>0)
            A[abs(A[i])-1]=-A[abs(A[i])-1];
    }
    f(i,0,n) if(A[i]>0) return i+1;
    
    return n+1;
}
