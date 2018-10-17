int import(int x);

int export(int x) {
    return import(x + 1);
}
