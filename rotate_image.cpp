#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix)
{
    const int n = matrix.size();
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n-i; ++j)
        {
            swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        }
    }

    for(int i=0; i<n/2; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            swap(matrix[i][j], matrix[n-i-1][j]);
        }
    }

}

int main()
{
    vector<vector<int> > matrix;
    int n = 3;
    int k = 0;
    for(int i=1; i<=n; ++i)
    {
        vector<int> vec;
        for(int j=1; j<=n; ++j)
        {
            k = ((i-1)*n + j);
            vec.push_back(k);
        }
        matrix.push_back(vec);
    }

    cout<<"before rotate.."<<endl;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    rotate(matrix);
    cout<<"after rotate.."<<endl;

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
