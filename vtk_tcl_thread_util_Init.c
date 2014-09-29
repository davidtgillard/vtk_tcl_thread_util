#include <stdio.h>
#include <stdlib.h>
#include <tcl.h>
#include "vtk_tcl_thread_util.h"

int Vtk_tcl_thread_util_Init(Tcl_Interp *interp) {
	/* initialize the stub table interface */
	if (Tcl_InitStubs(interp,"8.5",0)==NULL) {
		return TCL_ERROR;
	}
	/* Create all of the Tcl commands */
	Tcl_CreateObjCommand(interp,"::vtk_tcl_thread_util::__get_pointer_from_vtk_obj",get_pointer_from_vtk_obj,
			(ClientData)NULL,(Tcl_CmdDeleteProc *)NULL);
	Tcl_CreateObjCommand(interp,"::vtk_tcl_thread_util::__register_vtk_obj",register_vtk_obj,
	                     (ClientData)NULL,(Tcl_CmdDeleteProc *)NULL);           
	return TCL_OK;
}
