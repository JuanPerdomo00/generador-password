#include "includes/genpass.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *generate_password(int length) {
  if (length <= 0)
    return NULL;

  char *password = malloc(length + 1);
  if (!password)
    return NULL;

  srand(time(NULL));
  if (length == 8) {
    char all_chars[512] = "";
    for (int i = 0; ARR_STRINGS[i] != NULL; i++) {
      strcat(all_chars, ARR_STRINGS[i]);
    }

    for (int i = 0; i < length; i++) {
      password[i] = all_chars[rand() % strlen(all_chars)];
    }
  } else {
    for (int i = 0; i < length; i++) {
      const char *set = ARR_STRINGS[rand() % 5];
      password[i] = set[rand() % strlen(set)];
    }
  }

  password[length] = '\0';
  return password;
}
