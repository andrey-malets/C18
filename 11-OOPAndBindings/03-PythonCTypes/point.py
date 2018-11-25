import ctypes


class Point(ctypes.Structure):
    _fields_ = [('x', ctypes.c_int), ('y', ctypes.c_int)]


point_so = ctypes.CDLL('point.so')

p1, p2 = Point(), Point()

init_point = point_so.init_point
init_point.restype = ctypes.POINTER(Point)

p1_ptr = init_point(
    ctypes.byref(p1), ctypes.c_int(3), ctypes.c_int(0)
)

p2_ptr = init_point(
    ctypes.byref(p2), ctypes.c_int(0), ctypes.c_int(4)
)

distance = point_so.distance
distance.restype = ctypes.c_double

print distance(p1_ptr, p2_ptr)
