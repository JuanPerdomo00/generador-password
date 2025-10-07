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


#include "includes/colors.h"
#include "includes/genpass.h"
#include "includes/strings.h"
#include "includes/copyclip.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "1.0.0"

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
        printf("Example:\n");
        printf("  %s 12\n\n", argv[0]);
        printf("This will generate a random password with 12 characters.\n");
        return 0;
    }

    int length = atoi(argv[1]);

    if (length < 8) {
        fprintf(stderr, RED "Error:" RESET " length must be at least 8.\n");
        return 1;
    }

    init_strings();
    char *pass = generate_password(length);
		copy_to_clipboard_any(pass);
    printf(GREEN "Generated password: " RESET "%s\n", pass);
		
    return 0;
}

