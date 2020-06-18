#pragma once
#include <tchar.h>

class CLexer
{
public:
    enum class TOKEN
    {
        ILLEGAL_TOKEN = -1, // Not a Token
        TOK_PLUS = 1, // '+'
        TOK_MUL, // '*'
        TOK_DIV, // '/'
        TOK_SUB, // '-'
        TOK_OPAREN, // '('
        TOK_CPAREN, // ')'
        TOK_DOUBLE, // '('
        TOK_NULL // End of string
    };

public:
	CLexer(TCHAR* pExpr);
    TOKEN GetToken();
    double GetNumber();

private:
    TCHAR*  m_pExpr;
    int     m_Index;        // index into a character
    int     m_Length;       // Length of the string
    double  m_Number;       // Last grabbed number from the stream
};

