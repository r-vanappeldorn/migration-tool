#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>
#include <stddef.h>

bool stringInArray(const char *needle, const char *const *array);

int findIndexOfString(const char *needle, const char *const *array);

void toSnakeCase(char *buff, size_t size, const char *str);

#endif
