#pragma once
#include "pch.h"

namespace DebugUtil
{
	void OutputString(const char* s);

	template<typename T>
	std::string VectorToStr(const std::vector<T>& vec)
	{
		std::string str;
		for (const auto& it : vec)
		{
			str += std::to_string(it);
			str += ' ';
		}
		return str;
	}

	template<typename T>
	void DebugVector(const std::vector<T>& vec)
	{
		std::string str = DebugUtil::VectorToStr(vec);
		OutputString(str.c_str());
	}
}
