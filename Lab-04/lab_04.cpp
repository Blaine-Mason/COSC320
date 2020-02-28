#include <iostream>
#include <stack>
#include <string>
#include "d_tnode.h"
#include "d_tnode1.h"
#include "inf2pstf.h"

tnode<char> *buildExpTree(const string& exp);
void prefixoutput(tnode<char> *exp);
void postorderT(tnode<char> *expr);
void preorderT(tnode<char> *expr);

/*
* File Name: Lab_04.cpp
* Author: Blaine Mason
* Assignment: Lab-04
*/



int main(){

	tnode<char> *oneponeTree;
	tnode<char> *oneptwoTree;
	tnode<char> *onepthreeTree;

	//The infix expressions asked to convert to pre-order and post order
	string uno = "a*b";
	string dos = "a+b+c";
	string tres = "a+b*c/d-e";

	//Convert to postfix to be passed into buildExpTree
	infix2Postfix one(uno);
	infix2Postfix two(dos);
	infix2Postfix three(tres);
	uno = one.postfix();
	dos = two.postfix();
	tres = three.postfix();

	//Construct the Expression Trees
	oneponeTree = buildExpTree(uno);
	oneptwoTree = buildExpTree(dos);
	onepthreeTree = buildExpTree(tres);


	/*
	* Output the Pre-Order and Post-Order
	*/
	std::cout << "Pre-Order" << std::endl;
	preorderT(oneponeTree);
  	std::cout << std::endl;
	preorderT(oneptwoTree);
  	std::cout << std::endl;
	preorderT(onepthreeTree);
	std::cout << std::endl;

	std::cout << "Post-Order" << std::endl;
	postorderT(oneponeTree);
  	std::cout << std::endl;
	postorderT(oneptwoTree);
  	std::cout << std::endl;
	postorderT(onepthreeTree);
	std::cout << std::endl;



	//Take an expression from the user
	string user_exp;
	std::cout << "Enter the expression: ";
	std::cin >> user_exp;

	//Convert to postfix to build an expression tree
	infix2Postfix usr(user_exp);
	user_exp = usr.postfix();
	
	//Build expression tree
	tnode<char> *user_Input;
	user_Input = buildExpTree(user_exp);
	
	//Output Prefix and Postfix form 
	std::cout << "Prefix form: ";
	prefixoutput(user_Input);
	std::cout << std::endl;
	std::cout << "Postfix form: ";
	postorderT(user_Input);
	std::cout << std::endl;


	int size = user_exp.length();
	//Display the Created tree
	std::cout << "Expression tree: " << std::endl;
	displayTree(user_Input, size);
  

	return 0;
}



/*
* IN: tnode
* OUT: Void
* Method: Outputs the given expression in 
*		  pre-order
*/
void preorderT(tnode<char> *expr){
	if(!expr){
		return;
	}else{
		//NLR
		std::cout << expr->nodeValue << " ";
		postorderT(expr->left);
		postorderT(expr->right);
	}
}

/*
* IN: tnode
* OUT: Void
* Method: Outputs the given expression in 
*		  post-order
*/
void postorderT(tnode<char> *expr){
	if(!expr){
		return;
	}else{
		//LRN
		postorderT(expr->left);
		postorderT(expr->right);
		std::cout << expr->nodeValue << " ";
	}
}

/*
* IN: tnode
* OUT: Void
* Method: Outputs the given expression in 
*		  prefix
*/
void prefixoutput(tnode<char> *exp){
	if(!exp){
		return;
	}
	std::cout << exp->nodeValue << " ";
	prefixoutput(exp->left);
	prefixoutput(exp->right);
}
	
	

tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();
		
			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}
