#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _1706
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

    public:
        vector<vector<int>> grid;
        size_t colSize;

        int nextCell(size_t row, int col)
        {
            size_t currentCell = static_cast<int>(col);
            if (row >= grid.size())
                return -1;
            if (currentCell == 0 && (grid[row][currentCell] == -1))
                return -1;
            if (currentCell == colSize && (grid[row][currentCell] == 1))
                return -1;
            if ((grid[row][currentCell] == -1) && (grid[row][currentCell - 1] == 1))
                return -1;
            if ((grid[row][currentCell] == 1) && (grid[row][currentCell + 1] == -1))
                return -1;
            return (int)currentCell + grid[row][currentCell];
        }

        vector<int> findBall(vector<vector<int>>& in)
        {
            grid.swap(in);
            colSize = grid.front().size() - 1;
            vector<int> res(colSize + 1);
            size_t ball = 0;
            while (ball <= colSize)
            {
                size_t row = 0;
                res[ball] = (int)ball;
                while (row < grid.size())
                {
                    res[ball] = nextCell(row++, res[ball]);
                    if (res[ball] == -1)
                        break;
                }
                ball++;
            }
            return res;
        }

        bool exec() override
        {
            vector<int> ans;
            vector<vector<int>> grid = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
            DebugUtil::DebugVector(findBall(grid));
            return true;
        }
    };
} // namespace _1706