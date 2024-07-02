#include <iostream>
#include <vector>
#include <stack>


using namespace std;

// Стек через массив
class StackArray {
public:
	StackArray(int size) {
		arr = new int[size];
		top = -1;
	}

	~StackArray() {
		delete[] arr;
	}

	void push(int value) {
		arr[++top] = value;
	}

	int pop() {
		return arr[top--];
	}

	bool isEmpty() {
		return top == -1;
	}

private:
	int* arr;
	int top;
};

vector<int> fold_strip_array(int k) {
	int length = 1 << k; // 2^k
	StackArray stack(length);
	for (int i = 1; i <= length; i++) {
		stack.push(i);
	}

	while (length > 1) {
		StackArray temp_stack(length / 2);
		for (int i = 0; i < length / 2; i++) {
			temp_stack.push(stack.pop());
		}
		while (!temp_stack.isEmpty()) {
			stack.push(temp_stack.pop());
		}
		length /= 2;
	}

	vector<int> result;
	while (!stack.isEmpty()) {
		result.push_back(stack.pop());
	}
	return result;
}

void print_vector(const vector<int>& v) {
	for (int num : v) {
		cout << num << " ";
	}
	cout << endl;
}



struct Node {
	int data;
	Node* next;
};

class StackLinkedList {
public:
	StackLinkedList() {
		top = nullptr;
	}

	~StackLinkedList() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = top;
		top = newNode;
	}

	int pop() {
		if (isEmpty()) {
			throw runtime_error("Stack underflow");
		}
		Node* temp = top;
		top = top->next;
		int value = temp->data;
		delete temp;
		return value;
	}

	bool isEmpty() {
		return top == nullptr;
	}

private:
	Node* top;
};


vector<int> fold_strip_linked_list(int k) {
	int length = 1 << k; // 2^k
	StackLinkedList stack;
	for (int i = 1; i <= length; i++) {
		stack.push(i);
	}

	while (length > 1) {
		StackLinkedList temp_stack;
		for (int i = 0; i < length / 2; i++) {
			temp_stack.push(stack.pop());
		}
		while (!temp_stack.isEmpty()) {
			stack.push(temp_stack.pop());
		}
		length /= 2;
	}

	vector<int> result;
	while (!stack.isEmpty()) {
		result.push_back(stack.pop());
	}
	return result;
}

vector<int> fold_strip_stl(int k) {
	int length = 1 << k; // 2^k
	stack<int> stack1;
	for (int i = 1; i <= length; i++) {
		stack1.push(i);
	}

	while (length > 1) {
		stack<int> temp_stack;

		for (int i = 0; i < length / 2; i++) {
			temp_stack.push(stack1.top());
			stack1.pop();
		}
		while (!temp_stack.empty()) {
			stack1.push(temp_stack.top());
			temp_stack.pop();
		}
		length /= 2;
	}

	vector<int> result;
	while (!stack1.empty()) {
		result.push_back(stack1.top());
		stack1.pop();
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "RUS");

	cout << "Автор: Самаркина Евгения Андреевна\n";
	cout << "Группа: ПОВа - з22\n";

	int k = 3;

	vector<int> result = fold_strip_array(k);
	cout << "Результат для массива: ";
	print_vector(result);

	vector<int> result1 = fold_strip_linked_list(k);
	cout << "Результат для связанного списка: ";
	print_vector(result1);

	vector<int> result2 = fold_strip_stl(k);
	cout << "Результат для STL: ";
	print_vector(result2);

	return 0;
}