#include <stdio.h>
#include <stdlib.h>

void print_usage(char *prog) {
    printf("\n %s input_file output_file\n\n", prog);
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;

    if (argc < 2 || (input_file = fopen(argv[1], "rt")) == (FILE *) NULL
            || (output_file = fopen(argv[2], "wt")) == (FILE *) NULL) { 
        print_usage(argv[0]);
        return 1;
    }


    e_close:
    fclose(input_file);
    fclose(output_file);
    
    return 0;
}
