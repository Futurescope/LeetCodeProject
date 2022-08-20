#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _438
{
	class Solution : public SolutionBase

	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		vector<int> findAnagrams(const string& s, const string& p)
		{
			//get the str p
			vector<int> pHashMap(26, 0);
			size_t pSize = p.size();
			for (const auto& ch : p)
			{
				++pHashMap[ch - 'a'];
			}

			vector<int> ans;
			if (s.size() < pSize)
				return ans;
			size_t left = 0;
			size_t right = 0;
			for (; right < s.size();)
			{
				char ch = s[right];
				if (pHashMap[ch - 'a'] > 0)
				{
					--pHashMap[ch - 'a'];
					++right;
					if (right - left == pSize)
					{
						ans.push_back(left);
					}
				}
				else
				{
					++pHashMap[s[left] - 'a'];
					++left;
				}
			}
			return ans;
		}

		bool exec() override
		{
			vector<int> ans;
			DebugUtil::DebugVector(findAnagrams("cbaebabacd", "abc"));
			return true;
		}
	};
}