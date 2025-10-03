#ifndef CREATE_MIGRATION_H
#define CREATE_MIGRATION_H

#include <stdbool.h>

#ifdef __unix__
#define IS_UNIX 1
#else
#define IS_UNIX 0
#endif

bool isId(const char *str);

int getNextId(const char *migrationsPath, const char *filename);

void getIdStrFormat(char *buf, int id);

int createMigration();

#endif
