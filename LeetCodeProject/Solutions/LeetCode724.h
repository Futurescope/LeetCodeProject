#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _724
{
	class Solution : public SolutionBase

	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
        int pivotIndex(vector<int>& nums)
        {
            int res = 0;
            if (nums.empty())
                return res;
            int sum = std::accumulate(nums.begin(), nums.end(), 0);
            int halfsum = 0;
            for (int i = 0; i < static_cast<int>(nums.size()); ++i)
            {
                if(halfsum * 2 + nums.at(i) == sum)
                    return i;
                halfsum += nums.at(i);
            }
            return -1;
        }

        bool exec() override
		{
			vector<int> vec = {-1,-1,-1,-1,-1,0};
			DebugUtil::OutputValue(pivotIndex(vec));
			return true;
		}
	};
}