#!/usr/bin/tclsh
package require vtk_tcl_thread_util

set obj [vtkObject New]
set t [thread::create {package require vtk_tcl_thread_util; thread::wait}]
vtk_tcl_thread_util::register_vtk_object_with_thread $obj $t
