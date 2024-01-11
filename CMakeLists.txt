cmake_minimum_required(VERSION 3.21)
project(PrimeFactorizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -march=native -flto ") #time to fly

# Add Pybind11
include(FetchContent)
set(PYBIND11_VERSION 2.11.1)
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v${PYBIND11_VERSION}
)
FetchContent_MakeAvailable(pybind11)

pybind11_add_module(PrimeFactorizer MODULE prime.cpp main.cpp)
