#ifndef _IFSTATEMEMT_
#define  _IFSTATEMENT_
#include <stack>
#include "Print.h"
#include "Statement.h"
class IfStatement :public Print
{
private:
	stack<Statement> IfStruct;
public:
	IfStatement(const stack<Statement>& iniIfstruct);
	virtual void draw(int middle, int length, int lastLength, stack<Statement>& ifStruct);
};
#endif // !_IFSTATEMEMT_
