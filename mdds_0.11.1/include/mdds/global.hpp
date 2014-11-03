/*************************************************************************
 *
 * Copyright (c) 2008-2014 Kohei Yoshida
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 ************************************************************************/

#ifndef MDDS_GLOBAL_HPP
#define MDDS_GLOBAL_HPP

#include <exception>
#include <string>

#define MDDS_ASCII(literal) literal, sizeof(literal)-1

namespace mdds {

class general_error : public ::std::exception
{
public:
    general_error(const ::std::string& msg) : m_msg(msg) {}
    virtual ~general_error() throw() {}

    virtual const char* what() const throw()
    {
        return m_msg.c_str();
    }
private:
    ::std::string m_msg;
};

class invalid_arg_error : public general_error
{
public:
    invalid_arg_error(const ::std::string& msg) : general_error(msg) {}
};

}

#endif
