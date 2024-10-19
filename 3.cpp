// beats 100%

#include <algorithm>
#include <execution>
#include <vector>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        // vector as long as ascii table: counts number of times a character appears
        vector<int> charIndex(128, 0);
        int result = 0, left = 0, right = 0;
        while (right < s.length())
        {
            // if the character has been seen before, move left to the right of the same character last seen
            if (charIndex[s[right]] > 0)
            {
                left = max(charIndex[s[right]], left);
            }
            // update the character's last seen index
            charIndex[s[right]] = right + 1;
            // update the result
            result = max(result, right - left + 1);
            // move right to the next character
            right++;
        }
        return result;
    }
};