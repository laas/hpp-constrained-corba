// Copyright (C) 2011,2012 CNRS-LAAS
// Author: Sebastien Dalibard.
//
// This file is part of the hpp-constrained-corba.
//
// hpp-constrained-corba is free software: you can redistribute
// it and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation, either
// version 3 of the License, or (at your option) any later version.
//
// hpp-constrained-corba is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with hpp-constrained-corba.  If not, see
// <http://www.gnu.org/licenses/>.

#include <cassert>
#include <hpp/constrained/planner/grasping-planner.hh>
#include "constrained.impl.hh"

namespace hpp {
  namespace constrained {
    namespace impl {
      Constrained::Constrained () : planner_ (0) {}
      void Constrained::setPlanner (GraspingPlanner* planner)
      {
	planner_ = planner;
      }
      CORBA::Short
      Constrained::setTarget (CORBA::Double x, CORBA::Double y,
			      CORBA::Double z)
      {
	assert (planner_);
	planner_->setTarget (vector3d (x, y, z));
	return 0;
      }
      CORBA::Short
      Constrained::setHand (CORBA::Boolean rightHand)
      {
	assert (planner_);
	planner_->setHand (rightHand);
	return 0;
      }
    } // namespace impl
  } // namespace constrained
} // namespace hpp
