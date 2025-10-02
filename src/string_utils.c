#include <ctype.h>
#include <migrationtool/string_utils.h>
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

char *convertToSnakeCase(const char *str) {
  int strLength = strlen(str);
  char *snakeCaseStr = malloc(strLength + 1);
  if (!snakeCaseStr) {
    return NULL;
  }

  for (int i = 0; i < strLength; i++) {
    if (isupper(str[i])) {
      snakeCaseStr[i] = tolower(str[i]);

      continue;
    }

    if (isspace(str[i])) {
      snakeCaseStr[i] = '_';

      continue;
    }

    snakeCaseStr[i] = str[i];
  }

  snakeCaseStr[strLength] = '\0';
  return snakeCaseStr;
}
