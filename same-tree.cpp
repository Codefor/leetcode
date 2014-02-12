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
	bool isSameTree(TreeNode *p, TreeNode *q) {
	    if(NULL == p){
		return NULL == q;
	    }else if(NULL == q){
		return false;
	    }else{
		//p != NULL q != NULL
		if(p->val == q->val){
		    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
		}
		return false;
	    }
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

    struct TreeNode p1 = TreeNode(1);
    struct TreeNode p2 = TreeNode(2);
    struct TreeNode p3 = TreeNode(3);
    struct TreeNode p4 = TreeNode(4);
    struct TreeNode p5 = TreeNode(5);
    struct TreeNode p6 = TreeNode(6);
    struct TreeNode p7 = TreeNode(9);

    p1.left = &p2;
    p1.right= &p3;
    p2.left = &p4;
    p3.right = &p5;
    p4.left = &p6;
    p5.right = &p7;

    Solution s;
    cout<<s.isSameTree(&t1,&p1)<<endl;
    return 0;
}
