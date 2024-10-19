// fast, dumb

#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

  private:
    int atMostK(const vector<int> &nums, int k)
    {
        unordered_map<int, int> count;
        int left = 0, result = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            if (count[nums[right]]++ == 0)
            {
                --k;
            }

            while (k < 0)
            {
                if (--count[nums[left]] == 0)
                {
                    ++k;
                }
                ++left;
            }

            result += right - left + 1;
        }

        return result;
    }
};
