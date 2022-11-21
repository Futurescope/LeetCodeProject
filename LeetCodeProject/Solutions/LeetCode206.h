#pragma once
#include "DebugUtil.h"
#include "ListNode.h"

using namespace std;

namespace _206
{
	class Solution : public SolutionBase

	{
	public:
		Solution() = default;
		~Solution() = default;

	public:
		// 移除pre节点的下一个节点并返回
		ListNode* removeNode(ListNode* pre)
		{
			ListNode* remove = pre->next;
			pre = remove->next;
			return remove;
		}

		// 将insertNode添加到head前面
		ListNode* insertHead(ListNode* head, ListNode* insertNode)
		{
			insertNode->next = head;
			return insertNode;
		}

		ListNode* reverseList(ListNode* head)
		{
			ListNode* currentNode = head;
			while (currentNode->next != nullptr)
			{
				ListNode* node = removeNode(currentNode);
				head = insertHead(head, node);
			}
			return head;
		}

		bool exec() override
		{
			vector<int> ans;
			// DebugUtil::DebugVector(findAnagrams("cbaebabacd", "abc"));
			return true;
		}
	};
}