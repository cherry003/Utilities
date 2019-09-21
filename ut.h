// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the UT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// UT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UT_EXPORTS
#define UT_API __declspec(dllexport)
#else
#define UT_API __declspec(dllimport)
#endif

// This class is exported from the dll
class UT_API Cut {
public:
	Cut(void);
	// TODO: add your methods here.
};

extern UT_API int nut;

UT_API int fnut(void);
