#pragma once
#include "../DebugUtil.h"

using namespace std;

namespace _912
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

    public:
        // �������
        void QuickSort(vector<int>& nums, size_t left_in, size_t right_in)
        {
            if (left_in >= right_in)
                return;
            size_t left = left_in;
            size_t right = right_in;
            int val = nums[left];
            while (left < right)
            {
                // ��һ����ֵ
                while (left < right && nums[right] > val)
                    --right;
                if (left < right)
                    // ��++������ѭ��
                    nums[left++] = nums[right];
                // ��һ��Сֵ
                while (left < right && nums[left] < val)
                    ++left;
                if (left < right)
                    nums[right--] = nums[left];
            }
            nums[left] = val;
            QuickSort(nums, left_in, left - 1);
            QuickSort(nums, left + 1, right_in);
        }

        // swap����
        // swap���Ż�������һ�ִ�ǰ���󽻻��ķ������������
        void QuickSortSwap(vector<int>& nums, int left_in, int right_in)
        {
            if (left_in >= right_in)
                return;
            int left = left_in;
            int right = right_in;
            // ���base
            int rand_index = (rand() % (right_in - left_in)) + left_in;
            swap(nums[left_in], nums[rand_index]);
            int base = nums[left];
            while (left < right)
            {
                // ��һ����ֵ����Ϊbaseʹ�õ��ǵ�һ��ֵ���ں���swap base��ʱ��ֻ�����м�Ľ�С�߽���
                // �Ҵ�ֵ��ʱ������left == rightʱ������ͣ���ڽ�С���Ǹ�������
                while (left < right && nums[right] > base)
                    --right;
                // ��һ��Сֵ
                while (left < right && nums[left] <= base)
                    ++left;
                if (left < right)
                    swap(nums[left], nums[right]);
            }
            swap(nums[left_in], nums[left]);
            QuickSortSwap(nums, left_in, left - 1);
            QuickSortSwap(nums, left + 1, right_in);
        }

        vector<int> sortArray(vector<int>& nums)
        {
            QuickSortSwap(nums, 0, nums.size() - 1);
            return nums;
        }

        bool exec() override
        {
            std::vector<int> ans{ 5,4,3,2,1 };
            DebugUtil::DebugVector(sortArray(ans));
            return true;
        }
    };
} // namespace _912