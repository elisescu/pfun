#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input_file, *output_file;
int M, N, c, C;
int *west_size, *south_side, **max_city, **min_city;

void print_usage(char *prog) {
    printf("\n %s input_file output_file\n\n", prog);
}

void close_files() {
    fclose(input_file);
    fclose(output_file);
}

void print_matx(int **mat, int M, int N) {
    for (int i = 0; i < M; i++) {
        printf("\n");
        for (int j = 0; j < N; j++) {
            int **row = mat + i;
            int *v = (int *) *row;
            printf(" %05d", *v);
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2 || (input_file = fopen(argv[1], "rt")) == (FILE *) NULL
            || (output_file = fopen(argv[2], "wt")) == (FILE *) NULL) { 
        print_usage(argv[0]);
        return 1;
    }

    fscanf(input_file, "%d %d %d %d", &M, &N, &c, &C);
    printf("INPUT: M=%d N=%d c=%d C=%d\n", M, N, c, C);

    west_size = (int *) malloc(M*sizeof(int));
    south_side = (int *) malloc(N*sizeof(int));

    min_city = (int **) malloc (M * sizeof(int *));
    max_city = (int **) malloc (M * sizeof(int *));

    for (int i = 0; i < M; i++) {
        min_city[i] = (int *) malloc(N * sizeof(int));
        memset(min_city[i], 0, N * sizeof(int));
        max_city[i] = (int *) malloc(N * sizeof(int));
        memset(max_city[i], 0, N * sizeof(int));
    }

    for (int i = 0; i < M; i++) {
        fscanf(input_file, "\n%d", &west_size[i]);
    }

    for (int i = 0; i < N; i++) {
        fscanf(input_file, "\n%d", &south_side[i]);
    }

    // get the min number of people
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("\n -- ");
        }
    }

    print_matx(min_city, M, N);

    return 0;
}
