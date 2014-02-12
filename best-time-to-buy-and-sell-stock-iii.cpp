#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	int maxProfit(vector<int> &prices) {
	}

	int maxProfit2(vector<int> &prices) {
	    int max = 0;
	    if(prices.size() > 1){
		int tmp = 0;
		int j = 0;

		//skip the staring negative sequence
		int i = 0;
		while(prices[i+1] < prices[i]){
		    i++;
		}

		for(;i<prices.size()-1;i++){
		    j = i;
		    //find the incr seq
		    while(prices[i+1] > prices[i] && i<prices.size() -1){
			++i;
		    }
		    if(i > j){
			tmp += prices[i] - prices[j];
			if(tmp >max){
			    max = tmp;
			}
		    }

		    j = i;
		    //find the desc seq
		    while(prices[i+1] < prices[i] && i < prices.size()-1){
			++i;
		    }
		    if(i>j){
			tmp += prices[i] - prices[j];

			if(tmp < 0){
			    tmp = 0;
			}
		    }
		}
	    }

	    return max;
	}
};

int main(){
    Solution *s = new Solution();
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(4);
    cout<<s->maxProfit(prices)<<endl;
}
