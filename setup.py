from distutils.core import setup, Extension
module1 = Extension('animation',
                  sources=
                        [
                        './lib/curvesimplify.c',
                        './python/py_curvesimplify.c',
                        ],
                  include_dirs=
                        [
                        './python',
                        './lib'
                        ],)

setup(name='animation',
      version='1.0',
      description='animation tools',
      ext_modules=[module1])
