// Filename: parameterRemapBasicStringPtrToString.cxx
// Created by:  drose (11Aug09)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#include "parameterRemapBasicStringPtrToString.h"

////////////////////////////////////////////////////////////////////
//     Function: ParameterRemapBasicStringPtrToString::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
ParameterRemapBasicStringPtrToString::
ParameterRemapBasicStringPtrToString(CPPType *orig_type) :
  ParameterRemapToString(orig_type)
{
}

////////////////////////////////////////////////////////////////////
//     Function: ParameterRemapBasicStringPtrToString::pass_parameter
//       Access: Public, Virtual
//  Description: Outputs an expression that converts the indicated
//               variable from the original type to the new type, for
//               passing into the actual C++ function.
////////////////////////////////////////////////////////////////////
void ParameterRemapBasicStringPtrToString::
pass_parameter(ostream &out, const string &variable_name) {
  out << "&" << variable_name;
}

////////////////////////////////////////////////////////////////////
//     Function: ParameterRemapBasicStringPtrToString::get_return_expr
//       Access: Public, Virtual
//  Description: Returns an expression that evalutes to the
//               appropriate value type for returning from the
//               function, given an expression of the original type.
////////////////////////////////////////////////////////////////////
string ParameterRemapBasicStringPtrToString::
get_return_expr(const string &expression) {
  return "(" + expression + ")->c_str()";
}

////////////////////////////////////////////////////////////////////
//     Function: ParameterRemapBasicWStringPtrToWString::Constructor
//       Access: Public
//  Description:
////////////////////////////////////////////////////////////////////
ParameterRemapBasicWStringPtrToWString::
ParameterRemapBasicWStringPtrToWString(CPPType *orig_type) :
  ParameterRemapToWString(orig_type)
{
}

////////////////////////////////////////////////////////////////////
//     Function: ParameterRemapBasicWStringPtrToWString::pass_parameter
//       Access: Public, Virtual
//  Description: Outputs an expression that converts the indicated
//               variable from the original type to the new type, for
//               passing into the actual C++ function.
////////////////////////////////////////////////////////////////////
void ParameterRemapBasicWStringPtrToWString::
pass_parameter(ostream &out, const string &variable_name) {
  out << "&" << variable_name;
}

////////////////////////////////////////////////////////////////////
//     Function: ParameterRemapBasicWStringPtrToWString::get_return_expr
//       Access: Public, Virtual
//  Description: Returns an expression that evalutes to the
//               appropriate value type for returning from the
//               function, given an expression of the original type.
////////////////////////////////////////////////////////////////////
string ParameterRemapBasicWStringPtrToWString::
get_return_expr(const string &expression) {
  return "(" + expression + ")->c_str()";
}
