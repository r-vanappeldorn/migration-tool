#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>

bool stringInArray(const char *needle, const char *const *array);

int findIndexOfString(const char *needle, const char *const *array);

char *convertToSnakeCase(const char *str);

#endif
