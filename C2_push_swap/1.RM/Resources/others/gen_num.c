#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_random_numbers(int amount, int max_length) {
    srand(time(NULL));

    char arg_string[10000] = "ARG=\""; // Large enough buffer
    char num_str[20]; // Buffer to hold each number as a string

	amount = ((amount - 1) % 10) ? amount - 1 : amount;
    int max_value = 1;

    for (int i = 0; i < max_length; i++) {
        max_value *= 10;
    }
    max_value--;

    for (int i = 0; i < amount; i++) {
        int random_positive = rand() % (max_value + 1);
        int random_sign = rand() % 2;

        if (random_sign == 1) {
            sprintf(num_str, "%d", -random_positive);
        } else {
            sprintf(num_str, "%d", random_positive);
        }

        strcat(arg_string, num_str);
        strcat(arg_string, " "); // Add space separator
    }

    strcat(arg_string, "\""); // Add closing quote
    printf("%s\n", arg_string);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage:<amount> <max_length>\n");
        return 1;
    }

    int amount = atoi(argv[1]);
    int max_length = atoi(argv[2]);

    generate_random_numbers(amount, max_length);

    return 0;
}