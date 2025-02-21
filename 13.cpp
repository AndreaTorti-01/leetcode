#include <map>
#include <string>
using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int temp, past = 1000, result = 0;
        for (char c : s)
        {
            switch (c)
            {
            case 'I':
                temp = 1;
                break;
            case 'V':
                temp = 5;
                break;
            case 'X':
                temp = 10;
                break;
            case 'L':
                temp = 50;
                break;
            case 'C':
                temp = 100;
                break;
            case 'D':
                temp = 500;
                break;
            case 'M':
                temp = 1000;
                break;
            }
            result += temp;
            if (temp > past)
            {
                result -= 2 * past;
            }
            past = temp;
        }
        return result;
    }
};