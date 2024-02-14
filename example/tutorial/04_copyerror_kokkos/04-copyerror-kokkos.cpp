#include <Kokkos_Core.hpp>
#include <iostream>
// TODO Fix size conflict! 
int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  int n = 8;
	  int m = 4;
	  Kokkos::View<int[5][10]> A("A");
	  // fill View
	  for(int i = 0; i<A.extent(0); i++)
	    {
	      for(int j = 0; j<A.extent(1); j++)
		{
		  // To avoid relying on magic vars like n and m
		  // use the provided extent methods
		  A(i, j) = i*j;
		}
	    }
	  Kokkos::View<int**> B("B", n, m);
	  Kokkos::deep_copy(B, A);
	  B(2, 2) = 4; // A(2, 2) != 4
	  std::cout << "A(2, 2) is " << A(2, 2) << std::endl;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
