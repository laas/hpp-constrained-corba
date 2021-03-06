# Copyright (c) 2011 CNRS
# Author: Florent Lamiraux
#
# This file is part of hpp-constrained-corba.
# hpp-constrained-corba is free software: you can redistribute it
# and/or modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation, either version
# 3 of the License, or (at your option) any later version.
#
# hpp-constrained-corba is distributed in the hope that it will be
# useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# hpp-constrained-corba.  If not, see
# <http://www.gnu.org/licenses/>.

# Requires at least CMake 2.6 to configure the package.
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CXX_DISABLE_WERROR true)
SET(CUSTOM_HEADER_DIR "hpp/constrained-corba")

INCLUDE(cmake/base.cmake)
INCLUDE(cmake/cpack.cmake)
INCLUDE(cmake/idl.cmake)
INCLUDE(cmake/python.cmake)

SET(PROJECT_NAME hpp-constrained-corba)
SET(PROJECT_DESCRIPTION "Corba server and python client for hpp-constrained-planner")
SET(PROJECT_URL "http://github.com/laas/hpp-constrained-corba")

SET(${PROJECT_NAME}_HEADERS
  include/hpp/corbaserver/constrained/server.hh
  include/hpp/corbaserver/constrained/fwd.hh
)
SET(CUSTOM_HEADER_DIR hpp/corbaserver/constrained)

SETUP_PROJECT()


# Search for dependencies.
ADD_REQUIRED_DEPENDENCY("hpp-model >= 2.3")
ADD_REQUIRED_DEPENDENCY("hpp-constrained-planner >= 1.0")
ADD_REQUIRED_DEPENDENCY("hpp-template-corba >= 1.1")
ADD_REQUIRED_DEPENDENCY("hpp-util >= 0.6")
# This dependency ensures us that the intermediate __init__.py files are
# already installed.
ADD_REQUIRED_DEPENDENCY("hpp-corbaserver >= 2.1")
# Make sure that python submodule is installed in the same prefix as module.
IF (NOT ${HPP_CORBASERVER_PREFIX} STREQUAL ${CMAKE_INSTALL_PREFIX})
  MESSAGE(WARNING
    "  THIS PACKAGE SHOULD BE INSTALLED IN THE SAME PREFIX AS HPP-CORBASERVER,\n"
    "  SINCE IT INSTALLS A PYTHON SUBMODULE OF HPP.CORBASERVER.")
  MESSAGE("CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
  MESSAGE("HPP_CORBASERVER_PREFIX=${HPP_CORBASERVER_PREFIX}")
ENDIF()

PKG_CONFIG_APPEND_LIBS(${PROJECT_NAME})

ADD_SUBDIRECTORY(src)

SETUP_PROJECT_FINALIZE()
SETUP_PROJECT_CPACK()
