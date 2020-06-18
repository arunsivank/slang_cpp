// SlangCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>

#include "BinaryExp.h"
#include "UnaryExp.h"
#include "NumericConstant.h"
#include "ExpressionBuilder.h"

int main()
{
    
    Expression* pExp = new BinaryExp(LANG_OPERATOR::MUL
        , new NumericConstant(5) 
        , new NumericConstant(10));
    
    double d = pExp->Evaluate(new RuntimeContext());

    printf("Multiplication value %f", d);
   

    ExpressionBuilder* b = new ExpressionBuilder((TCHAR*)L"-2*(-3+3)");
    Expression* e = b->GetExpression();
    printf("\nExpression Builder %f", e->Evaluate(NULL));

    // a^2 + 2ab + b^2 (a = 5, b = 3) = 25 + 30 + 9 = 64
    b = new ExpressionBuilder((TCHAR*)L"(5 * 5)+(2*(5*3))+(3*3)");
    e = b->GetExpression();
    printf("\nExpression Builder %f", e->Evaluate(NULL));


    _getch();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
