#pragma once
#include "DebugUtil.h"

namespace _215
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

        // �����Ŀ�����ⷨ�������ȴӼ򵥵Ŀ�ʼ
        int findKthLargest(std::vector<int>& nums, int k)
        {
            return BubbleMax(nums, k);
        }

        // ���ǵ�������ǰN������֣�N������size�Ĺ�ϵ
        // ���NԶС��size���Ƽ�ʹ�ü򵥵�ð���������򷽷���Ч��O(k*n)
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

        // ���N��size��࣬��Ӧ�ÿ�����ͨ�����򷽷�
        // ���������ʺ������Ŀ������N��size�Ĺ�ϵ�������ʵ�����ŵ�Ч��



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
