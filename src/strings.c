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
