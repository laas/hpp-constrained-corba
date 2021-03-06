// Copyright (C) 2011,2012 CNRS-LAAS
// Author: Florent Lamiraux.
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

#ifndef HPP_CONSTRAINED_CORBA_CONSTRAINED_HH
# define HPP_CONSTRAINED_CORBA_CONSTRAINED_HH

# include <omniORB4/CORBA.h>
# include <hpp/constrained/planner/fwd.hh>

# include "constrained.hh"

namespace hpp {
  namespace constrained {
    namespace impl {
      class Constrained : public virtual POA_hpp::Constrained
      {
      public:
	Constrained ();
	void setPlanner (GraspingPlanner* planner);
	virtual CORBA::Short
	setTarget (CORBA::Double x, CORBA::Double y, CORBA::Double z);
	virtual CORBA::Short
	setHand (CORBA::Boolean rightHand);
	virtual CORBA::Short
	generateGoalConfigurations (CORBA::UShort rank, CORBA::UShort nbConfig);
      private:
	GraspingPlanner* planner_;
      }; // class Constrained
    } // namespace impl
  } // namespace constrained
} // namespace hpp

#endif //HPP_CONSTRAINED_CORBA_CONSTRAINED_HH
