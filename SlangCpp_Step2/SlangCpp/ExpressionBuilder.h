#pragma once
#include "AbstractBuilder.h"
#include "Expression.h"
#include <tchar.h>

class ExpressionBuilder :
	public AbstractBuilder
{
public:
	ExpressionBuilder(TCHAR* pStr);
	Expression* GetExpression();

private:
	TCHAR* m_pExpString;
};

