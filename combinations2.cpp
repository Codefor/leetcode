#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	vector<vector<int> > combine(int n, int k) {
	    //n >= k
	    vector<vector<int> > res;
	    if(n<k) return res;

	    if(k == 1){
		for(int i=0;i<n;i++){
		    vector<int> q(1,i+1);
		    res.push_back(q);
		}
	    }else if(n == k){
		vector<int> q;
		for(int i=0;i<n;i++){
		    q.push_back(i+1);
		}
		res.push_back(q);
	    }else{
		//c5,2 = c4,2 + c4,3
		vector<vector<int> > p = combine(n-1,k-1);

		for(int i =0;i<p.size();i++){
		    vector<int> tmp(p[i].begin(),p[i].end());
		    tmp.push_back(n);
		    res.push_back(tmp);
		}

		vector<vector<int> > q = combine(n-1,k);

		for(int i =0;i<q.size();i++){
		    res.push_back(q[i]);
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
