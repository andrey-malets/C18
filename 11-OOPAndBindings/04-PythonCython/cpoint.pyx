# cython: language_level=2

cdef extern from "point.h":
    cdef struct point:
        int x;
        int y;

    double c_distance(const point p1,
                      const point p2)


def distance(p1, p2):
    return c_distance(p1, p2)
