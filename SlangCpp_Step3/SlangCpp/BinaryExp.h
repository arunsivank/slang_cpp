#pragma once
#include "Expression.h"
#include "Includes.h"

using namespace std;

class BinaryExp :
	public Expression
{
public:
	BinaryExp(LANG_OPERATOR opr, Expression* pExp1, Expression* pExp2);
	virtual ~BinaryExp();

public:
	virtual double Evaluate(const RuntimeContext*);
	virtual Expression* Clone();

private:
	Expression* _exp1;
	Expression* _exp2;
	LANG_OPERATOR _operator;
};

