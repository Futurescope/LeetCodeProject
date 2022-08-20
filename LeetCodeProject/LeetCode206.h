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
		// �Ƴ�pre�ڵ����һ���ڵ㲢����
		ListNode* removeNode(ListNode* pre)
		{
			ListNode* remove = pre->next;
			pre = remove->next;
			return remove;
		}

		// ��insertNode��ӵ�headǰ��
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