#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
    	int n = 8;
	int result = 0;
    	Kokkos::View<int*> check("check", n);
	// fill array
	for(int i = 0; i<check.extent(0); i++){
	  check(i) = i*i;
	}
    	Kokkos::parallel_reduce("parallel sum", check.extent(0), KOKKOS_LAMBDA(const int& i, int& lsum){
                    	lsum+=check(i);
            }, result);
	Kokkos::fence();
    	std::cout << "Result: " << result << std::endl;
    	}
    	Kokkos::finalize();
    	return 0;
}
