#include <pybind11/pybind11.h>
#include "prime.h"
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(PrimeFactorizer, m) {
    m.def("not_disaster", &PrimeFactorizer::not_disaster);
}
