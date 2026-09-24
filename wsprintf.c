// Simple replacement for Solaris wsprintf() rourtine.
// Solaris does not have the sz argument.
//
// Arnold Robbins
// arnold@skeeve.com
// September, 2026
// Public domain

#include <string.h>
#include <wchar.h>
#include <stdarg.h>
#include <stdlib.h>

int
wsprintf(wchar_t *s, size_t sz, const char *format, va_list args)
{
	size_t n = strlen(format);
	wchar_t *wformat = malloc((n + 1) * sizeof(wchar_t));
	int i;
	int ret;

	for (i = 0; i < n; i++)
		wformat[i] = format[i];
	wformat[i] = L'\0';

	ret = vswprintf(s, sz, wformat, args);

	free(wformat);

	return ret;
}
