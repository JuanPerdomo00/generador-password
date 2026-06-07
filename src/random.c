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

#include "includes/random.h"
#include "includes/os_detect.h"
#include <stdio.h>
#include <stdint.h>

#ifdef OS_LINUX
#include <sys/random.h>
#endif

#ifdef OS_MAC
#include <CommonCrypto/CommonCrypto.h>
#endif

#ifdef OS_WINDOWS
#include <wincrypt.h>
#endif

int secure_random_bytes(unsigned char *buffer, size_t size) {
    if (!buffer || size == 0)
        return -1;

#ifdef OS_LINUX
    ssize_t ret = getrandom(buffer, size, 0);
    if (ret < 0 || (size_t)ret != size)
        return -1;
    return 0;

#elif defined(OS_MAC)
    int ret = SecRandomCopyBytes(kSecRandomDefault, size, buffer);
    return ret;

#elif defined(OS_WINDOWS)
    HCRYPTPROV hProv = 0;
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0)) {
        return -1;
    }
    if (!CryptGenRandom(hProv, (DWORD)size, buffer)) {
        CryptReleaseContext(hProv, 0);
        return -1;
    }
    CryptReleaseContext(hProv, 0);
    return 0;

#else
    (void)buffer;
    (void)size;
    fprintf(stderr, "Secure random not supported on this platform\n");
    return -1;
#endif
}

unsigned int secure_random_int(unsigned int max) {
    if (max == 0)
        return 0;

    unsigned char byte;
    unsigned int random_val;

   
    unsigned int range = UINT32_MAX - (UINT32_MAX % max);
    
    do {
        if (secure_random_bytes(&byte, sizeof(byte)) != 0)
            return 0;
        random_val = byte;
    } while (random_val >= range);

    return random_val % max;
}
