#include "BinaryExp.h"

BinaryExp::BinaryExp(LANG_OPERATOR opr, Expression* pExp1, Expression* pExp2)
{
	_operator = opr;
	if (!pExp1 || !pExp2)
		throw;
	
	_exp1 = pExp1->Clone();
	_exp2 = pExp2->Clone();
}

BinaryExp::~BinaryExp()
{
	delete _exp1;
	delete _exp2;
}


double BinaryExp::Evaluate(const RuntimeContext* pRuntime)
{
	switch (_operator)
	{
	case LANG_OPERATOR::PLUS:
		return _exp1->Evaluate(pRuntime) + _exp2->Evaluate(pRuntime);
	case LANG_OPERATOR::MINUS:
		return _exp1->Evaluate(pRuntime) - _exp2->Evaluate(pRuntime);
	case LANG_OPERATOR::DIV:
		return _exp1->Evaluate(pRuntime) / _exp2->Evaluate(pRuntime);
	case LANG_OPERATOR::MUL:
		return _exp1->Evaluate(pRuntime) * _exp2->Evaluate(pRuntime);
	default:
		return 0;
	}
}

Expression* BinaryExp::Clone()
{
	return new BinaryExp(_operator, _exp1, _exp2);
}
