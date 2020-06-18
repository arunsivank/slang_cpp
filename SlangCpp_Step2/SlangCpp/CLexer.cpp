#include "CLexer.h"
#include <memory>

CLexer::CLexer(TCHAR* pExpr)
	: m_Index(0)
	, m_Number(0)
{
	m_Length = (int)_tcslen(pExpr) + 1;
	m_pExpr = (TCHAR*)malloc(m_Length * sizeof(TCHAR));

	_tcscpy_s(m_pExpr, m_Length, pExpr);
}

CLexer::TOKEN CLexer::GetToken()
{
    TOKEN tok = TOKEN::ILLEGAL_TOKEN;
    ////////////////////////////////////////////////////////////
    //
    // Skip the white space
    //
    while (m_Index < m_Length &&
        (m_pExpr[m_Index] == ' ' || m_pExpr[m_Index] == '\t'))
        m_Index++;
    //////////////////////////////////////////////
    //
    // End of string ? return NULL;
    //
    if (m_Index == m_Length)
        return TOKEN::TOK_NULL;
    /////////////////////////////////////////////////
    //
    //
    //
    switch (m_pExpr[m_Index])
    {
        case '+':
            tok = TOKEN::TOK_PLUS;
            m_Index++;
            break;
        case '-':
            tok = TOKEN::TOK_SUB;
            m_Index++;
            break;
        case '/':
            tok = TOKEN::TOK_DIV;
            m_Index++;
            break;
        case '*':
            tok = TOKEN::TOK_MUL;
            m_Index++;
            break;
        case '(':
            tok = TOKEN::TOK_OPAREN;
            m_Index++;
            break;
        case ')':
            tok = TOKEN::TOK_CPAREN;
            m_Index++;
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            int strStart = m_Index;
            while (m_Index < m_Length &&
                (m_pExpr[m_Index] == '0' ||
                    m_pExpr[m_Index] == '1' ||
                    m_pExpr[m_Index] == '2' ||
                    m_pExpr[m_Index] == '3' ||
                    m_pExpr[m_Index] == '4' ||
                    m_pExpr[m_Index] == '5' ||
                    m_pExpr[m_Index] == '6' ||
                    m_pExpr[m_Index] == '7' ||
                    m_pExpr[m_Index] == '8' ||
                    m_pExpr[m_Index] == '9'))
            {
                m_Index++;
            }

            // Alloc the size of the string
            int strLen = m_Index - strStart;
            TCHAR* pNumb = (TCHAR*)malloc((strLen + 1) * sizeof(TCHAR));
            _tcsncpy_s(pNumb, strLen + 1, (m_pExpr + strStart), strLen);

            m_Number = _tcstod(pNumb, NULL);
            tok = TOKEN::TOK_DOUBLE;
        }
        break;
        case '\0':
            break;
    default:
        printf("Error While Analyzing Tokens\n");
    }
    return tok;
}

double CLexer::GetNumber()
{
	return m_Number;
}
