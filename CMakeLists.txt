set (package vtk_tcl_thread_util)
project (${package})
cmake_minimum_required (VERSION 2.6)

include (FindTCL)
include (FindPkgConfig)

include_directories(${TCL_INCLUDE_PATH})
include_directories(.)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

set (vtk_tcl_thread_util_SRCS
	local_vtkTclUtil.cc
	vtk_tcl_thread_util.cc
	vtk_tcl_thread_util.h
	vtk_tcl_thread_util_Init.c
)

add_library(vtk_tcl_thread_util MODULE ${vtk_tcl_thread_util_SRCS})

target_link_libraries(vtk_tcl_thread_util ${TCL_LIBRARY} ${TCLARGV_LIBRARY} ${VTK_LIBRARIES} vtkCommonTCL)
set_target_properties (vtk_tcl_thread_util PROPERTIES VERSION 1.0 SOVERSION 1 INSTALL_RPATH_USE_LINK_PATH on PREFIX "" INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib/${package})

# Headers 
install(FILES
	vtk_tcl_thread_util.h
	DESTINATION include/${package})

install(TARGETS vtk_tcl_thread_util DESTINATION lib/${package})

install(FILES
	vtk_tcl_thread_util.tcl
	pkgIndex.tcl
	DESTINATION lib/${package})
