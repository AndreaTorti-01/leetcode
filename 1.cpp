// beats 100%

#include <algorithm>
#include <execution>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // order nums 
        vector<int> sorted_nums = nums;
        sort(execution::par, sorted_nums.begin(), sorted_nums.end());

        // find the two numbers
        int i = 0, j = sorted_nums.size() - 1, sum;
        while (i < j) {
            sum = sorted_nums[i] + sorted_nums[j];
            if (sum == target) {
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        
        // find the indices of the two numbers in the original vector and return their indices
        vector<int> res;
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] == sorted_nums[i] || nums[k] == sorted_nums[j]) {
                res.push_back(k);
            }
        }

        return res;
    }
};
