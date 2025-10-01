#include "string_utils.h"
#include <string.h>

bool stringInArray(const char *needle, const char *const *array) {
  for (size_t i = 0; array[i] != NULL; i++) {
    if (strcmp(array[i], needle) == 0) {
      return true;
    }
  }

  return false;
}
