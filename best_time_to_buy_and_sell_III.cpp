#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            const int n = prices.size();
            if(n < 2) return 0;

            vector<int> f(n, 0);
            vector<int> g(n, 0);

            for(int i=1,vally=prices[0]; i<n; ++i)
            {
                vally = min(vally, prices[i]);
                f[i] = max(f[i-1], prices[i]-vally);
            }

            for(int i=n-2,peek=prices[n-1]; i>=0; --i)
            {
                peek = max(peek, prices[i]);
                g[i] = max(g[i], peek-prices[i]);
            }

            int max_profit = 0;
            for(int i=0; i<n; ++i)
            {
                cout<<"f["<<i<<"] = "<<f[i]<<" "<<endl;
                cout<<"g["<<i<<"] = "<<g[i]<<" "<<endl;
                
                max_profit = max(max_profit, f[i]+g[i]);
            }

            return max_profit;
        }

};


int main()
{
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(7);
    prices.push_back(9);
    prices.push_back(5);
    prices.push_back(11);

    Solution s;
    int result = s.maxProfit(prices);
    cout<<"result = "<<result<<endl;
    return 0;
}
