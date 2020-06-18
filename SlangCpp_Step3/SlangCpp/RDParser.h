#pragma once
#include "CLexer.h"
#include "Expression.h"
#include "ASTForStatements.h"
#include <list> // for list operations

using namespace std;

class RDParser :
	public CLexer
{
public:
	RDParser(TCHAR* pExpr);
	TOKEN GetNext();
	Expression* CallExp();
	Expression* Exp();
	Expression* Term();
	Expression* Factor();

	std::list<Statement*> Parse();
	std::list<Statement*> StatementList();
	Statement* GetStatement();
	Statement* ParsePrintLineStatement();
	Statement* ParsePrintStatement();

private:
	TOKEN Current_Token;
	TOKEN Last_Token;
};

