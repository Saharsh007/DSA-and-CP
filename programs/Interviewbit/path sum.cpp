/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int ans = 0;
void solve(TreeNode *A,int B,int sum){
    if(A==NULL){
        return ;
    }
    sum+=A->val;
    if(A->left == NULL && A->right == NULL && B==sum)
        ans = 1;
    

    solve(A->right,B,sum);
    solve(A->left,B,sum);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    ans = 0;
    solve(A,B,0);

    return ans;
}
