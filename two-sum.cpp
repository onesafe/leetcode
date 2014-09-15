#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

vector<int> twoSum(vector<int> &numbers, int target){
    vector<int> r;
    unordered_map<int, int> u_map;
    int i = 0;
    int len = numbers.size();

    for(i=0; i<len; ++i){
        
        if(u_map.count(target-numbers[i])){
            r.push_back(u_map[target-numbers[i]] + 1);
            r.push_back(i + 1);
            return r;
        }
        u_map[numbers[i]] = i;
    }
}

int main(){
    vector<int> numbers, result;
    int i = 0;
    int t = 0;
    cout<<"input numbers count: ";
    cin>>i;
    while(i > 0){
        cout<<"input number: ";
        cin>>t;
        numbers.push_back(t);
        --i;
    }

    int target = 0;
    cout<<"input target: ";
    cin>>target;
    result = twoSum(numbers, target); 
    cout<<"index1="<<result[0]<<", "<<"index2="<<result[1]<<endl;

    return 0;
}
