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

#ifndef HPP_CONSTRAINED_CORBA_SERVER_HH
# define HPP_CONSTRAINED_CORBA_SERVER_HH

# include <hpp/corba/template/server.hh>
# include "hpp/constrained/planner/fwd.hh"

namespace hpp {
  namespace constrained {
    namespace impl {
      class Constrained;
    } // namespace impl

    class Server
    {
    public:
      Server (int argc, char *argv[], bool multiThread = false,
	      const std::string& poaName = "child");
      ~Server ();
      /// Set planner that will be controlled by server
      void setPlanner (GraspingPlanner* planner);

      /// Start corba server

      /// Call hpp::corba::Server <impl::Problem>::startCorbaServer
      void startCorbaServer(const std::string& contextId,
			    const std::string& contextKind,
			    const std::string& objectId,
			    const std::string& objectKind);
    private:
      corba::Server <impl::Constrained>* impl_;
    };
  } // namespace constrained
} // namespace hpp
  
#endif // HPP_CONSTRAINED_CORBA_SERVER_HH
