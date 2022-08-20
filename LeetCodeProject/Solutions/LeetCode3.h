#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _3
{
	class Solution : public SolutionBase

	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		int lengthOfLongestSubstring(string s) {
			int nMaxLen = 0;
			// special case
			if (s.size() <= 1) return s.size();
			// keep the order of the child_string
			std::list<char> lChildList;
			// hash vector
			std::vector<char> vecCheck;
			vecCheck.resize(100, 0);
			lChildList.push_back(s.at(0));
			vecCheck[s.at(0) - ' '] = 1;
			nMaxLen = 1;
			for (int i = 1; i < s.size(); ++i)
			{
				char it = s.at(i);
				if (vecCheck.at(it - ' ') == 1)
				{
					while (true)
					{
						// refinded the child string
						if (lChildList.empty())
						{
							//vecCheck[it - ' '] = 1;
							//lChildList.push_back(it - ' ');
							break;
						}
						else if (lChildList.front() == it)
						{
							vecCheck[lChildList.front() - ' '] = 0;
							lChildList.pop_front();
							break;
						}
						// new child string
						else
						{
							vecCheck[lChildList.front() - ' '] = 0;
							lChildList.pop_front();
						}
					}
				}
				//else
				{
					lChildList.push_back(it);
					vecCheck[it - ' '] = 1;
					nMaxLen = lChildList.size() > nMaxLen ? lChildList.size() : nMaxLen;
				}
			}
			return nMaxLen;
		}

		bool exec() override
		{
			vector<int> ans;
			// DebugUtil::DebugVector(findAnagrams("cbaebabacd", "abc"));
			return true;
		}
	};
}