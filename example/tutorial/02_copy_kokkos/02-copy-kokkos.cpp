#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  int n = 8;
	  Kokkos::View<int*> A("A", n);
	  // fill View
	  Kokkos::parallel_for("Loop1", n, KOKKOS_LAMBDA (const int i) {
	      // accessor method uses parentheses
	      A(i) = i*i;
	    });
	  // View that points to original
	  Kokkos::View<int*> B = A;
	  B(2) = 4; // A(2) == 4
	  std::cout << "A(4) is " << A(2) << std::endl;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
