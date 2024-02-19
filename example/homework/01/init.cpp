#include <Kokkos_Core.hpp>
#include <cstdio>

// Problem: Link and run program with Kokkos where you initialize a View and print out its name with the $.label()$ method.

int main(int argc, char* argv[]) {
  Kokkos::initialize(argc, argv);
  {
  // Make View
  
  // print name
  }
  Kokkos::finalize();
}
