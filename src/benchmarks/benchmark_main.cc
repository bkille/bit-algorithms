// =============================== TEST ROOT ================================ //
// Project:         The Experimental Bit Algorithms Library
// Name:            test_root.cc
// Description:     Brings in all of the test headers into an object to be linked
//                  with the test main 
// Creator:         Vincent Reverdy
// Contributor(s):  Bryce Kille [2019]
// License:         BSD 3-Clause License
// ========================================================================== //



// ============================== PREAMBLE ================================== //
// C++ standard library
#include <tuple>
#include <vector>
#include <list>
#include <forward_list>
// Project sources
#include "bit.hpp"
#include "utils/test_utils.hpp"
#include "count_bench.hpp"
#include "rotate_bench.hpp"
#include "reverse_bench.hpp"
#include "search_bench.hpp"
// Third party libraries
#include <benchmark/benchmark.h>
#include <iostream>
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#include <string>
#include <typeinfo>
// ========================================================================== //

std::string demangle(const char* name) {
    int status = -4; // some arbitrary value to eliminate the compiler warning
    // enable c++11 by passing the flag -std=c++11 to g++
    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };
    return (status==0) ? res.get() : name ;
}


template<class F> 
constexpr void register_types(F test_lambda_f, std::string func_name, unsigned int size) {
    return;
}

template <class F, class C, class... Args> 
void register_types(F test_lambda_f, std::string func_name, unsigned int size) {
    using word_type = typename C::value_type;
    std::string container_name = demangle(typeid(C).name());
    std::string test_name = func_name; // + " " + container_name;
    benchmark::RegisterBenchmark(
            test_name.c_str(), 
            test_lambda_f, 
            std::make_tuple(C(), word_type(), size));
    register_types<F, Args...>(test_lambda_f, func_name, size);
}

template <class F> 
void register_word_containers(F test_lambda_f, std::string func_name, unsigned int size) {
    return;
}

template <class F, template<typename...> class C, template<typename...> class... Args> 
void register_word_containers(F test_lambda_f, std::string func_name, unsigned int size) {
    register_types<F, C<unsigned int>>(test_lambda_f, func_name, size);
    register_word_containers<F, Args...>(test_lambda_f, func_name, size);
}

template <class F> 
void register_bool_containers(F test_lambda_f, std::string func_name, unsigned int size) {
    return;
}

template <class F, template<typename...> class C, template<typename...> class... Args> 
void register_bool_containers(F test_lambda_f, std::string func_name, unsigned int size) {
    //std::string container_name = demangle(typeid(C).name());
    register_types<F, C<bool>>(test_lambda_f, func_name, size);
    register_bool_containers<F, Args...>(test_lambda_f, func_name, size);
}

//BENCHMARK_MAIN();
int main(int argc, char** argv) {
    unsigned int size_small = 1 << 4;
    unsigned int size_medium = 1 << 8;
    unsigned int size_large = 1 << 16;
    unsigned int size_huge = 1 << 30;
    // Reverse benchmarks
    register_word_containers<decltype(BM_BitReverse_UU), std::vector>(
            BM_BitReverse_UU, 
            "bit::reverse (small) (UU)",
            size_small);
    register_bool_containers<decltype(BM_BoolReverse), std::vector>(
            BM_BoolReverse, 
            "std::reverse (small)",
            size_small);
    register_word_containers<decltype(BM_BitReverse), std::vector>(
            BM_BitReverse, 
            "bit::reverse (large) (AA)",
            size_large);
    register_bool_containers<decltype(BM_BoolReverse), std::vector>(
            BM_BoolReverse, 
            "std::reverse (large)",
            size_large);

    // Rotate benchmarks 
    register_word_containers<decltype(BM_BitRotate), std::vector>(
            BM_BitRotate, 
            "bit::rotate (small) (ARA)",
            size_small);
    register_bool_containers<decltype(BM_BoolRotate), std::vector>(
            BM_BoolRotate, 
            "std::rotate (small)",
            size_small);
    register_word_containers<decltype(BM_BitRotate), std::vector>(
            BM_BitRotate, 
            "bit::rotate (large) (ARA)",
            size_large);
    register_bool_containers<decltype(BM_BoolRotate), std::vector>(
            BM_BoolRotate, 
            "std::rotate (large)",
            size_large);

    // Count benchmarks 
    register_word_containers<decltype(BM_BitCount), std::vector>(
            BM_BitCount, 
            "bit::count (small) (AA)",
            size_small);
    register_bool_containers<decltype(BM_BoolCount), std::vector>(
            BM_BoolCount, 
            "std::count (small)",
            size_small);
    register_word_containers<decltype(BM_BitCount), std::vector>(
            BM_BitCount, 
            "bit::count (large) (AA)",
            size_large);
    register_bool_containers<decltype(BM_BoolCount), std::vector>(
            BM_BoolCount, 
            "std::count (large)",
            size_large);

    // Search benchmarks
    //register_word_containers<decltype(BM_BitSearch), std::vector>(
            //BM_BitSearch, 
            //"Search_Bit_Large",
            //size);
    //register_bool_containers<decltype(BM_BoolSearch), std::vector>(
            //BM_BoolSearch, 
            //"Search_Bool_Large",
            //size);
    //register_word_containers<decltype(BM_BitSearch_WorstCase), std::vector>(
            //BM_BitSearch_WorstCase, 
            //"Search_Bit_Large_WorstCase",
            //size);
    //register_bool_containers<decltype(BM_BoolSearch_WorstCase), std::vector>(
            //BM_BoolSearch_WorstCase, 
            //"Search_Bool_Large_WorstCase",
            //size);
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}
