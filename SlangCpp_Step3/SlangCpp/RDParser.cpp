#include "RDParser.h"
#include "NumericConstant.h"
#include "Includes.h"
#include "UnaryExp.h"
#include "BinaryExp.h"


RDParser::RDParser(TCHAR* pExpr)
	: CLexer(pExpr)
    , Current_Token(TOKEN::ILLEGAL_TOKEN)
{

}
Expression* RDParser::CallExp()
{
	Current_Token = GetToken();
    return Exp();
}

CLexer::TOKEN RDParser::GetNext()
{
    Last_Token = Current_Token;
    Current_Token = GetToken();
    return Current_Token;
}

Expression* RDParser::Exp()
{
	Expression* pExp = Term();
    TOKEN l_token;
    while (Current_Token == TOKEN::TOK_PLUS || Current_Token == TOKEN::TOK_SUB)
    {
        l_token = Current_Token;
        Current_Token = GetToken();
        Expression* e1 = Exp();
        pExp = new BinaryExp(l_token == TOKEN::TOK_PLUS ? LANG_OPERATOR::PLUS : LANG_OPERATOR::MINUS, pExp, e1);

    }

	return pExp;
}
Expression* RDParser::Term()
{
	Expression* pExp = Factor();
    TOKEN l_token;

    while (Current_Token == TOKEN::TOK_MUL || Current_Token == TOKEN::TOK_DIV)
    {
        l_token = Current_Token;
        Current_Token = GetToken();

        Expression* e1 = Term();
        pExp = new BinaryExp(l_token == TOKEN::TOK_MUL ? LANG_OPERATOR::MUL : LANG_OPERATOR::DIV, pExp, e1);
    }

	return pExp;
}
Expression* RDParser::Factor()
{
	Expression* pExp = NULL;
	TOKEN l_token;

    if (Current_Token == TOKEN::TOK_DOUBLE)
    {

        pExp = new NumericConstant(GetNumber());
        Current_Token = GetToken();

    }
    else if (Current_Token == TOKEN::TOK_OPAREN)
    {

        Current_Token = GetToken();

        pExp = Exp();  // Recurse

        if (Current_Token != TOKEN::TOK_CPAREN)
        {
            printf("Missing Closing Parenthesis\n");
            throw;
        }
        Current_Token = GetToken();
    }

    else if (Current_Token == TOKEN::TOK_PLUS || Current_Token == TOKEN::TOK_SUB)
    {
        l_token = Current_Token;
        Current_Token = GetToken();
        pExp = Factor();

        pExp = new UnaryExp(l_token == TOKEN::TOK_PLUS ? LANG_OPERATOR::PLUS : LANG_OPERATOR::MINUS, pExp);
    }
    else
    {
        printf("Illegal Token");
        throw;
    }

	return pExp;
}

/// <summary>
///   The new Parser entry point
/// </summary>
/// <returns></returns>
list<Statement*> RDParser::Parse()
{
    GetNext();  // Get the Next Token
    //
    // Parse all the statements
    //
    return StatementList();
}

list<Statement*> RDParser::StatementList()
{
    list<Statement*> arr;
    while (Current_Token != TOKEN::TOK_NULL)
    {
        Statement* temp = GetStatement();
        if (temp != NULL)
        {
            arr.push_back(temp);
        }
    }
    return arr;
}

Statement* RDParser::GetStatement()
{
    Statement* pStat = NULL;

    if (Current_Token == TOKEN::TOK_PRINT) {
        pStat = ParsePrintStatement();
        GetNext();
    }
    else if (Current_Token == TOKEN::TOK_PRINTLN) {
        pStat = ParsePrintLineStatement();
        GetNext();
    }

    return pStat;
}

Statement* RDParser::ParsePrintStatement()
{
    GetNext();
    Expression* pExp = Exp();

    if (Current_Token != TOKEN::TOK_SEMI)
    {
        throw exception("; is missing");
    }

    return new PrintStatement(pExp);
}

Statement* RDParser::ParsePrintLineStatement()
{
    GetNext();
    Expression* pExp = Exp();

    if (Current_Token != TOKEN::TOK_SEMI)
    {
        throw exception("; is missing");
    }

    return new PrintLineStatement(pExp);
}