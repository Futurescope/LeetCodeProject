#pragma once
#include "pch.h"

template <typename T = int>
struct ListNode
{
    T val;
    ListNode* next;
    ListNode() : val(T()), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode *next) : val(x), next(next) {}
};

template <typename T = int>
ListNode<T>* CreatList(const std::vector<T>& arr)
{
    ListNode<T>* head = nullptr;
    for (auto it = arr.crbegin(); it != arr.crend(); ++it)
    {
        head = new ListNode<T>(*it, head);
    }
    return head;
}

namespace DebugUtil
{
    void OutputString(const char* s);
    template <typename T>
    void OutputValue(T s)
    {
        if (std::is_same<T, bool>::value)
            OutputString(s ? "true" : "false");
        else
            OutputString(std::to_string(s).c_str());
    }

    template <typename T>
    std::string VectorToStr(const std::vector<T>& vec)
    {
        std::string str;
        for (const auto& it : vec)
        {
            str += std::to_string(it);
            str += ' ';
        }
        return { str.begin(), str.end() - 1 };
    }

    template <typename T>
    void DebugVector(const std::vector<T>& vec)
    {
        std::string str = DebugUtil::VectorToStr(vec);
        OutputString(str.c_str());
        OutputString("\n");
    }

    template <typename T>
    void DebugList(const ListNode<T>* head)
    {
        if(head == nullptr)
            OutputString("Empty List!");
        while (head != nullptr)
        {
            OutputValue((T)head->val);
            if(head->next != nullptr)
                OutputString(", ");
            head = head->next;
        }
        OutputString("\n");
    }
}
