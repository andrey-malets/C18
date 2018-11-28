import ctypes
import os

import contextlib


point_so = ctypes.CDLL(os.path.join(os.curdir, 'point.so'))


@contextlib.contextmanager
def point(x, y):
    class Point(ctypes.Structure):
        _fields_ = [('x', ctypes.c_int), ('y', ctypes.c_int)]

        def __repr__(self):
            return 'Point({}, {})'.format(self.x, self.y)


    new_point = point_so.new_point
    new_point.restype = ctypes.POINTER(Point)

    free_point = point_so.free_point

    p = new_point(x, y)
    try:
        yield p
    finally:
        free_point(p)


with point(0, 3) as p1, point(4, 0) as p2:
    distance = point_so.distance
    distance.restype = ctypes.c_double

    print 'p1: {}, p2: {}'.format(p1.contents, p2.contents)
    print 'distance: {}'.format(distance(p1, p2))
