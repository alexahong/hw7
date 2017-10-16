/*****************************************************************
	Author: Jason Wherry	Date: 3-24-17	Class: CS 2401

	Professor: Jon Dolan	Assignment: Lab9	File: stackmain.cc

	Description: This program manipulates a calulator application
	 by using a stack and other functions to traverse/change
	 the stack's data.
******************************************************************/
#include <stack> 
#include <iostream>
#include "calc_useful.h"

using namespace std; 

int main(){
	stack<int> numbers;
	int count = 0;
	int onenum,twonum;
	char c;
 	bool error = false;

	cout << "Please enter an expression; enter 'q' to quit:  ";

	while(true)
	{
		c = cin.get();
		if(c == 'q' || c == 'Q')
		{
			break;
		}

		error = false;
		while(c != '\n')
		{
			if(isdigit(c)) //checks for operators or digits
			{
				cin.putback(c);
				cin >> onenum;
				numbers.push(onenum);
				count++;
			}
			else if(isop(c))   //c == '+' || c == '-' || c == '*' || c == '/'
			{
				if(count > 1)
				{
					count--;

					onenum = numbers.top(); //references the first number in the stack
					numbers.pop(); //removes the first number, but onenum is holding the value

					twonum = numbers.top(); //references the new first number in the stack
					numbers.pop(); //removes the new first number, but twonum is holding the value

					numbers.push(evaluate(twonum, onenum, c)); //puts the result at the top of the stack
				}
				else
				{
					error = true;
				}
			}
			c = cin.get();
		}
		if(!error && count == 1)
		{	//outputs the answer after the expression has been evaluated
			cout << "Answer: " << numbers.top() << endl;
			numbers.pop();
			count--;
		}
		else
		{
			cout << "Error" << endl;
		}
		cout << "Please enter an expression; enter 'q' to quit:  ";
	}
 return 0;
}


