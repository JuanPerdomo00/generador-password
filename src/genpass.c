/*
 * Simple code for a password generator.
 * CreationDate: 2022-04-08
 * Copyright (C) 2022 Jakepy Perdomo <j4kyjak3@protonmail.com>
 *
 * Comments welcome.
 * Permission granted for non-commercial use and distribution provided that
 * this notice is preserved. Any questions, write to me — or maybe I'm asleep, jsjs.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "includes/genpass.h"
#include "includes/random.h"
#include <stdlib.h>
#include <string.h>

char *generate_password(int length) {
  if (length <= 0)
    return NULL;

  char *password = malloc(length + 1);
  if (!password)
    return NULL;

  if (length == 8) {
    size_t total_size = 0;
    for (int i = 0; ARR_STRINGS[i] != NULL; i++) {
      total_size += strlen(ARR_STRINGS[i]);
    }

    char *all_chars = malloc(total_size + 1);
    if (!all_chars) {
      free(password);
      return NULL;
    }

    all_chars[0] = '\0';
    size_t pos = 0;
    for (int i = 0; ARR_STRINGS[i] != NULL; i++) {
      size_t len = strlen(ARR_STRINGS[i]);
      if (pos + len > total_size) {
        free(all_chars);
        free(password);
        return NULL;
      }
      memcpy(all_chars + pos, ARR_STRINGS[i], len);
      pos += len;
    }
    all_chars[pos] = '\0';

    for (int i = 0; i < length; i++) {
      password[i] = all_chars[secure_random_int(total_size)];
    }
    free(all_chars);
  } else {
    for (int i = 0; i < length; i++) {
      const char *set = ARR_STRINGS[secure_random_int(5)];
      password[i] = set[secure_random_int(strlen(set))];
    }
  }

  password[length] = '\0';
  return password;
}
