// Manacher's algorithm would be faster

#include <string>
using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        int i = 0, j = 0, max_len = 0, max_i = 0, max_j = 0;
        const int n = s.size();

        // cycle through the string and expand around the center if palindrome
        for (int k = 0; k < n; ++k)
        {
            // Initialize pointers for odd length palindrome
            i = k;
            j = k;
            // Expand around the center for odd length palindrome
            while (i >= 0 && j < n && s[i] == s[j])
            {
                // Update maximum length and indices if a longer palindrome is found
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    max_i = i;
                    max_j = j;
                }
                --i; // Move left pointer to the left
                ++j; // Move right pointer to the right
            }

            // Initialize pointers for even length palindrome
            i = k;
            j = k + 1;
            // Expand around the center for even length palindrome
            while (i >= 0 && j < n && s[i] == s[j])
            {
                // Update maximum length and indices if a longer palindrome is found
                if (j - i + 1 > max_len)
                {
                    max_len = j - i + 1;
                    max_i = i;
                    max_j = j;
                }
                --i; // Move left pointer to the left
                ++j; // Move right pointer to the right
            }
        }

        return s.substr(max_i, max_j - max_i + 1);
    }
};