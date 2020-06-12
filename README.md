# Quick Start
Language: [English](README.md) | [中文](README_ZH.md)
1. build `.so` file: `$ python3 setup.py build_ext --inplace`.

2. To be importable, the shared library (`.so` file) must be available on [PYTHONPATH](https://docs.python.org/3.7/using/cmdline.html#envvar-PYTHONPATH).

3. run test script: `$ python test_simplify.py`.