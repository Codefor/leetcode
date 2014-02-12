#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	vector<vector<int> > generate(int numRows) {           
	    vector<vector<int> > res;

	    if(numRows > 0){
		//add the very first row
		vector<int> tmp;
		tmp.push_back(1);
		res.push_back(tmp);

		//for the following rows,will start with 1,end with 1
		for(int i=1;i<numRows;i++){
		    vector<int> tmp;
		    tmp.push_back(1);

		    for(int j=1;j<i;j++){
			tmp.push_back(res[i-1][j-1] + res[i-1][j]);
		    }

		    tmp.push_back(1);

		    res.push_back(tmp);
		}
	    }
	    return res;
	}
};

int main(){
    Solution s;
    vector<vector<int> > triangle = s.generate(5);
    for(int i=0;i<triangle.size();i++){
	for(int j=0;j<triangle[i].size();j++){
	    cout<<triangle[i][j]<<" ";
	}
	cout<<endl;
    }
    return 0;
}
