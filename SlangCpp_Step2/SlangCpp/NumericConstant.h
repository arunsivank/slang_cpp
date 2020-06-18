#pragma once
#include "Expression.h"
class NumericConstant :
	public Expression
{
public:
	NumericConstant(double val) { _value = val; }
public:
	virtual double Evaluate(const RuntimeContext*) {
		return _value;
	}

	virtual Expression* Clone() {
		return new NumericConstant(_value);
	}

private:
	double _value;
};

