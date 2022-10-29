#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <unordered_map>

#include <math.h>
#include <algorithm>
#include <numeric>

class SolutionBase
{
public:
	SolutionBase() = default;
	virtual ~SolutionBase() = default;

	virtual bool exec() = 0;
};