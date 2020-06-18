#pragma once
#include <tchar.h>
#include <memory>

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
        TOK_NULL, // End of string
        TOK_PRINT, // Print Statement
        TOK_PRINTLN, // PrintLine
        TOK_UNQUOTED_STRING,
        TOK_SEMI
    };

    struct  ValueTable
    {
        CLexer::TOKEN tok; //token id
        TCHAR* Value;
        ValueTable(CLexer::TOKEN t, const TCHAR* val)
        {
            tok = t;

            int len = (int)_tcslen(val) + 1;
            Value = (TCHAR*)malloc(len * sizeof(TCHAR));

            _tcscpy_s(Value, len, val);
        }
    };

public:
	CLexer(TCHAR* pExpr);
    TOKEN GetToken();
    double GetNumber();

private:
    TCHAR*  m_pExpr;
    TCHAR*  m_pLastStr;
    int     m_Index;        // index into a character
    int     m_Length;       // Length of the string
    double  m_Number;       // Last grabbed number from the stream
    ValueTable** pValueTableList; // This will hole the 
};

