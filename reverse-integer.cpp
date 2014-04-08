#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
    public: 
        int reverse(int x) {
            bool p = x > 0 ? true:false;
            if(!p){
                x = -x;
            }

            int j = 0;
            while(x){
                j = j*10 + x % 10;
                x /= 10;
            }

            return p ? j:-j;
        }
};

int main(){
    Solution s;

    cout<<s.reverse(123)<<endl;
    cout<<s.reverse(-100)<<endl;
}
