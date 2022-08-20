#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _14
{
	class Solution : public SolutionBase
	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		string longestCommonPrefix(vector<string>& strs)
		{

		}

		bool exec() override
		{
			DebugUtil::OutputValue(longestCommonPrefix({ "cbaebabacd" }));
			return true;
		}
	};
} // namespace _14