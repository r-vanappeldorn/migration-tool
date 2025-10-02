#include <migrationtool/create_migration.h>
#include <migrationtool/string_utils.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  enum MODE { CREATE_MIGRATION, UP, DOWN, MODE_UNKNOWN };

  const char *allowed[] = {
      "create_migration",
      "up",
      "down",
      NULL,
  };

  enum MODE selectedMode;
  for (int i = 1; i < argc; i++) {
    int j = findIndexOfString(argv[i], allowed);
    if (j < 0) {
      continue;
    }

    selectedMode = (enum MODE)j;
  }

  if (selectedMode == MODE_UNKNOWN) {
    printf("Ivalid argument provided\n");

    return 1;
  }

  switch (selectedMode) {
  case CREATE_MIGRATION:
    return createMigration();
    break;
  }

  return 0;
}
