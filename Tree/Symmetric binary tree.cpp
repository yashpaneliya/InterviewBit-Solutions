// https://www.interviewbit.com/problems/symmetric-binary-tree/hints/

// Approach:
// Do level order traversal and check if the level is palindrome or not

int Solution::isSymmetric(TreeNode* A) {
    queue<TreeNode*> q;
    
    q.push(A);
    while(!q.empty()){
        int size=q.size();
        vector<int> temp;
        while(size--){
            TreeNode* t = q.front();
            q.pop();
            if(t->left==NULL)
                temp.push_back(-1);
            else
            {
                q.push(t->left);
                temp.push_back(t->left->val);
            }
            if(t->right==NULL)
                temp.push_back(-1);
            else{
                q.push(t->right);
                temp.push_back(t->right->val);
            }
        }
        
        for(int i=0;i<temp.size();++i){
            if(temp[i]!=temp[temp.size()-i-1])
                return 0;
        }
    }
    return 1;
}

// TC: O(n)
// SC: O(n) for queue