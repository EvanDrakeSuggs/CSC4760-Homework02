#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char** argv) {
  Kokkos::initialize( argc, argv );
  {
    // set the typedef
    typedef Kokkos::View<double***> View_t;
    int n,m,l = 8;
    // subview
    View_t A("A", n, m, l);
    for(int i = 0; i<A.extent(0); i++){
      for(int j = 0; i<A.extent(1); i++){
	for(int k = 0; i<A.extent(2); i++){
	  A(i, j, k) = i*j*k;
	}
      }
    }
    auto B = Kokkos::subview(A, 
			     std::make_pair(2, 5), 6, Kokkos::ALL);
    // unmanaged View
    char buf[] = {1, 2, 3, 4, 5};
    Kokkos::View<char*> C(buf, n);
    // A.data() == buf;
    std::cout << B.label() << "'s extents: " << std::endl;
    std::cout << "1st dim: " << B.extent(0) << "\n2nd dim: " << B.extent(1) << "\n3rd dim: " << B.extent(3) << std::endl;
	  
  }
  Kokkos::finalize();
  return 0;
}
