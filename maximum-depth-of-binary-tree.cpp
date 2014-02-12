#include<iostream>

using namespace std;


struct TreeNode {
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution {
    public:    
	int maxDepth(TreeNode *root){
	    if(NULL == root){
		return 0;    
	    }

	    int hl = maxDepth(root->left);
	    int hr = maxDepth(root->right);   
	    return hl > hr ? hl + 1 : hr + 1;       
	}	
};

int main(){
    struct TreeNode t1 = TreeNode(1);
    struct TreeNode t2 = TreeNode(1);
    struct TreeNode t3 = TreeNode(1);
    struct TreeNode t4 = TreeNode(1);
    struct TreeNode t5 = TreeNode(1);
    struct TreeNode t6 = TreeNode(1);
    struct TreeNode t7 = TreeNode(1);

    t1.left = &t2;
    t1.right= &t3;
    t2.left = &t4;
    t3.right = &t5;
    t4.left = &t6;
    t5.right = &t7;

    Solution s;
    cout<<s.maxDepth(&t1)<<endl;
    return 0;
}
