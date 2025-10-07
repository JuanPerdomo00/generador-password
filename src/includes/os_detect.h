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

#ifndef OS_DETECT_H
#define OS_DETECT_H

#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS 1
#define OS_NAME "Windows"

#elif defined(__linux__)
#define OS_LINUX 1
#define OS_NAME "Linux"

#elif defined(__APPLE__) && defined(__MACH__)
#define OS_MAC 1
#define OS_NAME "macOS"

#elif defined(__unix__)
#define OS_UNIX 1
#define OS_NAME "Unix-like"

#else
#define OS_UNKNOWN 1
#define OS_NAME "Unknown"
#endif

#endif // OS_DETECT_H

