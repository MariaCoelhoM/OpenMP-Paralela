//compilar no google colab
//!apt-get update
//!apt-get install -y mpich
//!mpicc vetor_partes.c -o vetor_partes
//!mpirun --allow-run-as-root --oversubscribe -np 5 ./vetor_partes

codigo = r'''
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int vetor[4] = {1, 2, 3, 4};
    int recebido;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 5) {
        if (rank == 0) {
            printf("Execute com pelo menos 5 processos.\n");
        }
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        for (int i = 1; i <= 4; i++) {
            MPI_Send(&vetor[i - 1], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }

    if (rank >= 1 && rank <= 4) {
        MPI_Recv(&recebido, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    for (int i = 1; i <= 4; i++) {
        MPI_Barrier(MPI_COMM_WORLD);

        if (rank == i) {
            printf("Processo %d recebeu: %d\n", rank, recebido);
            fflush(stdout);
        }
    }

    MPI_Finalize();
    return 0;
}
'''

with open("vetor_partes.c", "w") as f:
    f.write(codigo)

print("Arquivo atualizado!")