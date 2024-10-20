// beats 100%

#include <string>
using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string res;
        const int n = s.size();
        const int cycle = 2 * numRows - 2;

        // for every row
        for (int i = 0; i < numRows; ++i)
        {
            // move ahead by one cycle and don't go above n
            for (int j = 0; j + i < n; j += cycle)
            {
                // for sure add the correct letter
                res += s[j + i];
                // if needed add the diagonal letter
                if (i != 0 && i != numRows - 1 && j + cycle - i < n)
                    res += s[j + cycle - i];
            }
        }

        return res;
    }
};