// https://www.interviewbit.com/problems/shortest-unique-prefix/

// Approach:
// Using Trie
// Insert all the strings in the trie
// For each string, find the prefix by traversing the trie
// if the node has only single child till leaf then it is the prefix


struct Node{
    int numPre; // this node is the prefix for numPre strings
    Node* children[26];
};

Node* getNode(){
    struct Node *newnode = new Node;
    newnode->numPre=1;
    for(int i=0;i<26;++i)
        newnode->children[i]=NULL;
    return newnode;
}

void insert(Node* r, string s){
    Node* root=r;
    for(char c:s){
        int index = c-'a';
        if(root->children[index]==NULL){
            root->children[index] = getNode();
        } else{
            root->children[index]->numPre+=1;
        }
        root=root->children[index];
    }
}

string findPre(Node* r, string s){
    Node* root=r;
    string res="";
    int index;
    for(char c:s){
        index = c-'a';
        res+=c;
        if(root->children[index]->numPre==1)
            return res;
        root=root->children[index];
    }
    return res;
}

vector<string> Solution::prefix(vector<string> &A) {
    vector<string> res;
    Node* root = getNode();
    for(string s:A)
    {
        insert(root, s);
    }
    
    for(string s:A)
    {
        res.push_back(findPre(root, s));
    }
    return res;
}

// TC: O(n*m) where n is the number of strings and m is the length of the longest string
// SC: O(n*m) for trie