#include "Python.h"
#include "curvesimplify.h"

static PyObject *py_simplify_curve(PyObject *self, PyObject *args) {
    PyObject *pyPointList;
    double error;
    int len;

    if (!PyArg_ParseTuple(args, "Od", &pyPointList, &error)) {
        return NULL;
    }

    len = PySequence_Length(pyPointList);

    Point *pointArray ;
    pointArray = malloc(len * sizeof(Point));
    for (int i = 0; i < len; ++i) {
        PyObject *pyPointTuple = PyObject_GetItem(pyPointList, Py_BuildValue("i", i));

        PyObject *pyFloatT = PyObject_GetItem(pyPointTuple, Py_BuildValue("i", 0));
        PyObject *pyFloatV = PyObject_GetItem(pyPointTuple, Py_BuildValue("i", 1));

        pointArray[i].t = PyFloat_AsDouble(pyFloatT);
        pointArray[i].v = PyFloat_AsDouble(pyFloatV);
    }

    struct KeyFrameNode *firstNode = simplify_curve(&pointArray[0], len, error);

    PyObject *pyList = PyList_New(0);
    struct KeyFrameNode *p = NULL;
    for (p = firstNode; p != NULL; p = p->next) {
        double t = p->key->time;
        double v = p->key->value;
        double l = p->key->leftTangent;
        double r = p->key->rightTangent;

        PyObject *item = Py_BuildValue("(dddd)", t, v, l, r);

        PyList_Append(pyList,item);
    }

    free(firstNode->key);

    struct KeyFrameNode *cur = NULL;
    struct KeyFrameNode *prev = NULL;
    for (cur = firstNode, prev = NULL;
         cur != NULL;
         prev = cur, cur = cur->next)
    {
        free(prev);
    }
    free(cur);

    return pyList;
}

/* Module method table */
static PyMethodDef SampleMethods[] = {
        {"simplify", py_simplify_curve, METH_VARARGS, "Simplify Curve"},
        {NULL, NULL, 0, NULL}
};

/* Module structure */
static struct PyModuleDef animationModule = {
        PyModuleDef_HEAD_INIT,

        "animation",           /* name of module */
        "An animation tools module",  /* Doc string (may be NULL) */
        -1,                 /* Size of per-interpreter state or -1 */
        SampleMethods       /* Method table */
};

/* Module initialization function */
PyMODINIT_FUNC
PyInit_animation(void) {
    return PyModule_Create(&animationModule);
}