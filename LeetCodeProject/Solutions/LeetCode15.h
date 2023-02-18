#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _15
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

    public:
        vector<vector<int>> threeSum(vector<int>& nums)
        {
            if (nums.size() < 3)
                return {};
            // 这个题目最优就是n^2复杂度
            // 不排序是不行滴
            std::sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            for (int i = 0; i < (int)nums.size(); ++i)
            {
                // 排除i相等的情况
                if (i > 0 && nums[i] == nums[i - 1])
                    continue;
                for (int j = i + 1, k = nums.size() - 1; j < k; ++j)
                {
                    // 排除j相等的情况，k必不相等
                    if (j > i + 1 && nums[j] == nums[j - 1])
                        continue;
                    while (j < k && nums[i] + nums[j] + nums[k] > 0)
                        --k;
                    if (j < k &&nums[i] + nums[j] + nums[k] == 0)
                    {
                        res.push_back({ nums[i], nums[j], nums[k] });
                        continue;
                    }
                }
            }
            return res;
        }

        bool exec() override
        {
            vector<int> arr = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
            threeSum(arr);
            return true;
        }
    };
} // namespace _15