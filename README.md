# cpp-fast_float-proxy

Experimental third party proxy of fastfloat/fast_float.

## Usage

Generate the build files:

```console
❯ cmake -S . -B build
# ...
```

Build (in parallel):

```console
❯ cmake --build build --parallel 4
[ 50%] Building CXX object examples/CMakeFiles/basic.dir/basic.cpp.o
[ 50%] Building CXX object CMakeFiles/fast_float_test.dir/main.cpp.o
[ 75%] Linking CXX executable basic
[ 75%] Built target basic
[100%] Linking CXX executable fast_float_test
[100%] Built target fast_float_test
```

Execute tests:

```console
❯ build/fast_float_test
[doctest] doctest version is "2.4.4"
[doctest] run with "--help" for options
===============================================================================
[doctest] test cases: 1 | 1 passed | 0 failed | 0 skipped
[doctest] assertions: 6 | 6 passed | 0 failed |
[doctest] Status: SUCCESS!
```

Execute basic example:

```console
❯ build/examples/basic
parsed the number 3.1416
parsed lat 42.1234 and lon 179.123
residuals 0 and -8e-08
```

## Status

Experimental.

**Note**: The default branch is `default`.
