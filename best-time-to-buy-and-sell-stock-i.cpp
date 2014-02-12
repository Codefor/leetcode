#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public: 
	//return the next index of Extreme Point in prices from start
	int nextExtremePoint(vector<int> &prices,int start){
	    int size = prices.size();

	    if(start < 0 || size < 2 || start >= size){
		//not found
		return -1;
	    }

	    int index = start + 1;
	    while(index < prices.size()){
		k
	    }
	}

	int maxProfit(vector<int> &prices) {
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
