#include <ctype.h>
#include <migrationtool/string_utils.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

bool stringInArray(const char *needle, const char *const *array) {
  for (size_t i = 0; array[i] != NULL; i++) {
    if (strcmp(array[i], needle) == 0) {
      return true;
    }
  }

  return false;
}

int findIndexOfString(const char *needle, const char *const *array) {
  for (size_t i = 0; array[i] != NULL; i++) {
    if (strcmp(needle, array[i]) == 0) {
      return i;
    }
  }

  return -1;
}

void toSnakeCase(char *buff, size_t size, const char *str) {
  if (!str || !buff || !size) {
    return;
  }

  size_t len = strlen(str);

  for (size_t i = 0; i < len; i++) {
    if (isupper(str[i])) {
      buff[i] = tolower(str[i]);

      continue;
    }

    if (isspace(str[i])) {
      buff[i] = '_';

      continue;
    }

    buff[i] = str[i];
  }

  buff[len] = '\0';
}
