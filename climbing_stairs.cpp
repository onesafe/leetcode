#include <iostream>
#include <vector>

using namespace std;

int climbstairs(int n)
{
    int prev = 0;
    int cur = 1;
    for(int i=1; i<=n; ++i)
    {
        int tmp = cur;
        cur += prev;
        prev = tmp;
    }
    return cur;
}

int main()
{
    int r = climbstairs(5);
    cout<<r<<endl;

    return 0;
}
