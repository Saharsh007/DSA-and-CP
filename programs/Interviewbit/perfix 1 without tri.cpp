vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    vector<string> res(n);
    unordered_map<string,int> m;
    for(int i=0; i<n; i++){
        int j=1;
        while(j<=A[i].length()){
            string rep = A[i].substr(0,j);
            int flag = 1;
            for(int k=0;k<n;k++){
                if(A[k] != A[i] && A[k].length()>=j && A[k].substr(0,j) == rep )
                    flag = 0;
            }
            if(flag && m[rep] == 0){
                res.push_back(rep);
                m[rep] = 1;
                break;
            }
            j++;
        }
    }

    return res;
}