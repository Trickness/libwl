/*
 * Copyright (C) 2014  Wiky L
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with main.c; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include "wstring.h"
#include "m4.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char *w_strdup(const char *str)
{
	WL_RETURN_VAL_IF_FAIL(str != NULL, NULL);
	return strdup(str);
}

char *w_strndup(const char *str, int n)
{
	WL_RETURN_VAL_IF_FAIL(str != NULL, NULL);
	if (n < 0) {
		return strdup(str);
	}
	return strndup(str, n);
}

char *w_strdup_printf(const char *format, ...)
{
	WL_RETURN_VAL_IF_FAIL(format != NULL, NULL);

	va_list vl;
	char buf[LARGE_BUF];

	va_start(vl, format);

	vsnprintf(buf, LARGE_BUF, format, vl);

	va_end(vl);

	return w_strdup(buf);
}
