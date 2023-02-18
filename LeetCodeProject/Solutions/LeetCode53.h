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
            // �ؼ�˼·��������е��Ӵ���Ȼ��������
            // ��һ�������¼��iλ�ý�β���Ӵ�������
            // ��Ȼ��iλ�ý�β����ô��Ȼ����i�Լ����Ӵ�ֻ�����Ǽ���ǰ��Ļ����Գ�һ��
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