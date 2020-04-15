void findsub(int start,vector<int> &A, vector<vector<int>> &res, vector<int> tempres){
    if(start == A.size()){
        res.emplace_back(tempres);
        return;
    }
    findsub(start+1,A,res,tempres);
    tempres.emplace_back(A[start]);
    findsub(start+1,A,res,tempres);
    tempres.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> res;
    vector<int> tempres;
    findsub(0,A,res,tempres);
    sort(res.begin(), res.end());
    return res;
}
