#include <iostream>
#include <vector>

using namespace std;

void addone(vector<int> &digits, int digit)
{
    int c = digit;
    vector<int>::reverse_iterator it;
    for(it=digits.rbegin(); it != digits.rend(); ++it)
    {
        *it += c;
        c = *it/10;
        *it %= 10;
    }
    if(c > 0)
    {
        digits.insert(digits.begin(), 1);
    }
}

vector<int> plusone(vector<int> &digits)
{
    addone(digits, 1);
    return digits;
}

int main()
{
    vector<int> digits;
    vector<int> result;

    digits.push_back(1);
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);

    result = plusone(digits);
    int n = result.size();
    vector<int>::iterator it;
    for(it=result.begin(); it!=result.end(); ++it)
    {
        cout<<*it;
    }
    cout<<endl;

    return 0;
}
