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

#include <hpp/util/exception.hh>
#include "hpp/corbaserver/constrained/server.hh"
#include "constrained.impl.hh"

namespace hpp {
  namespace constrained {
    Server::Server (int argc, char *argv[], bool multiThread,
		    const std::string& poaName) : 
      impl_ (new corba::Server <impl::Constrained>
	     (argc, argv, multiThread, poaName)) {}
    Server::~Server () { delete impl_;}
    void Server::setPlanner (GraspingPlanner* planner)
    {
      impl_->implementation ().setPlanner (planner);
    }

    /// Start corba server
    void Server::startCorbaServer(const std::string& contextId,
				  const std::string& contextKind,
				  const std::string& objectId,
				  const std::string& objectKind)
    {
      if (impl_->startCorbaServer(contextId, contextKind, objectId, objectKind)
	  != 0) {
	HPP_THROW_EXCEPTION (hpp::Exception, "Failed to start corba server.");
      }
    }
  } // namespace constrained
} // namespace hpp
