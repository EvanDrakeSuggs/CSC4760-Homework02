
KOKKOS_INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
KOKKOS_INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

# This is a tutorial, not a test, so we don't ask CTest to run it.
KOKKOS_ADD_EXECUTABLE(
  tutorial_04_copyerror_kokkos
  SOURCES 04-copyerror-kokkos.cpp
)

