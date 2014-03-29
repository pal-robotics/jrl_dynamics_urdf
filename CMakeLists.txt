# Copyright 2013, Thomas Moulard, LAAS-CNRS
#
# This file is part of roboptim-core.
# roboptim-core is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# roboptim-core is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Lesser Public License for more details.
# You should have received a copy of the GNU Lesser General Public License
# along with roboptim-core.  If not, see <http://www.gnu.org/licenses/>.
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

project(jrl_dynamics_urdf)
find_package(catkin REQUIRED COMPONENTS sot_cmake resource_retriever roscpp urdf jrl-mal jrl-dynamics)

catkin_package(
LIBRARIES jrl_dynamics_urdf
INCLUDE_DIRS include
)

include_directories(${catkin_INCLUDE_DIRS})


INCLUDE(${SOT_CMAKE_DIR}/base.cmake)
INCLUDE(${SOT_CMAKE_DIR}/boost.cmake)
INCLUDE(${SOT_CMAKE_DIR}/lapack.cmake)
INCLUDE(${SOT_CMAKE_DIR}/eigen.cmake)

SET(PROJECT_NAME jrl_dynamics_urdf)
SET(PROJECT_DESCRIPTION "JRL dynamics URDF")
SET(PROJECT_URL "http://github.com/laas/jrl-dynamics-urdf")

SET(CXX_DISABLE_WERROR True)

set(${PROJECT_NAME}_HEADERS
    include/jrl/dynamics/urdf/doc.hh
  include/jrl/dynamics/urdf/parser.hh

  )

SETUP_PROJECT()

# Add main library to pkg-config file.
#PKG_CONFIG_APPEND_LIBS(jrl_dynamics_urdf)

# Search for dependencies.
SEARCH_FOR_BOOST()

ADD_REQUIRED_DEPENDENCY("urdfdom")
ADD_REQUIRED_DEPENDENCY("urdfdom_headers")
ADD_REQUIRED_DEPENDENCY("roscpp")
ADD_REQUIRED_DEPENDENCY("resource_retriever")

# Add Boost path to include directories.
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

# Make sure Boost.Filesystem v2 is used.
ADD_DEFINITIONS(-DBOOST_FILESYSTEM_VERSION=2)

ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(examples)
#ADD_SUBDIRECTORY(tests)

HEADER_INSTALL("${HEADERS}")

SETUP_PROJECT_FINALIZE()
