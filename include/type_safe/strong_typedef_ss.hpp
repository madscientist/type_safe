// Copyright (C) 2016-2020 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#ifndef TYPE_SAFE_STRONG_TYPEDEF_SS_HPP_INCLUDED
#define TYPE_SAFE_STRONG_TYPEDEF_SS_HPP_INCLUDED

#if defined(TYPE_SAFE_IMPORT_STD_MODULE)
import std;
#else
#include <iosfwd>
#endif

#include <type_safe/strong_typedef.hpp>

#ifdef _MSC_VER
#    define TYPE_SAFE_MSC_EMPTY_BASES __declspec(empty_bases)
#else
#    define TYPE_SAFE_MSC_EMPTY_BASES
#endif

namespace type_safe
{
/// Streams operations for [ts::strong_typedef]().
///
/// They all generate operators forwarding to the underlying type.
/// Inherit from them in the typedef definition.
namespace strong_typedef_op
{
    template <class StrongTypedef>
    struct TYPE_SAFE_MSC_EMPTY_BASES input_operator
    {
        /// \exclude
        template <typename Char, class CharTraits>
        friend std::basic_istream<Char, CharTraits>& operator>>(
            std::basic_istream<Char, CharTraits>& in, StrongTypedef& val)
        {
            using type = underlying_type<StrongTypedef>;
            return in >> static_cast<type&>(val);
        }
    };

    template <class StrongTypedef>
    struct TYPE_SAFE_MSC_EMPTY_BASES output_operator
    {
        /// \exclude
        template <typename Char, class CharTraits>
        friend std::basic_ostream<Char, CharTraits>& operator<<(
            std::basic_ostream<Char, CharTraits>& out, const StrongTypedef& val)
        {
            using type = underlying_type<StrongTypedef>;
            return out << static_cast<const type&>(val);
        }
    };
} // namespace strong_typedef_op
} // namespace type_safe

#undef TYPE_SAFE_MSC_EMPTY_BASES

#endif // TYPE_SAFE_STRONG_TYPEDEF_SS_HPP_INCLUDED
