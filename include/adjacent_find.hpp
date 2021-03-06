// ============================= ADJACENT FIND ============================= //
// Project: The Experimental Bit Algorithms Library
// Name: adjacent_find.hpp
// Description: bit_iterator overloads for std::adjacent_find
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _ADJACENT_FIND_HPP_INCLUDED
#define _ADJACENT_FIND_HPP_INCLUDED
// ========================================================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: to do
template <class ForwardIt>
constexpr bit_iterator<ForwardIt> adjacent_find(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last) {
    (last);
    return first;    
}

// Status: to do
template <class ExecutionPolicy, class ForwardIt>
bit_iterator<ForwardIt> adjacent_find(ExecutionPolicy&& policy,
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last) {
    (policy, last);
    return first;
}

// Status: on hold
template <class ForwardIt, class BinaryPredicate>
constexpr bit_iterator<ForwardIt> adjacent_find(bit_iterator<ForwardIt> first,
    bit_iterator<ForwardIt> last, BinaryPredicate p) {
    (last, p); 
    return first;
}

// Status: on hold
template <class ExecutionPolicy, class ForwardIt, class BinaryPredicate>
bit_iterator<ForwardIt> adjacent_find(ExecutionPolicy&&, 
    bit_iterator<ForwardIt> first, bit_iterator<ForwardIt> last,
    BinaryPredicate p) {
    (last, p); 
    return first;
}

// ========================================================================== //
} // namespace bit

#endif // _ADJACENT_FIND_HPP_INCLUDED
// ========================================================================== //
