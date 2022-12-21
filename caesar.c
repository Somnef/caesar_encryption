#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str_is_number(char* str) {
    const int str_len = strlen(str);

    for (int i = 0; i < str_len; i++) {
        if (isdigit(str[i]) == 0)
            return 0;
    }

    return 1;
}

char* concat_strings(char** str_list, int str_list_len) {
    int msg_len = 0;
    for (int i = 0; i < str_list_len; i++) {
        msg_len += strlen(str_list[i]) + 1;
    }

    char* result;
    result = (char*) calloc(msg_len, sizeof(char));

    for (int i = 0; i < str_list_len; i++) {
        strcat(result, str_list[i]);

        if (i < str_list_len - 1) {
            strcat(result, " ");
        }
        else {
            strcat(result, "\0");
        }
    }

    return result;
}

char* caesar(char* operation, char* msg, int k) {
    if (strcmp(operation, "cipher") != 0 && strcmp(operation, "decipher") != 0) {
        printf("Cannot operate: operation \"%s\" unkown", operation);
        return "";
    }

    k %= 26;

    if(strcmp(operation, "decipher") == 0) {
        k = (26 - k) % 26;
    }

    const int msg_len = strlen(msg);

    char* code;
    code = (char*) calloc(msg_len, sizeof(char));

    for (int i = 0; i < msg_len; i++) {
        if (65 <= msg[i] && msg[i] <= 90) {
            code[i] = (msg[i] + k - 65) % 26 + 65;
        } 
        else if (97 <= msg[i] && msg[i] <= 122) {
            code[i] = (msg[i] + k - 97) % 26 + 97;
        }
        else {
            code[i] = msg[i];
        }
    }

    return code;
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("usage: %s <cipher|decipher> <key> <string_to_process>", argv[0]);
        return 0;
    }
    else if (strcmp(argv[1], "cipher") != 0 && strcmp(argv[1], "decipher") != 0 || !str_is_number(argv[2])) {
        printf("usage: %s <cipher|decipher> <key> <string_to_process>", argv[0]);
        return 0;
    }

    char *msg = concat_strings(&(argv[3]), argc-3);
    const int msg_len = strlen(msg); 

    char *code = caesar(argv[1], msg, atoi(argv[2]));

    printf("%s\n", code);

    return 0;
}