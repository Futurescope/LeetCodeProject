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
                int target_value = -nums.at(i);
                int j = i + 1;
                int k = (int)nums.size() - 1;
                auto j_value = std::numeric_limits<int>::min();
                while (j < k && j < (int)nums.size())
                {
                    if (nums.at(j) + nums.at(k) == target_value)
                    {
                        if (nums.at(j) > j_value)
                        {
                            res.push_back({nums.at(i), nums.at(j), nums.at(k)});
                            j_value = nums.at(j);
                        }
                        ++j;
                    }
                    else if (nums.at(j) + nums.at(k) < target_value)
                        ++j;
                    else
                        --k;
                }
            }
            res.resize(std::distance(res.begin(), std::unique(res.begin(), res.end())));
            return res;
        }

        bool exec() override
        {
            vector<int> arr = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
            threeSum(arr);
            return true;
        }
    };
} // namespace _15