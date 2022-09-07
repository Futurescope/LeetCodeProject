#pragma once
#include "DebugUtil.h"

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        m_maxCap = capacity;
    }

    int get(int key)
    {
        if (m_map.find(key) == m_map.end())
            return -1;
        auto res = *m_map[key];
        m_order.erase(m_map[key]);
        m_order.push_back(res);
        m_map[key] = --m_order.end();
        return res.first;
    }

    void put(int key, int value)
    {
        // 新的key
        if (m_map.find(key) == m_map.end())
        {
            if (m_map.size() == m_maxCap)
            {
                // 淘汰最老的
                m_map.erase(m_order.begin()->second);
                m_order.pop_front();
            }
            // add
            m_order.emplace_back(value, key);
            m_map[key] = --m_order.end();
            return;
        }
        // 重复的
        m_order.erase(m_map[key]);
        m_order.emplace_back(value, key);
        m_map[key] = --m_order.end();
    }

private:
    int m_maxCap = 0;
    std::list<std::pair<int, int>> m_order;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map;
};

namespace _146
{
    class Solution : public SolutionBase
    {
    public:
        Solution() = default;
        ~Solution() = default;

        bool exec() override
        {
            //["LRUCache","put","put","get","put","get","put","get","get","get"]
            //[[2], [1, 0], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
            LRUCache cache(2);
            cache.put(1, 1);
            // DebugUtil::OutputValue(cache.get(2));
            cache.put(2, 2);
            DebugUtil::OutputValue(cache.get(1));
            cache.put(3, 3);
            DebugUtil::OutputValue(cache.get(2));
            cache.put(4, 4);
            DebugUtil::OutputValue(cache.get(1));
            DebugUtil::OutputValue(cache.get(3));
            DebugUtil::OutputValue(cache.get(4));
            return true;
        }
    };
}
