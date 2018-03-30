#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


bool brute_force(char *text, int t_len, char *pattern, int p_len) {
    int i, j;
    for(i=0; i < t_len; i++) {
        for(j=0; j < p_len && i+j < t_len; j++) {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == p_len)
            return true;
    }
    return false;
}


int main() {
    char text[10000];
    char pattern[10000];
    int t_len, p_len;
    
    scanf("%s", text);
    scanf("%d", &t_len);

    scanf("%s", pattern);
    scanf("%d", &p_len);
    
    printf("Found %s\n", brute_force(text, t_len, pattern, p_len)?"Yes":"No");
    return 0;
}
