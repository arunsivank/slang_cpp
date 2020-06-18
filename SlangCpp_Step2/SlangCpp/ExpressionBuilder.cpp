#include "ExpressionBuilder.h"
#include "RDParser.h"


ExpressionBuilder::ExpressionBuilder(TCHAR* pStr)
{
    int len = (int)_tcslen(pStr) + 1;
    m_pExpString = (TCHAR*)malloc(len * sizeof(TCHAR));

    _tcscpy_s(m_pExpString, len, pStr);
}

Expression* ExpressionBuilder::GetExpression()
{
    try
    {
        RDParser* pParser = new RDParser(m_pExpString);
        return pParser->CallExp();
    }
    catch (_exception)
    {
        return nullptr;
    }
}
