#pragma once

#include <iostream>
#include <functional>

#include <vector>
#include <queue>
#include <deque>

#include <set>
#include <list>

#include <string>

#include <map>
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