#pragma once
#include "Expression.h"
#include "Includes.h"

using namespace std;

class UnaryExp :
	public Expression
{
public:
	UnaryExp(LANG_OPERATOR opr, shared_ptr<Expression> pExp1);

public:
	double virtual Evaluate(const RuntimeContext*);

private:
	shared_ptr<Expression> _exp1;
	LANG_OPERATOR _operator;

};

