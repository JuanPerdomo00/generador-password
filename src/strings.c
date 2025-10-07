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

#include "includes/strings.h"
#include <stddef.h>

const char *LETTERS_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *LETTERS_LOWER = "abcdefghijklmnopqrstuvwxyz";
const char *NUMBERS = "0123456789";
const char *SYMBOLS = "!@#$%^&*()_+-=[]{}|;:',.<>/?";
const char *MIXED =
    "aZ1!bY2@cX3#dW4$eV5%fU6^gT7&hS8*iR9(jQ0)kP_lO+mN-nM=oL[pK]qJ{rI}sH|tG;"
    "uF:'vE,wD<xC>yB?zA.";

const char *ARR_STRINGS[6];

void init_strings(void) {
  ARR_STRINGS[0] = LETTERS_LOWER;
  ARR_STRINGS[1] = LETTERS_UPPER;
  ARR_STRINGS[2] = NUMBERS;
  ARR_STRINGS[3] = SYMBOLS;
  ARR_STRINGS[4] = MIXED;
  ARR_STRINGS[5] = NULL;
}
