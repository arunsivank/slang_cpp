#pragma once

#include <memory>
#include "RuntimeContext.h"

class Expression
{
public:
    virtual double Evaluate(const RuntimeContext*) = 0;
    virtual Expression* Clone() = 0;
};

