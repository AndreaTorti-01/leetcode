// beats 100%

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    string predictPartyVictory(string senate)
    {
        // create two vectors
        const int n = senate.size();
        vector<int> R;
        R.reserve(n);
        vector<int> D;
        D.reserve(n);

        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'R')
            {
                R.push_back(i);
            }
            else
            {
                D.push_back(i);
            }
        }
        // simulate the voting process
        int rIdx = 0, dIdx = 0, rPos, dPos;
        while (rIdx < R.size() && dIdx < D.size())
        {
            // get the position of the next senator of each party
            rPos = R[rIdx];
            dPos = D[dIdx];
            // schedule vote of winning senator in the next round
            // the next rounds goes from n to 2n-1
            if (rPos < dPos)
            {
                R.push_back(rPos + n);
                rIdx++;
                dIdx++;
            }
            else
            {
                D.push_back(dPos + n);
                rIdx++;
                dIdx++;
            }
        }
        return rIdx < R.size() ? "Radiant" : "Dire";
    }
};