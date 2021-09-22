#include "result.h"

struct Results *solution(const int N, const int A[], const int M) {
    struct Results *result = NULL;
    result = results_create_struct(&N);
    if (result == NULL) return NULL;

    int max_value = 0;

    for (int i = 0; i < M; ++i) {
        if (1 <= A[i] && A[i] <= N) {
            (*(result->C + A[i] - 1))++;
            if (*(result->C + A[i] - 1) > max_value) {
                max_value = *(result->C + A[i] - 1);
            }
        }
        if (A[i] == N + 1) {
            for (int j = 0; j < result->L; ++j) {
                (*(result->C + j)) = max_value;
            }
        }
        results_display(result);
    }
    results_destroy_struct(result);
    return result;
}

struct Results *results_create_struct(const int *N) {
    struct Results *ptr_results = NULL;
    ptr_results = (struct Results *) malloc(sizeof(struct Results));
    if (ptr_results == NULL) return NULL;
    ptr_results->C = (int *) calloc(*N, sizeof(int));
    if (ptr_results->C == NULL) {
        free(ptr_results);
        return NULL;
    }
    ptr_results->L = *N;
    return ptr_results;
}

void results_destroy_struct(struct Results *result) {
    if (result == NULL) return;
    free(result->C);
    free(result);
}

void results_display(struct Results *result) {
    if (result == NULL) {
        printf("Error display");
    }
    for (int i = 0; i < result->L; ++i) {
        printf("%d ", *(result->C + i));
    }
    printf("\n");
}