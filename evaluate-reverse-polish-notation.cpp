#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
    public: 
    int evalRPN(vector<string> &tokens) {
        vector<int> store;
        for(int i=0;i<tokens.size();i++){
            //switch only support integer
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a = store[store.size()-1];
                store.pop_back();
                int b = store[store.size()-1];

                switch(tokens[i][0]){
                    case '+':
                        store[store.size()-1] = b + a;
                        break;
                    case '-':
                        store[store.size()-1] = b - a;
                        break;
                    case '*':
                        store[store.size()-1] = b * a;
                        break;
                    case '/':
                        store[store.size()-1] = b / a;
                }
            }else{
                store.push_back(atoi(tokens[i].c_str()));
            }
        }
        return store[0];
    }
};

int main(){
    Solution s;

    string a[] = {"2", "1", "+", "3", "*"};
    vector<string> v(a,a+5);
    cout<<s.evalRPN(v)<<endl;

    string b[] = {"4", "13", "5", "/", "+"};
    vector<string> v2(b,b+5);
    cout<<s.evalRPN(v2)<<endl;
}
