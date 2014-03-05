// Copyright (C) 2008-2013 LAAS-CNRS, JRL AIST-CNRS.
//
// This file is part of jrl-cmakemodules.
// jrl-mathtools is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// jrl-mathtools is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License
// along with jrl-mathtools.  If not, see <http://www.gnu.org/licenses/>.

#ifndef JRL_DYNAMICS_URDF_CONFIG_HH
# define JRL_DYNAMICS_URDF_CONFIG_HH

// Package version (header).
# define JRL_DYNAMICS_URDF_VERSION "2.0.1-3-gf6c8-dirty"

// Handle portable symbol export.
// Defining manually which symbol should be exported is required
// under Windows whether MinGW or MSVC is used.
//
// The headers then have to be able to work in two different modes:
// - dllexport when one is building the library,
// - dllimport for clients using the library.
//
// On Linux, set the visibility accordingly. If C++ symbol visibility
// is handled by the compiler, see: http://gcc.gnu.org/wiki/Visibility
# if defined _WIN32 || defined __CYGWIN__
// On Microsoft Windows, use dllimport and dllexport to tag symbols.
#  define JRL_DYNAMICS_URDF_DLLIMPORT __declspec(dllimport)
#  define JRL_DYNAMICS_URDF_DLLEXPORT __declspec(dllexport)
#  define JRL_DYNAMICS_URDF_DLLLOCAL
# else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#   define JRL_DYNAMICS_URDF_DLLIMPORT __attribute__ ((visibility("default")))
#   define JRL_DYNAMICS_URDF_DLLEXPORT __attribute__ ((visibility("default")))
#   define JRL_DYNAMICS_URDF_DLLLOCAL  __attribute__ ((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#   define JRL_DYNAMICS_URDF_DLLIMPORT
#   define JRL_DYNAMICS_URDF_DLLEXPORT
#   define JRL_DYNAMICS_URDF_DLLLOCAL
#  endif // __GNUC__ >= 4
# endif // defined _WIN32 || defined __CYGWIN__

# ifdef JRL_DYNAMICS_URDF_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define JRL_DYNAMICS_URDF_DLLAPI
#  define JRL_DYNAMICS_URDF_LOCAL
# else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef jrl_dynamics_urdf_EXPORTS
#   define JRL_DYNAMICS_URDF_DLLAPI JRL_DYNAMICS_URDF_DLLEXPORT
#  else
#   define JRL_DYNAMICS_URDF_DLLAPI JRL_DYNAMICS_URDF_DLLIMPORT
#  endif // JRL_DYNAMICS_URDF_EXPORTS
#  define JRL_DYNAMICS_URDF_LOCAL JRL_DYNAMICS_URDF_DLLLOCAL
# endif // JRL_DYNAMICS_URDF_STATIC
#endif //! JRL_DYNAMICS_URDF_CONFIG_HH
