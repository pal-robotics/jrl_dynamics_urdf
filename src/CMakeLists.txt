# Copyright 2013, Thomas Moulard, LAAS_CNRS
#
# This file is part of roboptim_core.
# roboptim_core is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# roboptim_core is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Lesser Public License for more details.
# You should have received a copy of the GNU Lesser General Public License
# along with roboptim_core.  If not, see <http://www.gnu.org/licenses/>.

ADD_LIBRARY(jrl_dynamics_urdf SHARED ${HEADERS} parser.cc)
TARGET_LINK_LIBRARIES(jrl_dynamics_urdf ${Boost_LIBRARIES} ${catkin_LIBRARIES})

INSTALL(TARGETS jrl_dynamics_urdf DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
