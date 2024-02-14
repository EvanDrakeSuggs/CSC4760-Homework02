#include <Kokkos_Core.hpp>
#include <iostream>

template<typename View_t>
void foo(View_t& buf){
  std::cout << buf.label() << " View works!" << std::endl;
}

// why does this function cause an error?
void bar(Kokkos::View<double*>& buf){
  std::cout << buf.label() << " View works!" << std::endl;
}

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
	// Which one of these works correctly
	foo(check);
	//bar(check);
    	}
    	Kokkos::finalize();
    	return 0;
}
