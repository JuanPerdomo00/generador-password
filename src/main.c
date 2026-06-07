/*
 * Simple code for a password generator.
 * CreationDate: 2022-04-08
 * Copyright (C) 2022 Jakepy Perdomo <j4kyjak3@protonmail.com>
 *
 * Comments welcome.
 * Permission granted for non-commercial use and distribution provided that
 * this notice is preserved. Any questions, write to me — or maybe I'm asleep,
 * jsjs.
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

#include "includes/colors.h"
#include "includes/copyclip.h"
#include "includes/genpass.h"
#include "includes/strings.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef VERSION
#define VERSION "1.0.1"
#endif

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 10000

int parse_length(const char *str, int *length) {
  char *endptr;
  long val;

  if (!str || !length)
    return 1;

  errno = 0;
  val = strtol(str, &endptr, 10);

  if (errno != 0) {
    perror("strtol");
    return 1;
  }

  if (endptr == str) {
    fprintf(stderr, RED "Error:" RESET " '%s' is not a valid number.\n", str);
    return 1;
  }

  if (*endptr != '\0') {
    fprintf(stderr, RED "Error:" RESET " '%s' contains invalid characters.\n", str);
    return 1;
  }

  if (val < MIN_PASSWORD_LENGTH) {
    fprintf(stderr, RED "Error:" RESET " length must be at least %d.\n",
            MIN_PASSWORD_LENGTH);
    return 1;
  }

  if (val > MAX_PASSWORD_LENGTH) {
    fprintf(stderr, RED "Error:" RESET " length cannot exceed %d.\n",
            MAX_PASSWORD_LENGTH);
    return 1;
  }

  *length = (int)val;
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, RED "Use: " RESET GREEN "%s <length>" RESET "\n", argv[0]);
    fprintf(stderr, "Try '%s --help' for more information.\n", argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
    printf(GREEN "Password Generator " RESET "v%s\n", VERSION);
    printf("Written by: " CYAN "Jakepys\n" RESET);
    return 0;
  }

  if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    printf("\n" CYAN "Password Generator " RESET "v%s\n", VERSION);
    printf("Usage: %s <length>\n\n", argv[0]);
    printf("Options:\n");
    printf("  -h, --help      Show this help message\n");
    printf("  -v, --version   Show program version\n\n");
    printf("Arguments:\n");
    printf("  <length>        Password length (min: %d, max: %d)\n\n",
           MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    printf("Example:\n");
    printf("  %s 12\n\n", argv[0]);
    printf("This will generate a random password with 12 characters.\n");
    return 0;
  }

  int length = 0;
  if (parse_length(argv[1], &length) != 0) {
    return 1;
  }

  init_strings();
  char *pass = generate_password(length);
  copy_to_clipboard_any(pass);
  printf(GREEN "Generated password: " RESET "%s\n", pass);

  free(pass);
  return 0;
}
