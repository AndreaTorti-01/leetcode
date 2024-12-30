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
        size_t n = prices.size();
        if (n < 2)
            return 0;

        vector<int> left(n), right(n);

        // Best single transaction profit up to each index
        int minVal = prices[0], best = 0;
        for (int i = 1; i < n; i++)
        {
            // updates minimum value up to i point
            minVal = min(minVal, prices[i]);
            // updates best profit up to i point
            best = max(best, prices[i] - minVal);
            // sets best profit up to i point
            left[i] = best;
        }

        // Best single transaction profit from each index to end
        int maxVal = prices[n - 1];
        best = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            // updates maximum value from i point to end
            maxVal = max(maxVal, prices[i]);
            // updates best profit from i point to end
            best = max(best, maxVal - prices[i]);
            // sets best profit from i point to end
            right[i] = best;
        }

        // find the maximum profit by combining the two arrays
        int ans = std::transform_reduce(
            std::execution::par_unseq, left.begin(), left.end(), right.begin(), 0,
            [](int a, int b) { return std::max(a, b); }, [](int l, int r) { return l + r; });
        return ans;
    }
};