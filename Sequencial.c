#include <stdio.h>
#include <omp.h>

long fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 40;

    double inicio = omp_get_wtime();

    long resultado = fibonacci(n);

    double fim = omp_get_wtime();

    printf("Fibonacci(%d) = %ld\n", n, resultado);
    printf("Tempo: %f segundos\n", fim - inicio);

    return 0;
}