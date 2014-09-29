#ifndef VTK_TCL_THREAD_UTIL_H
#define VTK_TCL_THREAD_UTIL_H

#include <tcl.h>

#ifdef __cplusplus
extern "C" {
#endif

	extern int get_pointer_from_vtk_obj(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]);
	extern int register_vtk_obj(ClientData ClientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]);

#ifdef __cplusplus
}
#endif

#endif
