#pragma once

#include <memory>
#include "RuntimeContext.h"

class Expression
{
public:
    double virtual Evaluate(const RuntimeContext*) = 0;
};

