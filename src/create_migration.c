#include "migrationtool/string_utils.h"
#include <ctype.h>
#include <dirent.h>
#include <limits.h>
#include <linux/limits.h>
#include <migrationtool/create_migration.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int createMigration() {
  const char *dir = "migrations";
  char cwd[PATH_MAX];
  struct stat st = {0};

  if (IS_UNIX != 1 || getcwd(cwd, sizeof cwd) == NULL) {
    fprintf(stderr, "%s os must be unix based\n", dir);

    return 1;
  }

  if (stat(dir, &st) == -1) {
    printf("Created migrations directory %s/%s\n", cwd, dir);
    mkdir(dir, 0700);
  } else if (!S_ISDIR(st.st_mode)) {
    fprintf(stderr, "%s exists but is not a directory\n", dir);

    return 1;
  }

  printf("Provided a migration name\n");
  char migrationNameInput[255];
  scanf("%254[^\n]", migrationNameInput);

  char filename[strlen(migrationNameInput)];
  toSnakeCase(filename, sizeof filename, migrationNameInput);

  int id = 1;
  char migrationsPath[strlen(cwd) + strlen(dir)];
  sprintf(migrationsPath, "%s/%s", cwd, dir);
  int result = getNextId(migrationsPath, filename);
  if (result == -1) {
    return 0;
  }

  id = result;

  char idStr[5];
  getIdStrFormat(idStr, id);

  int pathBufSize =
      strlen(cwd) + strlen(dir) + strlen(idStr) + strlen(filename);

  char upFilePath[pathBufSize];
  sprintf(upFilePath, "%s/%s/%s_%s_up.sql", cwd, dir, idStr, filename);

  FILE *upFile = fopen(upFilePath, "w");
  fclose(upFile);
  printf("%s\n", upFilePath);

  char downFilePath[pathBufSize];
  sprintf(downFilePath, "%s/%s/%s_%s_down.sql", cwd, dir, idStr, filename);

  FILE *downFile = fopen(downFilePath, "w");
  fclose(downFile);
  printf("%s\n", downFilePath);

  return 0;
}

int getNextId(const char *migrationsPath, const char *filename) {
  DIR *dir;
  struct dirent *en;
  dir = opendir(migrationsPath);
  if (!dir) {
    printf("not a dir: %s\n", migrationsPath);

    return -1;
  }

  int lastId = 0;
  while ((en = readdir(dir)) != NULL) {
    if (strcmp("..", en->d_name) == 0 || strcmp(".", en->d_name) == 0) {
      continue;
    }

    if (strstr(en->d_name, filename)) {
      printf("Migration name must be unique. name %s already in use\n",
             filename);

      return -1;
    }

    char idBuf[5];
    sprintf(idBuf, "%.4s", en->d_name);

    if (isId(idBuf)) {
      int fileId = atoi(idBuf);
      if (lastId < fileId) {
        lastId = fileId;
      }
    }
  }
  closedir(dir);

  return lastId + 1;
}

bool isId(const char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }

  return true;
}

void getIdStrFormat(char *buf, int id) {
  snprintf(buf, 5, "%04d", id);
  buf[4] = '\0';
}
