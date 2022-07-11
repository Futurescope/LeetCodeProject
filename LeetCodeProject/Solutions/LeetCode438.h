#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _438
{
	class Solution : public SolutionBase

	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		bool findWord(vector<vector<char>>& board, char ch, size_t& x, size_t& y)
		{
			size_t maxX = board.size();
			size_t maxY = board[x].size();
			if (x >= 1 && board[x - 1][y] == ch)
				return --x >= 0;
			if (x + 1 < maxX && board[x + 1][y] == ch)
				return ++x >= 0;
			if (y >= 1 && board[x][y - 1] == ch)
				return --y >= 0;
			if (y + 1 < maxY && board[x][y + 1] == ch)
				return ++y >= 0;
			return false;
		}

		bool exist(vector<vector<char>>& board, string word) {
			for (size_t x = 0; x < board.size(); ++x)
			{
				for (size_t y = 0; y < board[x].size(); ++y)
				{
					if (board[x][y] == word.front())
					{
						bool res = true;
						auto _x = x;
						auto _y = y;
						for (size_t i = 1; i < word.size(); ++i)
						{
							res = res && findWord(board, word[i], _x, _y);
						}
						if (res)
							return true;
					}
				}
			}
			return false;
		}

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