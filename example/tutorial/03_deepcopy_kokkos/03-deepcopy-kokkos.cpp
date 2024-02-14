#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  int n = 8;
	  int m = 4;
	  Kokkos::View<int**> A("A", n, m);
	  // fill View
	  Kokkos::parallel_for("Loop1", A.extent(0), KOKKOS_LAMBDA (const int i) {
		Kokkos::parallel_for("Loop2", A.extent(1), KOKKOS_LAMBDA (const int j) {
		  // To avoid relying on magic vars like n and m
		  // use the provided extent methods
		  A(i, j) = i*j;
		});
	    });
	  Kokkos::View<int**> B("B", n, m);
	  Kokkos::deep_copy(B, A);
	  B(2, 2) = 4; // A(2, 2) != 4
	  std::cout << "A(2, 2) is " << A(2, 2) << std::endl;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
