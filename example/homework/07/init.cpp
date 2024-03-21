#include <Kokkos_Core.hpp>
#include <mpi.h>
#include <cstdio>

int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);
  Kokkos::initialize(argc, argv);
  {
  // Make View and init values
 
  // Send View values with MPI functions

  // Output
  printf("\nhello world\n");
  }
  Kokkos::finalize();
  MPI_Finalize();
}
