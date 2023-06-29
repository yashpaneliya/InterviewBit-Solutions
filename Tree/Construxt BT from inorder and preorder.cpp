// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

// Approach:
// Use preorder to find root and use inorder to find left and right subtrees
// Recursively call for left and right subtrees

TreeNode* generateTree(int prestart, int preend,int instart, int inend, vector<int>& preorder, unordered_map<int,int>& locations){
    if(prestart<=preend && instart<=inend){
        int breakpoint = locations[preorder[prestart]];
        TreeNode* root=new TreeNode(0);
        root->val = preorder[prestart];
        int gap = (breakpoint-instart);
        root->left = generateTree(prestart+1, prestart+gap, instart, breakpoint-1, preorder, locations);
        root->right = generateTree(prestart+gap+1, preend, breakpoint+1, inend, preorder, locations);
        return root;
    } else{
        return NULL;
    }
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> locations;
    for(int i=0;i<B.size();++i)
        locations[B[i]]=i;
        
    return generateTree(0, A.size()-1, 0, B.size()-1, A, locations);
}

// TC: O(n)
// SC: O(n) for recursive stack