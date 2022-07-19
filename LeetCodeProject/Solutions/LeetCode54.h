#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _54
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

    public:
        struct Point
        {
            int row;
            int col;
            Point(int _row, int _col) : row(_row), col(_col){};

            bool operator<=(const Point& pt)
            {
                return row <= pt.row && col <= pt.col;
            };
        };

        Point letTop = Point(0, 0);
        Point ritBot = Point(0, 0);

        vector<int> spiralOrder(vector<vector<int>>& matrix)
        {
            ritBot = Point(matrix.size() - 1, matrix.front().size() - 1);
            int model = 0;
            vector<int> res;
            while (letTop <= ritBot)
            {
                auto tmp = loopOrder(matrix, model);
                res.insert(res.end(), tmp.begin(), tmp.end());
                model = (model + 1) % 4;
            }
            return res;
        }

        vector<int> loopOrder(vector<vector<int>>& matrix, int model)
        {
            int row;
            int col;
            if (model == 0 || model == 1)
                row = letTop.row;
            else
                row = ritBot.row;
            if (model == 1 || model == 2)
                col = ritBot.col;
            else
                col = letTop.col;
            vector<int> res;
            Point x(row, col);
            while (letTop <= x && x <= ritBot)
            {
                res.push_back(matrix[x.row][x.col]);
                switch (model)
                {
                case 0:
                    ++x.col;
                    break;
                case 1:
                    ++x.row;
                    break;
                case 2:
                    --x.col;
                    break;
                case 3:
                    --x.row;
                    break;
                }
            }
            switch (model)
            {
            case 0:
                ++letTop.row;
                break;
            case 1:
                --ritBot.col;
                break;
            case 2:
                --ritBot.row;
                break;
            case 3:
                ++letTop.col;
                break;
            }
            return res;
        }

        bool exec() override
        {
            vector<int> ans;
            vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
            DebugUtil::DebugVector(spiralOrder(matrix));
            return true;
        }
    };
} // namespace _54