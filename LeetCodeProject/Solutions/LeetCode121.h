#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _121
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

    public:
        int maxProfit(vector<int>& prices)
        {
            if (prices.empty())
                return 0;
            int minPrice = prices.front();
            for (auto& i : prices)
            {
                int temp = i;
                i -= minPrice;
                minPrice = std::min(minPrice, temp);
            }
            return std::max(0, *std::max_element(prices.begin(), prices.end()));
        }

        bool exec() override
        {
            vector<int> prices = { 7,1,5,3,6,4 };
            DebugUtil::OutputValue(maxProfit(prices));
            return true;
        }
    };
} // namespace _121