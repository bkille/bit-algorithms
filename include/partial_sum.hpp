// ============================== PARTIAL SUM ============================== //
// Project: The Experimental Bit Algorithms Library
// Name: partial_sum.hpp
// Description: bit_iterator overloads for std::partial_sum
// Creator: Vincent Reverdy
// Contributor(s): 
// License: BSD 3-Clause License
// ========================================================================== //
#ifndef _PARTIAL_SUM_HPP_INCLUDED
#define _PARTIAL_SUM_HPP_INCLUDED
// ========================================================================== //

// ============================== PREAMBLE ================================== //
// C++ standard library
// Project sources
// Third-party libraries
// Miscellaneous

namespace bit {
// ========================================================================== //



// Status: will not implement?
template <class InputIt, class OutputIt>
bit_iterator<OutputIt> partial_sum(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first) {
    (first, last);
    return d_first;
}

// Status: on hold
template <class InputIt, class OutputIt, class BinaryOperation>
bit_iterator<OutputIt> partial_sum(bit_iterator<InputIt> first,
    bit_iterator<InputIt> last, bit_iterator<OutputIt> d_first,
    BinaryOperation op) {
    (first, last, op); 
    return d_first;
}

// ========================================================================== //
} // namespace bit

#endif // _PARTIAL_SUM_HPP_INCLUDED
// ========================================================================== //
