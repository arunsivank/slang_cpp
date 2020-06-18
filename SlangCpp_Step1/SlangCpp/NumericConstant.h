#pragma once
#include "Expression.h"
class NumericConstant :
	public Expression
{
public:
	NumericConstant(double val) { _value = val; }
public:
	double virtual Evaluate(const RuntimeContext*) {
		return _value;
	}

private:
	double _value;
};

