#include <stdbool.h>
#include <string.h>

bool is_pal_tail_helper(char *s, int start, int end) {
    if (start >= end) {
        return true; 
    }
    if (s[start] != s[end]) {
        return false;
    }
    return is_pal_tail_helper(s, start + 1, end - 1); 
}

bool is_pal_tail(char *s) {
    int len = strlen(s);
    return is_pal_tail_helper(s, 0, len - 1); 
}