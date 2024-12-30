// beats 100%

#include <algorithm>
#include <execution>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // make the derivative array as long as prices
        vector<int> derivative(prices.size(), 0);
        for (int i = 0; i < static_cast<int>(prices.size()) - 1; i++)
        {
            // compiler will optimize this
            int diff = prices[i + 1] - prices[i];
            derivative[i] = diff > 0 ? diff : 0;
        }
        // sum the derivative array in parallel
        return (reduce(execution::par, derivative.begin(), derivative.end(), 0));
    }
};