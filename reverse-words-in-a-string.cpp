#include<iostream>
#include<string>

using namespace std;

class Solution {
    public: 
    void reverseString(string &s,int start,int end){
        char t;
        while(start < end){
            t = s[start];
            s[start] = s[end];
            s[end] = t;

            start++;
            end--;
        }
    }

    void reverseWords(string &s) {
        //trim left
        int l = 0;
        while(s[l] == ' '){
            l++;
        }
        s.erase(0,l);

        //trim right
        l = s.size() - 1;
        while(s[l] == ' '){
            l--;
        }
        s.erase(l+1,s.size()-1-l);
        
        //trim middle
        for(int i= 0;i < s.size();i++){
            if(s[i] == ' '){
                l = i+1;
                while(l < s.size() && s[l] == ' '){
                    l++;
                }

                if(l > i+1){
                    s.erase(i,l-i-1);
                }
            }
        }

        reverseString(s,0,s.size()-1);
        l = 0; 
        for(int i= 0;i < s.size();i++){
            if(s[i] == ' '){
                reverseString(s,l,i-1);
                l = i+1;
            }
        }
        reverseString(s,l,s.size()-1);
    }
};

int main(){
    Solution s;

    string str = "  the sky is       blue  ";
    cout<<str<<endl;
    s.reverseWords(str);
    cout<<str<<endl;
}
