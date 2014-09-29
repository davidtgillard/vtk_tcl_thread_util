#include <vtkTclUtil.h>
#include "vtk_tcl_thread_util.h"

int get_pointer_from_vtk_obj(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
	char buff[1024];
	char *obj_name=NULL;
	void *vtk_ptr=NULL;
	int err=0;
	// ensure number of arguments is correct
	if (objc!=2) {
		Tcl_WrongNumArgs(interp,1,objv,"vtk_object_name");
		return TCL_ERROR;
	}
	obj_name = Tcl_GetStringFromObj(objv[1],NULL);
	// try to get pointer from vtk object name
	vtk_ptr = vtkTclGetPointerFromObject(obj_name,"vtkObject",interp,err);
	if (err) {
		Tcl_ResetResult(interp);
		Tcl_AppendResult(interp,"Error getting pointer from vtk object ",obj_name,NULL);
		return TCL_ERROR;
	}
	// return pointer as string
	sprintf(buff,"%p",vtk_ptr);
	Tcl_AppendResult(interp,buff,NULL);
	return TCL_OK;
}

int register_vtk_obj(ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
	const char *ptr_string;
	char *str_part;
	void * vtk_ptr;
	// ensure number of arguments is correct
	if (objc!=2) {
		Tcl_WrongNumArgs(interp,1,objv,"vtk_object_ptr");
		return TCL_ERROR;
	}
	ptr_string = Tcl_GetStringFromObj(objv[1],NULL);
	vtk_ptr = (void *)strtol(ptr_string, &str_part, 0);
	// try to get vtk object from pointer
	vtkTclGetObjectFromPointer(interp,vtk_ptr,"vtkObject");
	return TCL_OK;
} 
