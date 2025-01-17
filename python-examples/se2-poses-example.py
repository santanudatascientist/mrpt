#!/usr/bin/env python3

# ---------------------------------------------------------------------
# Install python3-mrpt, or test with a local build with:
# export PYTHONPATH=$HOME/code/mrpt/build-Release/:$PYTHONPATH
# ---------------------------------------------------------------------

from math import radians
from mrpt import pymrpt
mrpt = pymrpt.mrpt

p1 = mrpt.poses.CPose2D(1.0, 2.0, radians(90.0))
p2 = mrpt.poses.CPose2D(3.0, 0.0, radians(0.0))

p3 = p1 + p2
p4 = p3 - p1

print('p1             : ' + str(p1))
print('p2             : ' + str(p2))
print('p1(+)p2        : ' + str(p3))
print('(p1(+)p2)(-)p1 : ' + str(p4))
