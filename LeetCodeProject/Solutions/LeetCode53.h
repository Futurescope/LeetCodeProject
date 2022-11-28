#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _53
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

        int maxSubArray(vector<int>& nums)
        {
            vector<int > res(nums.size(), 0);
            int temp;
            res[0] = nums[0];
            // 关键思路是求出所有的子串和然后找最大的
            // 用一个数组记录以i位置结尾的子串的最大和
            // 既然以i位置结尾，那么必然包含i自己，子串只可能是加入前面的或者自成一队
            for (int i = 1; i < nums.size(); ++i)
            {
                temp = res[i - 1] + nums[i];
                res[i] = temp > nums[i] ? temp : nums[i];
            }
            sort(res.begin(), res.end());
            return res.back();
        }

    public:
        bool exec() override
        {
            vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
            DebugUtil::DebugVector(vec);
            return true;
        }
    };
} // namespace _54