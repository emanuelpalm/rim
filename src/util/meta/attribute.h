#ifndef UTIL_META_ATTRIBUTE_H
#define UTIL_META_ATTRIBUTE_H

/// Compiler attributes.
///
/// This files contains various macros that may be invoked to signify that
/// functions or variables have special properties. Each Attribute comes with
/// an example of how it is used. The attributes are only honored on supported
/// platforms, and must therefore only be used as a means to improve code
/// analysis or performance.
///
/// \file

#if __GNUC__ >= 3
#define ATTRIBUTE_NORETURN() __attribute__((__noreturn__))
#elif _MSC_VER => 1400
#define ATTRIBUTE_NORETURN() __declspec(noreturn)
#elif __COMPCERT__ >= 1
#define ATTRIBUTE_NORETURN() __attribute__(noreturn)
#else
/// Indicates that a function never returns after being called.
///
/// ## Example
///
/// ```c
/// void panic(const char *message) ATTRIBUTE_NORETURN();
/// ```
#define ATTRIBUTE_NORETURN()
#endif

#if __GNUC__ >= 3
#define ATTRIBUTE_FORMAT_PRINTF(fmt, va_args) \
    __attribute__((format (printf, (fmt), (va_args))))
#else
/// Indicates that a function takes a format string and format arguments
/// compatible with those accepted by printf().
///
/// ## Example
///
/// ```c
/// void log_printf(int logLevel, const char *format, ...)
///     ATTRIBUTE_FORMAT_PRINTF(2, 3);
/// ```
///
/// \param fmt     The position of the format parameter, starting from 1.
/// \param va_args The position of the variadic parameter, starting from 1.
#define ATTRIBUTE_FORMAT_PRINTF(fmt, va_args)
#endif

#endif
