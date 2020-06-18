#include "UnaryExp.h"

UnaryExp::UnaryExp(LANG_OPERATOR opr, Expression* pExp1)
{
	if (!pExp1)
		throw;

	_operator = opr;
	_exp1 = pExp1->Clone();
}

UnaryExp::~UnaryExp()
{
	delete _exp1;
}

double UnaryExp::Evaluate(const RuntimeContext* pRuntime)
{
	switch (_operator)
	{
	case LANG_OPERATOR::PLUS:
		return _exp1->Evaluate(pRuntime);
	case LANG_OPERATOR::MINUS:
		return -1 * _exp1->Evaluate(pRuntime);
	default:
		return 0;
	}
}

Expression* UnaryExp::Clone()
{
	return new UnaryExp(_operator, _exp1);
}
