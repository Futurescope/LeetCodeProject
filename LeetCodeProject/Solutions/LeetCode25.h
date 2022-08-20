#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x, ListNode* p = nullptr) : val(x), next(p) {}
};

class Partition
{
public:
	Partition() = default;
	~Partition() = default;

public:
	//��Node�ڵ���뵽Front֮��
	void insertNode(ListNode* pFront, ListNode* pNode)
	{
		pNode->next = pFront->next;
		pFront->next = pNode;
	}

	ListNode* partition(ListNode* pHead, int x)
	{
		// ʹ��ͷ�巨���ɽ��������
		if (pHead == nullptr)
			return nullptr;
		ListNode* pSentry = new ListNode(INT_MAX);
		ListNode* pInsPos = pSentry;
		pSentry->next = pHead;
		ListNode* pFront = pSentry;
		//���ҵ�һ������x�Ľڵ�
		while (pFront->next != nullptr)
		{
			ListNode* pNode = pFront->next;
			if (pNode->val < x)
			{
				pFront = pFront->next;
				continue;
			}
			if (pFront->next == nullptr)
			{
				return pHead;
			}
			pInsPos = pFront;
			break;
		}
		pFront = pInsPos;
		//��������pPoint����һ���ڵ�
		while (pFront->next != nullptr)
		{
			ListNode* pNode = pFront->next;
			//ListNode* pNode = nullptr;
			if (pNode->val < x)
			{
				//ȡ������ڵ�
				pFront->next = pNode->next;
				//���뵽����ڵ�֮��
				insertNode(pInsPos, pNode);
				pInsPos = pNode;
			}
			else
			{
				pFront = pFront->next;
			}
		}
		ListNode* pRes = pSentry->next;
		delete pSentry;
		return pRes;
	}

public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* pRes = nullptr;
		if (pHead1->val < pHead2->val)
		{
			pRes = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			pRes = pHead2;
			pHead1 = pHead2->next;
		}
		ListNode* pEnd = pRes;
		while (true)
		{
			//��������
			if (pHead1 == nullptr)
			{
				pEnd->next = pHead2;
				break;
			}
			if (pHead2 == nullptr)
			{
				pEnd->next = pHead1;
				break;
			}

			if (pHead1->val < pHead2->val)
			{
				pEnd->next = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				pEnd->next = pHead2;
				pHead2 = pHead2->next;
			}
			pEnd = pEnd->next;
		}
		return pRes;
	}
};