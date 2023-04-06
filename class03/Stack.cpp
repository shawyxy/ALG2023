#include <iostream>
#include <list>

namespace xy
{
	struct Node
	{
		struct Node* _next;
		struct Node* _prev;
		int _val;
	};

}