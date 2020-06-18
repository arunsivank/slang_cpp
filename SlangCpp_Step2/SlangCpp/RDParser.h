#pragma once
#include "CLexer.h"
#include "Expression.h"

class RDParser :
	public CLexer
{
public:
	RDParser(TCHAR* pExpr);
	Expression* CallExp();
	Expression* Exp();
	Expression* Term();
	Expression* Factor();

private:
	TOKEN Current_Token;

};

