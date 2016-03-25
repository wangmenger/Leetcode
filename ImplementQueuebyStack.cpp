#include<iostream>
#include<stack>
using namespace std;

//˼·����������ͼ���ǰд����һƪ�澭��������ͬ����Ŀ�� 
//�������о� ������ջģ��ʵ�ֶ��С����������ܼ򵥣�
//������ջ�Ϳ���ģ��һ�����У�����˼·�����κ���ȳ� = �Ƚ��ȳ���
//Ԫ�������������Aջ��Ԫ�س��������Bջ��Ϊ��ֱ�ӵ���BջͷԪ�أ�
//���BջΪ�վͰ�AջԪ�س�ջȫ��ѹ��Bջ���ٵ���Bջͷ��
//������ģ�����һ�����С����ľ��Ǳ�֤ÿ��Ԫ�س�ջʱ��������A��B����ջ��
//������ʵ�������κ���ȳ� = �Ƚ��ȳ���

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