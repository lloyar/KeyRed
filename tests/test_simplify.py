import animation
from math import *

data = []
n = 512
for t in [x * 2 * pi / n for x in range(n + 1)]:
    data.append((t, sin(t)))

out = animation.simplify(data)

for i in list(range(len(out))):
    print(out[i])
