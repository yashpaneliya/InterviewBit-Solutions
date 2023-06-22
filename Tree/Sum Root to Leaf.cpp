// https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/

// Approach:
// Recursively traverse the tree and keep track of the current number in form of string
// When a leaf node is reached, add the current number to the sum

int sum;

void util(TreeNode* A, string curnum){
    curnum=curnum+to_string(A->val);
    curnum=to_string(stoi(curnum)%1003);
    
    if(A->left==NULL && A->right==NULL){
        int num = stoi(curnum);
        sum = sum + num;
        return;
    }
    
    if(A->left)
        util(A->left, curnum);
    if(A->right)
        util(A->right, curnum);
} 

int Solution::sumNumbers(TreeNode* A) {
    sum = 0;
    if(A==NULL) return 0;
    string s="";
    util(A,s);
    return sum%1003;
}

// TC: O(N)
// SC: O(height)