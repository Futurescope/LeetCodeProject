#pragma once
#include "DebugUtil.h"

using namespace std;

namespace _43
{
	class Solution : public SolutionBase
	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		int number(char c)
		{
			return c - '0';
		}
		char getchar(int n)
		{
			return n + '0';
		}
		char plus(char a, char b)
		{
			return getchar(number(a) + number(b));
		}
		string plus(const string& num1, const string& num2)
		{
			if (num1.empty())
				return num2;
			if (num2.empty())
				return num1;
			char perfix = '0';
			size_t len1 = num1.size();
			size_t len2 = num2.size();
			string res(std::max(len1, len2), '0');
			size_t i = 0;
			while (i <= res.size())
			{

				if (i >= len1)
					res[i] = num2[i];
				else if (i >= len2)
					res[i] = num1[i];
				else
				{
					res[i] = plus(plus(num1.at(i), num2.at(i)), perfix);
					if (plus(num1.at(i), num2.at(i)) > '9')
					{
						perfix = '1';
						res[i] -= 10;
					}
					else
						perfix = '0';
				}
			}
			if (perfix != '0')
				res.push_back(perfix);
			return res;
		}
		string multiply(const string& num, char n, int level)
		{
			int value = 0;
			int index = 0;
			for (const auto& i : num)
			{
				value += number(i) * number(n) * std::pow(10, index);
			}
			value *= std::pow(10, level);
			string res;
			while (value > 0)
			{
				res.push_back(getchar(value % 10));
				value = value / 10;
			}
			return res;
		}

		// 字符串格式的数字相乘
		string multiply(string& num1, string& num2)
		{
			std::reverse(num1.begin(), num1.end());
			std::reverse(num2.begin(), num2.end());
			string res;
			size_t i = 0;
			while(i <num2.size())
			{
				string temp = multiply(num1, num2.at(i), i);
				res = plus(res, temp);
			}
			return { res.end(), res.begin() };
		}

		bool exec() override
		{
			string num1 = "213";
			string num2 = "4";
			num2.find_last_of(" ");
			DebugUtil::OutputString(multiply(num1, num2).c_str());
			return true;
		}
	};
} // namespace _43