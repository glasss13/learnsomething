import timeit
import cppimport.import_hook
import PrimeFactorizer

def disasterCode():
    factorizations = PrimeFactorizer.not_disaster()
    return factorizations



# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,10):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/10

    print(f"Average execution time after 10 runs: {res:.6f} seconds")
