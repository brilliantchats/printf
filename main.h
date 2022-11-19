#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int string_conversion(char *str);
int print_char(char c);
int char_str_conversion(char character, va_list args);

#endif /* MAIN_H */
