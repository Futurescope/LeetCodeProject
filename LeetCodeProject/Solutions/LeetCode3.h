#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _3_old
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
			if (s.size() <= 1) return (int)s.size();
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
					nMaxLen = lChildList.size() > nMaxLen ? (int)lChildList.size() : nMaxLen;
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

namespace _3
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;
        // 由英文字母、数字、符号和空格组成
        std::vector<bool> wordBook = std::vector<bool>(128, false);

        bool InBook(char c)
        {
            return wordBook[c];
        }

        void PopBook(char c)
        {
            wordBook[c] = false;
        }
        void PushBook(char c)
        {
            wordBook[c] = true;
        }


        int lengthOfLongestSubstring(const string& s)
        {
            size_t front = 0;
            size_t back = 0;
            size_t maxLen = 0;
            for (; back < s.length(); ++back)
            {
                if (InBook(s[back]))
                {
                    while (front < back)
                    {
                        PopBook(s[front]);
                        ++front;
                        if (s[front - 1] == s[back])
                            break;
                    }
                }
                PushBook(s[back]);
                maxLen = std::max(back - front + 1, maxLen);
            }
            return static_cast<int>(maxLen);
        }

        bool exec() override
        {
            DebugUtil::OutputValue(lengthOfLongestSubstring(""));
            return true;
        }
    };
}
