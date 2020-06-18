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
#include "RDParser.h"

void TestFirstScript()
{
    const TCHAR* pLine = _T("PRINTLINE 2*10;\r\n PRINTLINE 10;\r\n PRINT 2*10; PRINT 3848;\r\n");

    RDParser* p = new RDParser( const_cast<TCHAR*>(pLine));
    std::list<Statement*> arr = p->Parse();

    for(std::list<Statement*>::iterator it = arr.begin();
        it != arr.end();
        it++)
    {
        Statement *pS = *it;
        pS->Execute(NULL);
    }
}

int main()
{
    TestFirstScript();

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
