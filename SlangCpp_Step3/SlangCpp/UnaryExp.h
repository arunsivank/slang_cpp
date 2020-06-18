#pragma once
#include "Expression.h"
#include "Includes.h"

using namespace std;

class UnaryExp :
	public Expression
{
public:
	UnaryExp(LANG_OPERATOR opr, Expression* pExp1);
	virtual ~UnaryExp();

public:
	virtual double Evaluate(const RuntimeContext*);
	virtual Expression* Clone();

private:
	Expression* _exp1;
	LANG_OPERATOR _operator;

};

