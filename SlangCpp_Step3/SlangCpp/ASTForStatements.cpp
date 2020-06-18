#include "ASTForStatements.h"

PrintStatement::PrintStatement(Expression* pExp)
    : m_pExpr(NULL)
{
    m_pExpr = pExp->Clone();
}
/// <summary>
/// 
/// </summary>
/// <param name="con"></param>
/// <returns></returns>
bool PrintStatement::Execute(RuntimeContext* con)
{
    printf("%f", m_pExpr->Evaluate(con));
    return true;
}

PrintLineStatement::PrintLineStatement(Expression* pExp)
    : m_pExpr(NULL)
{
    m_pExpr = pExp->Clone();
}

bool PrintLineStatement::Execute(RuntimeContext* con)
{
    printf("%f\n", m_pExpr->Evaluate(con));
    return true;
}
