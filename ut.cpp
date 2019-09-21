// ut.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ut.h"


// This is an example of an exported variable
UT_API int nut=0;

// This is an example of an exported function.
UT_API int fnut(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Cut::Cut()
{
    return;
}
