#!/usr/bin/tclsh
package require vtk_tcl_thread_util

set obj [vtkObject New]
puts "The name of our VTK object in the main thread is $obj. It's refcount is [$obj GetReferenceCount]."
puts "Now we'll spawn a thread and pass the handle of the vtk object to it..." 
set t [thread::create {package require vtk_tcl_thread_util; thread::wait}]
set t_obj [vtk_tcl_thread_util::register_vtk_object $t $obj]
puts "The name of the object in the spawned thread is $t_obj. It's refcount is now [$obj GetReferenceCount]."
puts "Now we'll delete $t_obj in the spawned thread..."
thread::send $t [list $t_obj Delete]
puts "And the refcount of the object is back to [$obj GetReferenceCount]."
puts "You can also specify the name of the object to be registered in another thread. Let's call it...[vtk_tcl_thread_util::register_vtk_object $t $obj $::tcl_platform(user)]." 
