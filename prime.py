import timeit

def sieve():
    primes = [True] * 2500
    primes[0] = False
    primes[1] = False
    for i in range(2, 51): # 51 is sqrt(2500) + 1
        if primes[i]:
            for j in range(i*i, 2500, i):
                primes[j] = False
    return [i for i in range(2,2500) if primes[i]]

def disasterCode():
    primes = sieve()
    print(len(primes))

    factorizations = [[] for _ in range(2500)]
    for i in range(2,2500):
        for prime in primes:
            if i % prime == 0:
                val = i // prime
                # the prime factors of i's factor (excluding j)
                factor_factors = factorizations[val]
                # if the factors already has j, don't re-add it
                if val % prime == 0:
                    factorizations[i] = factor_factors
                else:
                    factorizations[i] = factor_factors + [prime]
                break
    return factorizations



# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0,5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")

    times = []
    for i in range(0,5):
        times.append(timeit.timeit("sieve()", setup="from __main__ import sieve", number=1))
    
    res2 = sum(times)/5
    print(f"Average execution time for sieve after 5 runs: {res2:.6f} seconds")
    print(f"ratio: {res/res2:.6f}")
