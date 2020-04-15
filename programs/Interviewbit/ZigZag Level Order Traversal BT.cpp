/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<stack<TreeNode*>> s(2);
    s[0].push(A);
    int curr = 0;
    vector<vector<int>> res;
    if(A==NULL) return res;
    vector<int> ans;
    while(s[0].empty()==0 || s[1].empty() == 0){
        ans.clear();
        if(curr == 0){
            while(s[curr].empty()==0){
                TreeNode *temp = s[curr].top();
                s[curr].pop();
                if(temp)
                    ans.push_back(temp->val);
                if(temp->left)
                    s[1-curr].push(temp->left);
                if(temp->right)
                    s[1-curr].push(temp->right);
            }
        }
        else if(curr == 1){
            while(s[curr].empty()==0){
                TreeNode *temp = s[curr].top();
                s[curr].pop();
                if(temp)
                    ans.push_back(temp->val);
                if(temp->right)
                    s[1-curr].push(temp->right);
                if(temp->left)
                    s[1-curr].push(temp->left);
            }
        }
        res.push_back(ans);
        curr = 1-curr;
    }

    return res;
}
