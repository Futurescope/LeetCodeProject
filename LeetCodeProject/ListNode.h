#pragma once
#include <memory>

template<typename T>
class Node
{
public:
	Node(T x, std::shared_ptr<Node> p = nullptr) : val(x), next(p) {};
	~Node() = default;

public:
	//static Node* head = nullptr;
	T val;
	std::shared_ptr<Node> next;
};

class ListNode : public Node<int>
{
public:
	ListNode(int x, std::shared_ptr<ListNode> p = nullptr)
		:Node<int>(x, p)
	{};
	~ListNode() = default;
};

// struct DoubleListNode
// {
// public:
// 	DoubleListNode(int x, DoubleListNode* pLast = nullptr, DoubleListNode* pNext = nullptr)
// 		: val(x),last(pLast), next(pNext) {}
// 
// public:
// 	int val;
// 	DoubleListNode* last;
// 	DoubleListNode* next;
// };
