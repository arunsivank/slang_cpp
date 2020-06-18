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