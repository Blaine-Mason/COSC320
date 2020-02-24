#include <iostream>
#include <stack>
#include <string>
#include "d_tnode.h"
#include "d_tnode1.h"


tnode<char> *buildExpTree(const string& exp);
void prefixoutput(tnode<char> *exp);
void postorderT(tnode<char> *expr);
void preorderT(tnode<char> *expr);





int main(){
	//tnode<char> *oneponeTree;
	//tnode<char> *oneptwoTree;
	tnode<char> *onepthreeTree;

	//string uno = "a*b";
	//string dos = "a+b*c";
	string tres = "ab*cd/+";

	//oneponeTree = buildExpTree(uno);
	//oneptwoTree = buildExpTree(dos);
	onepthreeTree = buildExpTree(tres);

	//preorderT(oneponeTree);
	//preorderT(oneptwoTree);
	preorderT(onepthreeTree);

	std::cout << std::endl;

	//postorderT(oneponeTree);
	//postorderT(oneptwoTree);
	postorderT(onepthreeTree);

	std::cout << std::endl;

	prefixoutput(onepthreeTree);

	std::cout << std::endl;
	return 0;
}




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

void prefixoutput(tnode<char> *exp){
	if(!exp){
		return;
	}else{
		prefixoutput(exp->left);
		prefixoutput(exp->right);
		std::cout << exp->nodeValue << " ";
	}
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