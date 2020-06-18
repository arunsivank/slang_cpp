#pragma once

#include "RuntimeContext.h"
#include "Expression.h"

class Statement
{

public:
	Statement() {}
	virtual bool Execute(RuntimeContext* con) = 0;
};


class PrintStatement : public Statement
{
public:
	PrintStatement(Expression* pExp);
	virtual bool Execute(RuntimeContext* con);

private:
	Expression* m_pExpr;
};

class PrintLineStatement : public Statement
{
public:
	PrintLineStatement(Expression* pExp);
	virtual bool Execute(RuntimeContext* con);

private:
	Expression* m_pExpr;
};

