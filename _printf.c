#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int chars_printed = 0;
    char c;
    
    while ((c = *format++) != '\0') {
        if (c != '%') {
            putchar(c);
            chars_printed++;
        } else {
            c = *format++;
            if (c == '%') {
                putchar('%');
                chars_printed++;
            } else if (c == 'c') {
                char ch = va_arg(args, int);
                putchar(ch);
                chars_printed++;
            } else if (c == 's') {
                const char *str = va_arg(args, const char *);
                while (*str) {
                    putchar(*str);
                    str++;
                    chars_printed++;
                }
            }
            // Add more conversion specifiers here if needed
        }
    }
    
    va_end(args);
    return chars_printed;
}

int main() {
    int num_chars = _printf("Hello, %s! Today is %c\n", "John", 'S');
    printf("\nNumber of characters printed: %d\n", num_chars);
    return 0;
}

