#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	int minimumTotal(vector<vector<int> > &triangle) {
	    if(triangle.size() > 0){
		//O(n) extra space
		vector<int> rec(triangle.size()+1);

		for(int i = triangle.size() - 1;i>=0;i--){
		    for(int j=0;j<=i;j++){
			rec[j] = rec[j] < rec[j+1] ? triangle[i][j] + rec[j] : triangle[i][j] + rec[j+1];
		    }
		}
		return rec[0];
	    }
	    return 0;
	}
};

int main(){
    vector<vector<int> > triangle;

    int arr[] = {2,3,4,6,5,7,4,1,8,3};

    vector<int> row1(arr,arr+1);
    vector<int> row2(arr+1,arr+3);
    vector<int> row3(arr+3,arr+6);
    vector<int> row4(arr+6,arr+10);

    triangle.push_back(row1);
    triangle.push_back(row2);
    triangle.push_back(row3);
    triangle.push_back(row4);

    Solution s;
    cout<<s.minimumTotal(triangle)<<endl;
    return 0;
}
