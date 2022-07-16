#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _202
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

    public:
        bool isHappy(int n)
        {
            while (true)
            {
                int sum = 0;
                while (n > 0)
                {
                    int i = n % 10;
                    sum += i * i;
                    n = n / 10;
                }
                if (sum == 1)
                    return true;
                if (values.find(sum) != values.end())
                    return false;
                n = sum;
                values.emplace(sum);
            }
            return false;
        }
        std::set<int> values;

        bool exec() override
        {
            vector<int> ans;
            DebugUtil::OutputValue(isHappy(2));
            return true;
        }
    };
} // namespace _202