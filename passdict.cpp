#include <Python.h>

#include <iostream>

// Get all the keys from a dictionary and print them to the console

static PyObject *
passdict( PyObject *self, PyObject *pyArgs ) {

//  Py_Initialize();
  PyObject *pyDict;
  PyObject *pyKeyList;

  if( !PyArg_ParseTuple(pyArgs,"O!",&PyDict_Type,&pyDict ) ) {
    return NULL;
  }
  

  // Get a list of all the keys
  pyKeyList = PyDict_Keys(pyDict);

  if( PyList_Check(pyKeyList) ) {
    std::cout << "Extracted a list of keys from dictionary" << std::endl;
  }
  
  Py_ssize_t len = PyList_Size(pyKeyList);
  
  
  std::cout << "The dictionary contains " << len << " keys" << std::endl;
 
  for( Py_ssize_t i=0; i<len; ++i ) {

    std::cout << "Key " << i << " is of ";

    PyObject *pyKey = PyList_GetItem(pyKeyList,i);
    PyObject *pyValue = PyDict_GetItem(pyDict,pyKey);

    if(PyUnicode_Check(pyKey)) {
      PyObject *pyTemp = PyUnicode_AsEncodedString(pyKey,"ASCII","strict");
      
      std::cout << "string type" << " and is equal to \"" << PyBytes_AsString(pyTemp) 
                << "\"" << std::endl;

      Py_XDECREF(pyTemp);

   }    
    else if(PyLong_Check(pyKey)) {
      std::cout << "long type" << " and is equal to " << PyLong_AsLong(pyKey) << std::endl;
    }
   
    std::cout << "The corresponding value is of type ";
    
    if( PyUnicode_Check(pyValue)) {
      PyObject *pyTemp = PyUnicode_AsEncodedString(pyValue,"ASCII","strict");
      
      std::cout << "string type" << " and is equal to \"" << PyBytes_AsString(pyTemp) 
                << "\"" << std::endl;

      Py_XDECREF(pyTemp);
    }
    else if(PyLong_Check(pyKey)) {
      std::cout << "long type" << " and is equal to " << PyLong_AsLong(pyValue) << std::endl;
    }
 

  }
//  Py_XDECREF(pyKeyList);
//  Py_Finalize();
  return Py_None;
}

static char passdict_doc[] = 
  "passdict( ) : print all the keys from a Python dictionary";

static PyMethodDef passdict_methods[] = {
  {"passdict", (PyCFunction)passdict,METH_VARARGS,passdict_doc},
  {NULL,NULL,0,NULL}
};

static struct PyModuleDef passdict_module =  {
  PyModuleDef_HEAD_INIT,
  "passdict",
  passdict_doc,
  -1,
  passdict_methods
};

PyMODINIT_FUNC
PyInit_passdict(void) {
  return PyModule_Create(&passdict_module);
}





