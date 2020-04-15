int mycomp(pair<int,int> a,pair<int,int> b){
    if(a.first == b.first) return a.second<b.second;
    return a.first>b.first;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    int n = B.size();
    string temp = "";
    int i = 0;
    //creating a map for good words
    unordered_map<string,int> m;
    m.clear();
    while(i<=A.length()){
        if(A[i] == '_' || i == A.length()){
            m[temp] = 1;
            temp = "";
        }
        else{
            temp += A[i];
        }
        i++;
    }
    
    vector<vector<string>> inp(n);
    //storing reviews in a vector<vector<string>> 
    for(i=0; i<n; i++){
         int j = 0;
         temp = "";
         while(j<=B[i].length()){
           if(B[i][j] == '_' || j == B[i].length()){
               if(temp.length()<=4){
                    inp[i].push_back(temp);
               }
            temp = "";

            }
            else{
                temp += B[i][j];
            }  
            j++;
         }
    }
    
    //now to generate the count array
    vector<int> count(n,0);
    for(i=0; i<n; i++){
        for(int j=0; j<inp[i].size(); j++){
            if( m[ inp[i][j] ] == 1){
                count[i]++;
            }
        }
    }
    
    //now that we have the count array let's just sort it using pair
    vector<pair<int,int>> midans(n);
    for(i=0; i<B.size(); i++){
        midans[i].first = count[i];
        midans[i].second = i;
    }
    
    sort(midans.begin(),midans.end(),mycomp);
    
    //now copying final answer in a res vector
    vector<int> res(n);
    
    for(i=0; i<n; i++){
        res[i] = midans[i].second;
    }
    
    return res;
}

