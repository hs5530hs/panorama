// File: debugutils.hh
// Date: Sat May 04 12:03:06 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>


#pragma once
#include <string>

/*
 *#define P(a) std::cout << (a) << std::endl
 *#define PP(s, a) std::cout << s << " " << (a) << std::endl
 */


void __m_assert_check__(bool val, const char *expr,
		const char *file, const char *func, int line);


void error_exit(const char *msg) __attribute__((noreturn));

inline void error_exit(const std::string& s) __attribute__((noreturn));
void error_exit(const std::string& s) {
	error_exit(s.c_str());
}

// keep print_debug
#define print_debug(fmt, ...) \
			__print_debug__(__FILE__, __func__, __LINE__, fmt, ## __VA_ARGS__)


void __print_debug__(const char *file, const char *func, int line, const char *fmt, ...)
	__attribute__((format(printf, 4, 5)));

#ifdef DEBUG

#define m_assert(expr) \
	__m_assert_check__((expr), # expr, __FILE__, __PRETTY_FUNCTION__, __LINE__)



#else

//#define print_debug(fmt, ...)

#define m_assert(expr)

#endif
