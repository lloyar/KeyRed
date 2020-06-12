# KeyRed

Language: [English](README.md) | [中文](doc/README_ZH.md)
-------

Keyframe reduction is a python library written in C. The main function of the database is to obtain a small number of control points and to fit complex curves.

## Quick Start

1. Build:
```shell script
$ git clone https://github.com/Realibox/KeyRed.git
$ cd KeyRed
$ python setup.py build
```

2. Install the library
```shell script
$ python setup.py install
```

1. run test script: `$ python test_simplify.py`.

## Example

Usage:

```python
import animation
from math import *

data = []
n = 512
error = 0.05
for t in [x * 2 * pi / n for x in range(n + 1)]:
    data.append((t, sin(t)))

out = animation.simplify(data, error)

for i in list(range(len(out))):
    print(out[i])
```