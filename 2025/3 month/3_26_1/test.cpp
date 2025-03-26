#include <vector>

class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.size() % (i + 1) == 0)
            {
                ret += (nums[i] * nums[i]);
            }
        }
        return ret;
    }
};