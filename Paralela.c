#include <stdio.h>
#include <omp.h>

long fibonacci_parallel(int n) {
    long x, y;

    if (n <= 1)
        return n;

    #pragma omp task shared(x)
    x = fibonacci_parallel(n - 1);

    #pragma omp task shared(y)
    y = fibonacci_parallel(n - 2);

    #pragma omp taskwait

    return x + y;
}

int main() {
    int n = 40;
    long resultado;

    double inicio = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        resultado = fibonacci_parallel(n);
    }

    double fim = omp_get_wtime();

    printf("Resultado: %ld\n", resultado);
    printf("Tempo: %f segundos\n", fim - inicio);

    return 0;
}