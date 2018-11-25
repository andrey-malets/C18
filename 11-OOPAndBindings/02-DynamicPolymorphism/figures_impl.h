
struct FigureOps {
  struct Figure *(*allocate)(size_t size);
  void (*deallocate)(struct Figure *s);

  double area(void);
};
