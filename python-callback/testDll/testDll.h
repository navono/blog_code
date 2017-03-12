// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TESTDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TESTDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESTDLL_EXPORTS
#define TESTDLL_API __declspec(dllexport)
#else
#define TESTDLL_API __declspec(dllimport)
#endif

struct A_s
{
	const char* a1;
	unsigned int a2;
};

#ifdef __cplusplus
extern "C" {
#endif

typedef struct A_s A_t;
typedef void(*outputcallback2)(void* a, void* b);


TESTDLL_API int function1(void (*outputcallback)(const A_t* a, void* b), void* param);

TESTDLL_API int function2(outputcallback2 cb, void* data);

TESTDLL_API void sub(outputcallback2 cb);
TESTDLL_API void function3(void* data);


#ifdef __cplusplus
}
#endif // __cplusplus