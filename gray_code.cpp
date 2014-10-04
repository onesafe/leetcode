#include <iostream>
#include <vector>

using namespace std;

unsigned int binary_to_gray(unsigned int n)
{
    return n^(n >> 1);
}

vector<int> graycode(int n)
{
    vector<int> result;
    const size_t size = 1 << n;
    result.reserve(size);
    for(size_t i=0; i<size; ++i)
    {
        result.push_back(binary_to_gray(i));
    }
    return result;
}

int main()
{
    vector<int> res;
    res = graycode(2);
    vector<int>::iterator it;
    for(it=res.begin(); it!=res.end(); ++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}
