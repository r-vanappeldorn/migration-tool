#include <migrationtool/string_utils.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  const char *allowed[] = {
      "create_migration",
      "up",
      "down",
      NULL,
  };

  for (int i = 0; i < argc; i++) {
    if (stringInArray(argv[i], allowed)) {
      printf("%s is allowed\n", argv[i]);
    }
  }

  return 0;
}
