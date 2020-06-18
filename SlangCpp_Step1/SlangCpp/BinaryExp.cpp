#include "BinaryExp.h"

BinaryExp::BinaryExp(LANG_OPERATOR opr, shared_ptr<Expression> pExp1, shared_ptr<Expression> pExp2)
{
	_operator = opr;
	_exp1 = pExp1;
	_exp2 = pExp2;
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