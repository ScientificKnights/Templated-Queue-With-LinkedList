#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct node{
	T val;
	node* next;
	node(T data): val(data),next(NULL){}
};

template<typename T>
class ListQueue {
	typedef node<T> * nodePtr;
private:
	nodePtr head;
	nodePtr tail;
	unsigned int size;
	nodePtr CreatNode(const T &data) {
		nodePtr p=new node<T>(data);
		return p;
	}
	void EmptyQueue() {
		while (head != NULL) {
			nodePtr cur = head;
			head = head->next;
			delete cur;
		}
		tail = NULL;
		size = 0;
	}
public:
	ListQueue() {
		head = NULL;
		size = 0;
	}
	~ListQueue() {
		EmptyQueue();
	}
	T front() const{
		return head->val;
	}
	void push(const T &data) {
		nodePtr p = CreatNode(data);
		if (size == 0) {
			head = p;
			tail = p;
		}
		else {
			tail->next = p;
			tail = tail->next;
		}
		size++;
	}
	void pop() {
		if (size == 0) throw - 1;
		else {
			nodePtr cur = head;
			head = head->next;
			if (head == NULL) tail = NULL;
			delete cur;
		}
		size--;
	}
	int Size() const {
		return size;
	}
	bool empty() const {
		return size == 0;
	}
	void print() const{
		nodePtr temp = head;
		for (int i = 0; i < size; i++) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	node<int> res(0);
	cout << res.val;
	ListQueue<string> q;
	cout << q.empty() << endl;
	q.push("chao");
	q.print();
	cout << q.empty() << endl;
	q.push("bin");
	q.push("haha");
	cout << q.front() << endl;
	q.print();
	q.pop();
	q.print();
	q.pop();
	q.pop();
	cout << q.empty() << endl;
	cout << q.Size() << endl;
	q.print();
	system("pause");
	return 0;
}
