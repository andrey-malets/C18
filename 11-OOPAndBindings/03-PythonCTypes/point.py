import ctypes
import os


class Point(ctypes.Structure):
    _fields_ = [('x', ctypes.c_int), ('y', ctypes.c_int)]

    def __repr__(self):
        return 'Point({}, {})'.format(self.x, self.y)


point_so = ctypes.CDLL(os.path.join(os.curdir, 'point.so'))

p1, p2 = Point(), Point()
print 'before init: {}, {}'.format(p1, p2)

init_point = point_so.init_point
init_point.restype = ctypes.POINTER(Point)

p1_ptr = init_point(
    ctypes.byref(p1), ctypes.c_int(3), ctypes.c_int(0)
)
print '*p1_ptr: {}'.format(p1_ptr.contents)

p2_ptr = init_point(
    ctypes.byref(p2), ctypes.c_int(0), ctypes.c_int(4)
)
print '*p2_ptr: {}'.format(p2_ptr.contents)

print 'after init: {}, {}'.format(p1, p2)

distance = point_so.distance
distance.restype = ctypes.c_double

print 'distance: {}'.format(distance(p1_ptr, p2_ptr))
