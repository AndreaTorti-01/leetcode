// beats 100%

#include <execution>
#include <numeric> // needed for transform_reduce
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // Using transform_reduce to calculate the maximum profit from stock prices
        // execution::par - Specifies parallel execution policy
        // prices.begin() - Iterator to the beginning of the prices vector
        // prices.end() - 1 - Iterator to the second last element of the prices vector
        // prices.begin() + 1 - Iterator to the second element of the prices vector
        // 0 - Initial value for the reduction
        // plus<>() - Binary operation to sum up the results of the transformation
        // [](int a, int b) { return max(0, b - a); } - Lambda function to calculate the profit for each pair of
        // consecutive days. b - a if b > a, otherwise 0.
        return transform_reduce(execution::par, prices.begin(), prices.end() - 1, prices.begin() + 1, 0, plus<>(),
                                [](int a, int b) { return max(0, b - a); });
    }
};