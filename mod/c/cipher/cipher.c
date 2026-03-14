#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"

void print_progress(size_t current, size_t total, int width) {
    if (total == 0) return;

    int percentage = (current * 100) / total;
    int filled_width = (percentage * width) / 100;

    printf("\r[");
    for (int i = 0; i < width; i++) {
        if (i < filled_width) printf("#");
        else printf("-");
    }
    printf("] %d%%", percentage);
    fflush(stdout);
}

size_t get_file_size(FILE *f) {
    if (f == NULL) return -1;

    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    return size;
}

void process_file(const char *in_pth, const char *out_pth, const char *key)
{
    FILE *f_in = fopen(in_pth, "rb");
    FILE *f_out = fopen(out_pth, "wb");

    if (!f_in || !f_out) {
        perror(RED "Error opening file" RESET);
        return;
    }

    unsigned char buffer[4096];
    size_t bytes_read;
    size_t total = get_file_size(f_in);
    size_t total_processed = 0;
    size_t key_len = strlen(key);
    size_t key_pos = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), f_in)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[key_pos];
            key_pos = (key_pos + 1) % key_len;
        }
        fwrite(buffer, 1, bytes_read, f_out);
        total_processed += bytes_read;

        print_progress(total_processed, total, 30);
    }

    fclose(f_in);
    fclose(f_out);
}

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, RED "Usage: %s <input file> <output file> <key>\n" RESET, argv[0]);
        return 1;
    }

    const char *input = argv[1];
    const char *output = argv[2];
    const char *key = argv[3];

    if (strlen(key) == 0) {
        fprintf(stderr, RED "Error: Key cannot be empty!\n" RESET);
        return 1;
    }

    printf(HIDE_CURSOR "File encryption: %s -> %s\n", input, output);
    process_file(input, output, key);
    printf(GRN "\nSuccessfully!\n" RESET SHOW_CURSOR);
}