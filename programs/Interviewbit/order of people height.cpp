#define debug4(a,b,c,d) cout<<a<<"->"<<b<<"->"<<c<<"->"<<d<<"\n"

int mycomp(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        v[i].first = A[i];
        v[i].second = B[i];
    }
    sort(v.begin(),v.end(),mycomp);
    vector<int> res(n,-1);
    int pos;
    for(int i=0;i<n;i++){
        
        pos = v[i].second;
        int emptytillnow = 0;
        for(int k=0;k<pos;k++)
            if(res[k]==-1)
                emptytillnow++;
                
        int start = pos;
        while((emptytillnow<pos || res[start] != -1) && start<n){
            if(res[start] == -1) emptytillnow++;
            start++;
        }
        res[start] = v[i].first;
    }

    return res;
}
