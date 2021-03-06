// Filename: odeGeom_ext.I
// Created by:  rdb (11Dec13)
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

#include "odeSpace_ext.h"
#include "lpoint3.h"

////////////////////////////////////////////////////////////////////
//     Function: OdeGeom::get_AA_bounds
//       Access: Published
//  Description: A more Pythonic way of calling getAABB()
////////////////////////////////////////////////////////////////////
INLINE PyObject *Extension<OdeGeom>::
get_AA_bounds() const {
  LPoint3f *min_point = new LPoint3f;
  LPoint3f *max_point = new LPoint3f;
  _this->get_AABB(*min_point, *max_point);

  PyObject *min_inst = DTool_CreatePyInstance(min_point, true);
  PyObject *max_inst = DTool_CreatePyInstance(max_point, true);
  return Py_BuildValue("NN", min_inst, max_inst);
}

////////////////////////////////////////////////////////////////////
//     Function: OdeGeom::get_converted_space
//       Access: Published
//  Description: Equivalent to get_space().convert()
////////////////////////////////////////////////////////////////////
INLINE PyObject *Extension<OdeGeom>::
get_converted_space() const {
  OdeSpace s = _this->get_space();
  return invoke_extension(&s).convert();
}
