#include<iostream>
#include<queue>
using namespace std;

// implement stack by queue
// idea: using 2 queues, with 1 always empty, alternatively empty the two

class Stack {
private:
	queue<int> Q1;
	queue<int> Q2;

public:
	// Push element x onto stack.
	void push(int x) {
		if (Q1.empty())
		{
			Q1.push(x);
			while (!Q2.empty())
			{
				Q1.push(Q2.front());
				Q2.pop();
			}
		}
		else
		{
			Q2.push(x);
			while (!Q1.empty())
			{
				Q2.push(Q1.front());
				Q1.pop();
			}
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!empty()) 
		{
			if (Q1.empty())
				Q2.pop();
			else
				Q1.pop();
		}
	}

	// Get the top element.
	int top() {
		if (!empty())
		{
			if (Q1.empty())
				return Q2.front();
			else
				return Q1.front();
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		return Q1.empty() && Q2.empty();
	}

};


int main()
{
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	while (!stk.empty())
	{
		cout << stk.top() << endl;
		stk.pop();
	}
	system("pause");
	return 0;
}