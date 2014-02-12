#include<iostream>

using namespace std;

class Solution {
    public:    
	int singleNumber(int A[], int n) {
	    int s = 0;
	    int i = 0;
	    for(;i<n;i++){
		s ^= A[i];
	    }
	    return s;
	}
};

int main(){
    int a[] = {133,2,3,4,5,6,6,5,4,3,2};
    Solution s;
    cout<<s.singleNumber(a,11)<<endl;
    return 0;
}
