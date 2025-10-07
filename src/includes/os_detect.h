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

