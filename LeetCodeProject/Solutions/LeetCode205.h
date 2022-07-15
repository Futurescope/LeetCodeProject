#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _205
{
	class Solution : public SolutionBase

	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		bool isIsomorphic(string str1, string str2)
		{
			if (str1.size() != str2.size())
				return false;
			std::vector<int> charsMap(26, -100);
			for (size_t i = 0; i < str1.size(); ++i)
			{
				int charIndex = str1.at(i) - 'a';
				if (charsMap.at(charIndex) == -100)
					charsMap[charIndex] = str2.at(i) - str1.at(i);
				else
				{
					if (charsMap[charIndex] != str2.at(i) - str1.at(i))
						return false;
				}
			}
			return true;
		}

		bool exec() override
		{
			vector<int> ans;
			DebugUtil::OutputValue(isIsomorphic("badc", "baba"));
			return true;
		}
	};
}