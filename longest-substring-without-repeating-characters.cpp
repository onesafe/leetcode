#include <iostream>
#include <tr1/unordered_map>
#include <vector>

using namespace std;
using namespace std::tr1;

int lengthOfLongestSubstring(string s){
    unordered_map<char, int> u_map;
    int n = s.length();
    int i = 0, j = 0;
    int maxLen = 0;

    while(i < n){
        
        if(u_map.count(s[i])){
            maxLen = max(maxLen, i - j);
            while(s[i] != s[j]){
                u_map.erase(s[j]);
                ++j;
            }

            ++i;
            ++j;
        }else{
            u_map[s[i]] = i;
            ++i;
        }
    }
    maxLen = max(maxLen, n-j);
    return maxLen;
}

int main(){
    int n = 0;
    string s;
    cout<<"input string: ";
    cin>>s;
    n = lengthOfLongestSubstring(s);
    cout<<"the length is: "<<n<<endl;

    return 0;
}
