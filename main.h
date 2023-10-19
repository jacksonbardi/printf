#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
int _putint(int n);
int print_oc(va_list args);


int obtain_precision(cont char *format, int *i, va_list list);



#endif
