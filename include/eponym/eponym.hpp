#ifndef INCL_EPONYM_EPONYM_HPP
#define INCL_EPONYM_EPONYM_HPP

///////////////////////////////////////////////////////////////////////////////////
// 
// The MIT License (MIT)
//
// Copyright (c) 2015 Michael B. Price
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////////

#include <utility>

/**
    The second parameter becomes an alias of the first within the current scope
*/
#define EPONYM_ALIAS(fullyQualifiedFunctionName, newName)                \
template <typename ... Args>                                             \
auto newName (Args&&... args)                                            \
  -> decltype(fullyQualifiedFunctionName(std::forward<Args>(args)...)) { \
    return fullyQualifiedFunctionName(std::forward<Args>(args)...);      \
}


/**
    Creates an alias for the member function named by the second parameter, for
    the object named by the first parameter, within the current scope
*/
#define EPONYM_USING(delegateObject, functionName)                       \
template <typename ... Args>                                             \
auto functionName (Args&&... args)                                       \
 -> decltype(delegateObject.functionName(std::forward<Args>(args)...)) { \
    return delegateObject.functionName(std::forward<Args>(args)...);     \
}


#endif // INCL_EPONYM_EPONYM_HPP

