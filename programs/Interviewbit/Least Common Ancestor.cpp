/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> path1,path2;
 int num1,num2;
 void findpath(TreeNode *A,int &B,vector<int> path){
     if(A==NULL) return;
     path.push_back(A->val);
     
     if(A->val == B){
         if(B==num1) path1 = path;
         if(B==num2) path2 = path;
         return ;
     }
     findpath(A->left,B,path);
     findpath(A->right,B,path);
 }
int Solution::lca(TreeNode* A, int B, int C) {
    num1 = B,num2 = C;
    path1.clear();
    path2.clear();
    vector<int> temp;
    findpath(A,B,temp);
    findpath(A,C,temp);
    
    int ans = -1;
    if(path1.size() == 0 || path2.size() == 0) return ans;
    for(int i=0;i<min(path1.size(),path2.size()); i++){
        // cout<<path1[i]<<" and "<<path2[i]<<"\n";
        if(path1[i] == path2[i]) ans = path1[i];
        else break;
    }

    return ans;
}
