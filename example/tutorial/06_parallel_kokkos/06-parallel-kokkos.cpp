#include <Kokkos_Core.hpp>
#include <iostream>

struct Foo{
  KOKKOS_INLINE_FUNCTION void operator() (const double& i, double& lsum) const{
    lsum+=i;
  }
};

int main(int argc, char** argv) {
    	Kokkos::initialize( argc, argv );
    	{
	  int n = 16;
	  Kokkos::View<int*> check("check", n);
	  Kokkos::parallel_for("iterator", n, KOKKOS_LAMBDA(const int& i){
	      check(i) = i*i;
	    });
	  Foo functor;
	  double result = 0;
	  Kokkos::parallel_reduce (n, functor, result);
	  std::cout << "Result: " << result << std::endl;
	  
    	}
    	Kokkos::finalize();
    	return 0;
}
