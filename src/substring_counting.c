#include <stdio.h>
#include <string.h>

int count_substrings(const char* str, const char* sub) {
    int count = 0;
    int str_len = strlen(str);
    int sub_len = strlen(sub);
    if (sub_len == 0 || sub_len > str_len) {
        return 0;
    }
    // Перебираем возможные позиции начала подстроки в строке
    for (int i = 0; i <= str_len - sub_len; i++) {
        if (strncmp(&str[i], sub, sub_len) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    char S[1001], S1[1001];
    printf("Enter string S: ");
    fgets(S, sizeof(S), stdin);
    S[strcspn(S, "\n")] = 0; 
    printf("Enter substring S1: ");
    fgets(S1, sizeof(S1), stdin);
    S1[strcspn(S1, "\n")] = 0;
    // Подсчёт вхождений
    int result = count_substrings(S, S1);
    printf("The number of occurrences of S1 in S as a substring: %d\n", result);

    return 0;
}