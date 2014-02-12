#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:    
	int maxProfit(vector<int> &prices) {
	    int max = 0;
	    if(prices.size() > 0){
		int j = prices[0];

		int i = 1;
		for(;i<prices.size()-1;i++){
		    if(prices[i] > j){
			max += prices[i] - j;
		    }
		    j = prices[i];
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
