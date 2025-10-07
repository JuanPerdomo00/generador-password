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

