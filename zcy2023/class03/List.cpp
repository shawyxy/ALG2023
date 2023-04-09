#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
	struct Node* _next;
	struct Node* _prev;
	int _val;
};

Node* node1 = new Node;
Node* node2 = new Node;
Node* node3 = new Node;
Node* node4 = new Node;
Node* node5 = new Node;
// 单链表初始化
Node* SingleListInit()
{
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;
	node5->_next = nullptr;

	// node1->_val = 1;
	// node2->_val = 2;
	// node3->_val = 3;
	// node4->_val = 4;
	// node5->_val = 5;
	// remove version
	node1->_val = 1;
	node2->_val = 1;
	node3->_val = 1;
	node4->_val = 4;
	node5->_val = 5;

	return node1;
}
// 双链表初始化
Node* DoubleListInit()
{
	node1->_next = node2;
	node2->_prev = node1;

	node2->_next = node3;
	node3->_prev = node2;

	node3->_next = node4;
	node4->_prev = node3;
	
	node4->_next = node5;
	node5->_prev = node4;

	node5->_next = node1;
	node1->_prev = node5;


	node1->_val = 1;
	node2->_val = 2;
	node3->_val = 3;
	node4->_val = 4;
	node5->_val = 5;

	return node1;
}
// 打印
void SingleListPrint(Node* head)
{
	if(head == nullptr)
		return;

	Node* cur = head;
	while(cur)
	{
		cout << cur->_val << " ";
		cur = cur->_next;
	}
	cout << endl;
}
void DoubleListPrint(Node* head)
{
	if(head == nullptr || head->_next == head->_prev)
		return;

	Node* cur = head;
	while(cur->_next != head)
	{
		cout << cur->_val << " ";
		cur = cur->_next;
	}
	cout << cur->_val;
	cout << endl;

}
// 反转单链表
Node* SingleListReverse(Node* head)
{
	if(head == nullptr || head->_next == nullptr)
		return head;

	Node* cur = head;
	Node* next = head; // 注意next的初始值不能是nullptr否则while失效
	Node* prev = nullptr;
	while(next != nullptr)
	{
		next = cur->_next; // 注意要用cur更新next，用next->_next可能会跳过一个(初始值)
		cur->_next = prev;
		prev = cur;
		cur = next;
	}
	return prev; // 注意走到最后，prev是最后一个结点
}
// 反转双链表
Node* DoubleListReverse(Node* head)
{
	if(head == nullptr || head->_next == head)
		return head;

	Node* cur = head;
	Node* next = cur->_next;

	while(next != head)
	{
		cur->_next = cur->_prev;
		cur->_prev = next;

		cur = next;
		next = next->_next;
	}

	return cur;
}
// 删除链表中值为val的结点
Node* RemoveValOfList(Node* head, int val)
{
	if(head == nullptr || head->_next == nullptr)
		return head;

	Node* cur = head;
	//  头部有连续的val
	while(cur->_val == val)
	{
		cur = cur->_next; // 迭代
	}
	Node* ret = cur;
	// 来到第一个值不是val的位置
	Node* prev = cur;
	while(cur)
	{
		if(cur->_val == val) // 遇到要删除的结点
			prev->_next = cur->_next;
		else
			prev = cur; // 否则更新prev

		cur = cur->_next; // 迭代
	}

	return ret;

	// 思路2:哨兵位结点
	// 在单链表中删除特定值val结点的思路是遍历整个链表，
	// 找到值为val的结点，然后将其删除。
	// 首先创建一个虚拟结点dummy，它的下一个结点指向头结点head。
	// 然后定义两个指针prev和cur分别指向dummy和head。
	// 接着遍历整个链表，如果cur指向的结点的值等于val，
	// 则将prev的下一个结点指向cur的下一个结点，然后删除cur指向的结点，
	// 并将cur指向prev的下一个结点。否则，prev和cur都向后移动一位。
	// 最后返回dummy的下一个结点
	// Node* dummy  = new Node;
    // dummy->_next = head;
    // Node* prev = dummy;
    // Node* cur = head;
    // while (cur) 
    // {
    //     if (cur->_val == val) 
    //     {
    //         prev->_next = cur->_next;
    //         delete cur;
    //         cur = prev->_next;
    //     } else 
    //     {
    //         prev = cur;
    //         cur = cur->_next;
    //     }
    // }
    // return dummy->_next;
}
void ListReverseTest()
{
	// Node* head = SingleListInit();
	// SingleListPrint(head);
	// Node* newHead = SingleListReverse(head);
	// SingleListPrint(newHead);

	Node* head = DoubleListInit();
	DoubleListPrint(head);
	Node* newHead = DoubleListReverse(head);
	DoubleListPrint(newHead);
}
void RemoveValOfListTest()
{
	Node* head = SingleListInit();
	SingleListPrint(head);
	Node* newHead = RemoveValOfList(head, 1);
	SingleListPrint(newHead);
}

int main()
{
	//ListReverseTest();
	RemoveValOfListTest();
	return 0;
}