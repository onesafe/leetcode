#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
        bool isPalindrome(string s){

        int len = s.length();
        int left=0, right=len-1;
        while(left < right){
            if(!isalnum(s[left])){
                    left++;
                }else if(!isalnum(s[right])){
                    right--;
                }else if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }else{
                    left++;
                    right--;
                }
            }
            return true;
        }
};

int main(){

    string s;
    cout<<"input a string: ";
    getline(cin, s);
    Solution t;
    if(t.isPalindrome(s)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}
