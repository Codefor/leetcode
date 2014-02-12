#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	vector<int> getRow(int rowIndex) {            
	    vector<int> res;
	    if(rowIndex >= 0){
		//the 0th row
		res.push_back(1);

		for(int i=1;i<=rowIndex;i++){
		    for(int j=i-1;j>=1;j--){
			res[j] += res[j-1];
		    }
		    res.push_back(1);
		}
	    }
	    return res;
	}
};

int main(){
    Solution s;
    vector<int> triangle = s.getRow(3);
    for(int i=0;i<triangle.size();i++){
	cout<<triangle[i]<<" ";
    }
    cout<<endl;
    return 0;
}
