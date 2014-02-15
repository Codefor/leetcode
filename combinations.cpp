#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	vector<vector<int> > combine(int n, int k) {
	    vector<vector<int> > res;
	    vector<int> p(k);

	    for(int j=0;j<k;j++){
		p[j] = j+1;
	    }

	    vector<int> tmp(p.begin(),p.end());
	    res.push_back(tmp);

	    for(int i=k-1;i>=0;i--){
		while(p[i] < n - k + i + 1){
		    p[i] ++;

		    for(int j=i+1;j<k;j++){
			p[j] = p[i] + j - i;
		    }

		    vector<int> tmp(p.begin(),p.end());
		    res.push_back(tmp);

		    if(i< k -1){
			i = k -1;
		    }
		}
	    }

	    return res;
	}

	void display(vector<int> p){
	    cout<<"***display"<<endl;
	    for(int i=0;i<p.size();i++){
		cout<<p[i]<<" ";
	    }
	    cout<<endl;
	}
};

int main(){
    Solution s;
    vector<vector<int> > res = s.combine(4,2);
    for(int i=0;i<res.size();i++){
	for (int j =0;j<res[i].size();j++){
	    cout<<res[i][j]<<" ";
	}
	cout<<endl;
    }

    return 0;
}
