#pragma once
#include "Expression.h"
#include "Includes.h"

using namespace std;

class BinaryExp :
	public Expression
{
public:
	BinaryExp(LANG_OPERATOR opr, shared_ptr<Expression> pExp1, shared_ptr<Expression> pExp2);

public:
	double virtual Evaluate(const RuntimeContext*);

private:
	shared_ptr<Expression> _exp1, _exp2;
	LANG_OPERATOR _operator;
};

