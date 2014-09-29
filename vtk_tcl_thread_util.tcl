package provide vtk_tcl_thread_util 1.0
package require Thread
package require vtk
load [file join [file dirname [info script]] vtk_tcl_thread_util.so]

proc vtk_tcl_thread_util::register_vtk_object_with_thread {vtk_obj threadid} {
	if {[catch {$vtk_obj GetReferenceCount} err]} {
		error "$vtk_obj is not a VTK object name"
	}
	set ptr [vtk_tcl_thread_util::__get_pointer_from_vtk_obj $vtk_obj]
	return [thread::send $threadid [list vtk_tcl_thread_util::__register_vtk_obj $ptr]] 
}
