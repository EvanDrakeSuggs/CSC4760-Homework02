#include <Kokkos_Core.hpp>

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
		// do something in scope
    	}
    	Kokkos::finalize();
    	return 0;
}
