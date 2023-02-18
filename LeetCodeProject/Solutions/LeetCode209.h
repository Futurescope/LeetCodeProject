#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _209
{
class Solution : public SolutionBase
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int min_len = std::numeric_limits<int>::max();
        int i = 0;
        int j = 0;
        int sum = 0;
        bool res = false;
        for (; j < nums.size(); ++j)
        {
            sum += nums[j];
            if (sum < target)
                continue;
            while (sum >= target)
                sum -= nums[i++];
            min_len = min(j - i + 2, min_len);
            res = true;
        }
        return res ? min_len : 0;
    }
    bool exec() override
    {
        std::vector<int> ans{ 1,1,1,1,1,1,1,1 };
        DebugUtil::OutputValue(minSubArrayLen(11, ans));
        return true;
    }
};
}
