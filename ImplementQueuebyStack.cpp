#include<iostream>
#include<stack>
using namespace std;

//思路分析：这题和几年前写过的一篇面经博文是相同的题目： 
//面试题研究 用两个栈模拟实现队列。基本做法很简单，
//用两个栈就可以模拟一个队列，基本思路是两次后进先出 = 先进先出，
//元素入队列总是入A栈，元素出队列如果B栈不为空直接弹出B栈头元素；
//如果B栈为空就把A栈元素出栈全部压入B栈，再弹出B栈头，
//这样就模拟出了一个队列。核心就是保证每个元素出栈时都经过了A，B两个栈，
//这样就实现了两次后进先出 = 先进先出。

class Queue {
private:
	stack<int> A;
	stack<int> B;
public:
	// Push element x to the back of queue.
	void push(int x) {
		A.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!B.empty())
			B.pop();
		else if (!A.empty())
		{
			// push A into B and pop()
			while (!A.empty())
			{
				B.push(A.top());
				A.pop();
			}
			B.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if (!B.empty())
		{
			return B.top();
		}
		else
		{
			// push all ele in A into B and top()
			while (!A.empty())
			{
				B.push(A.top());
				A.pop();
			}
			return B.top();
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return (A.empty() && B.empty());
	}

};

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	while (!q.empty())
	{
		cout << q.peek() << endl;
		q.pop();
	}
	system("pause");
	return 0;
}