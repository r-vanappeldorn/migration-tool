#include "migrationtool/string_utils.h"
#include <migrationtool/create_migration.h>
#include <stdio.h>
#include <string.h>

int createMigration() {
  printf("Provided a migration name\n");

  char migrationNameInput[30];
  scanf("%29[^\n]", migrationNameInput);

  char filename[strlen(migrationNameInput)];
  sprintf(filename, "%s.sql\n", convertToSnakeCase(migrationNameInput));

  printf("%s\n", filename);

  return 0;
}
