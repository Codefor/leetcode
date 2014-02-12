#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution {
    public:    
	vector<int> postorderTraversal(TreeNode *root) {
	    vector<int> res;
	    _postorderTraversal(root,res);
	    return res;
	}

	void _postorderTraversal(TreeNode *root,vector<int> &res){
	    if(NULL == root){
		return;
	    }

	    _postorderTraversal(root->left,res);
	    _postorderTraversal(root->right,res);

	    res.push_back(root->val);
	}
};

int main(){
    struct TreeNode t1 = TreeNode(1);
    struct TreeNode t2 = TreeNode(2);
    struct TreeNode t3 = TreeNode(3);
    struct TreeNode t4 = TreeNode(4);
    struct TreeNode t5 = TreeNode(5);
    struct TreeNode t6 = TreeNode(6);
    struct TreeNode t7 = TreeNode(7);

    t1.left = &t2;
    t1.right= &t3;
    t2.left = &t4;
    t3.right = &t5;
    t4.left = &t6;
    t5.right = &t7;

    Solution s;
    vector<int> res = s.postorderTraversal(&t1);
    for(int i=0;i<res.size();i++){
	cout<< res[i] <<endl;
    }
    return 0;
}
