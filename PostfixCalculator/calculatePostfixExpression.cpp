#include <string>
#include <stack>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length){
	//if the pushed length is 0 or 2, there is no possibility that an operation can be done, return 0
	bool operandPushed = false;
	if(length < 3 && length != 1){
		return 0;
	}
    stack<int> temp;
	for(int i=0;i<length;i++){
		//if we have an operand, push it to the stack
		if(expression[i] >= "0" && expression[i] <= "9"){
			temp.push(stoi(expression[i]));
			operandPushed = true;
		}
		//special case where only operators are pushed
		else if(!operandPushed){
			return 0;
		}
		//if we have any operator, pop the top 2 elements of the stack, and perform
		//the given operation, then push the new operand to the stack
		else if(expression[i] == "+"){
			int a = temp.top();
			temp.pop();
			int b = temp.top();
			temp.pop();
			a += b;
			temp.push(a);
		}
		else if(expression[i] == "-"){
			int a = temp.top();
			temp.pop();
			int b = temp.top();
			temp.pop();
			a = b-a;
			temp.push(a);
		}
		else if(expression[i] == "*"){
			int a = temp.top();
			temp.pop();
			int b = temp.top();
			temp.pop();
			a = a*b;
			temp.push(a);
		}
		else if(expression[i] == "/"){
			int a = temp.top();
			temp.pop();
			int b = temp.top();
			temp.pop();
			a = b/a;
			temp.push(a);
		}
		else if(expression[i] == "%"){
			int a = temp.top();
			temp.pop();
			int b = temp.top();
			temp.pop();
			a = b%a;
			temp.push(a);
		}
	}
	//if there are a proper number of operators, only 1 value should remain in the stack
	//so if the size is greater than 1, return 0. Otherwise, return the 1 value left in the stack
	if(temp.size() > 1){
		return 0;
	}
	else{
		return temp.top();
	}
}