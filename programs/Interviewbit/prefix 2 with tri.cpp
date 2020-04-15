struct triNode{
    unordered_map<char,triNode*> child;
    unordered_map<char,int> freq;
    bool isend = 0;
};

vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    vector<string> res(n);
    unordered_map<string,int> m;
    
    triNode *root = new triNode;
    
    for(int i=0; i<n; i++){
        triNode *temp = root;
        triNode *next;
        for(int j=0; j<A[i].length(); j++){
            char curr = A[i][j];
            next = new triNode;
            //if no character is there
            if(temp->freq[curr] == 0){
                temp->child[curr] = next;
            }
            //is curr character is already recorded
            else{
                next = temp->child[curr];
            }
            temp->freq[curr]++;
            temp = next;
        }
        next->isend = 1;
    }
    
    for(int i=0; i<n; i++){
        triNode *temp = root;
        string s = "";
        for(int j=0; j<A[i].length(); j++){
            char curr = A[i][j];
            s += curr;
            if(temp->freq[curr] == 1){
                res.push_back(s);
                break;
            }
            temp = temp->child[curr];
        }
    }
    return res;
}
