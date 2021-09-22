#ifndef MAXCOUNTERS_CODILITY_RESULT_H
#define MAXCOUNTERS_CODILITY_RESULT_H

#include <stdlib.h>
#include <stdio.h>

struct Results {
    int *C;
    int L; // Length of the array
};

struct Results *results_create_struct(const int *N);

struct Results *solution(const int N, const int A[], const int M);

void results_destroy_struct(struct Results *result);

void results_display(struct Results *result);

#endif //MAXCOUNTERS_CODILITY_RESULT_H
