#pragma once
#include "DebugUtil.h"

namespace _215
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

        // 这个题目有许多解法，可以先从简单的开始
        int findKthLargest(std::vector<int>& nums, int k)
        {
            return BubbleMax(nums, k);
        }

        // 考虑到数组中前N大的数字，N与数组size的关系
        // 如果N远小于size，推荐使用简单的冒（大）泡排序方法，效率O(k*n)
        int BubbleMax(std::vector<int>& nums, int k)
        {
            if (nums.size() < k)
                return -1;
            for (int count = 0; count < k; ++count)
            {
                for (int i = (int)nums.size() - 1; i > count; --i)
                {
                    if (nums[i] > nums[i - 1])
                        std::swap(nums[i], nums[i - 1]);
                }
            }
            return nums[--k];
        }

        // 如果N与size差不多，那应该考虑普通的排序方法
        // 堆排序最适合这个题目，无论N与size的关系如何总能实现最优的效率



        bool exec() override
        {
            std::vector<int> ans{ 999 };
            std::vector<int>* nums = &ans;
            auto i = (*nums)[0];
            DebugUtil::OutputValue(findKthLargest(ans, 1));
            return true;
        }
    };
}
