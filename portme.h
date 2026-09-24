// Simple definitions to make Solaris code compile.
//
// Arnold Robbins
// arnold@skeeve.com
// September, 2026
// Public domain

typedef unsigned short ushort_t;
typedef unsigned int uint_t;
typedef unsigned char uchar_t;
#define __NORETURN	// nothing
#include <libintl.h>
#include <wctype.h>
#include <unistd.h>
#define REG_OK (0)
#define REG_EFATAL	REG_EEND
struct qelem {
	struct qelem *q_forw;
};
extern int wsprintf(wchar_t *s, size_t sz, const char *format, ...);
