#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int solve(ll l,ll r,ll key){

	if(key == 1) return 1;
	ll  result;
	while(l<=r){
		ll mid = (l+r)/2;
		if(mid*mid == key) return mid;
		else if(mid*mid < key){
			l = mid + 1;
			result = mid;
		}
		else r = mid-1;
	}
	return result; 
}
int Solution::sqrt(int A) {
    if(A < 2) return A;
    return solve(1,A/2,A);
}
