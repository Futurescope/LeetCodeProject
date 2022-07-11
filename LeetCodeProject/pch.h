#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <numeric>

class SolutionBase
{
public:
	SolutionBase() = default;
	virtual ~SolutionBase() = default;

	virtual bool exec() = 0;
};