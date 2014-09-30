#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string getPermutation(int n, int k)
{
    vector<int> s(n);
    int pcount = 1;
    for(int i=0; i<n; ++i)
    {
        s[i] = i+1;
        pcount *= (i+1);
    }
    k--;
    string res = "";

    for(int i=0; i<n; ++i)
    {
        pcount = pcount/(n-i);
        int selected = k/pcount;
        res += ('0' + s[selected]);

        for(int j=selected; j<n-i-1; ++j)
        {
            s[j] = s[j+1];
        }
        k = k%pcount;
    }
    return res;
}

int main()
{
    string ret="";
    ret = getPermutation(8, 15025);
    cout<<ret<<endl;

    return 0;
}
