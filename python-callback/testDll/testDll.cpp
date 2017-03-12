// testDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "testDll.h"

outputcallback2	gCb;

TESTDLL_API int function1(void (*outputcallback)(const A_t* a, void* b),
	void* param)
{
	A_t obj;
	obj.a1 = "hello";
	obj.a2 = 4;

	outputcallback(&obj, param);
	return 1;
}

TESTDLL_API int function2( outputcallback2 cb, void* data )
{
	return 0;
}

TESTDLL_API void sub( outputcallback2 cb )
{
	gCb = cb;
}

TESTDLL_API void function3( void* data )
{
	A_t obj;
	obj.a1 = "world!";
	obj.a2 = 5;
	gCb(&obj, data);
}
