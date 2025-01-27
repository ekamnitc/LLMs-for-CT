#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

vector<string> get_split_string()
{
	string input, buffer;
	getline(cin, input);
	stringstream ss(input);
	vector<string> result;
	while (getline(ss, buffer, ' '))
		result.push_back(buffer);
	return result;
}

int main()
{
	stack<int> value_stack;
	vector<string> list = get_split_string();
	int left_operand, right_operand;

	for (vector<string>::iterator it = list.begin();
		it != list.end(); it++) {
		switch (it->at(0))
		{
		case '+': // operator +
			right_operand = value_stack.top(); value_stack.pop();
			left_operand = value_stack.top(); value_stack.pop();
			value_stack.push(left_operand + right_operand);
			break;
		case '-': // operator -
			right_operand = value_stack.top(); value_stack.pop();
			left_operand = value_stack.top(); value_stack.pop();
			value_stack.push(left_operand - right_operand);
			break;
		case '*': // operator *
			right_operand = value_stack.top(); value_stack.pop();
			left_operand = value_stack.top(); value_stack.pop();
			value_stack.push(left_operand * right_operand);
			break;
		default: // operands
			value_stack.push(atoi(it->c_str()));
		}
	}
	
	cout << value_stack.top() << endl;
	return 0;
}