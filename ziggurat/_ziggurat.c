#include <Python.h>
#include <numpy/arrayobject.h>

#include <math.h>
#include <stdlib.h>

/* redefine types for 64-bit machine */
#define long int
#define fabs abs
#define float double

#include "rnorrexp.c"

static PyObject* _ziggurat_seed(PyObject *self, PyObject *args)
{
  int seed;

  if(!PyArg_ParseTuple(args, "i", &seed))
    return NULL;

  zigset(seed);

  Py_RETURN_NONE;
}

  
static PyObject* _ziggurat_randn(PyObject *self, PyObject *args)
{
  PyArrayObject *py_mat;
  double *mat;
  npy_intp dims[1] = {0};
  int n, i;
  
  if(!PyArg_ParseTuple(args, "i", &n))
    return NULL;

  dims[0] = n;
  py_mat = (PyArrayObject *) PyArray_SimpleNew(1,dims,NPY_DOUBLE);
  mat    = (double *) py_mat->data;
  
  for( i=0; i<n; ++i )
    mat[i] = (double) RNOR;
  
  return PyArray_Return(py_mat);
}

static PyMethodDef _ziggurat_methods[] = 
  {
    {
      "randn", _ziggurat_randn, METH_VARARGS
    },
    {
      "seed", _ziggurat_seed, METH_VARARGS
    },
    {
      NULL, NULL
    },
  };

PyMODINIT_FUNC init_ziggurat(void)
{
  (void) Py_InitModule("_ziggurat", _ziggurat_methods);
  import_array();
}

