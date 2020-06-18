#include "UnaryExp.h"

UnaryExp::UnaryExp(LANG_OPERATOR opr, shared_ptr<Expression> pExp1)
{
	_operator = opr;
	_exp1 = pExp1;
}


double UnaryExp::Evaluate(const RuntimeContext* pRuntime)
{
	switch (_operator)
	{
	case LANG_OPERATOR::PLUS:
		return _exp1->Evaluate(pRuntime);
	case LANG_OPERATOR::MINUS:
		return-1 * _exp1->Evaluate(pRuntime);
	default:
		return 0;
	}
}