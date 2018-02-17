
def t(self, indent=1, width=80, depth=None, stream=None):
    indent = int(indent)
    width = int(width)
    assert indent >= 0, "indent must be >= 0"
    assert depth is None or depth > 0, "depth must be > 0"
    assert width, "width must be != 0"
    self._depth = depth
    self._indent_per_level = indent
    self._width = width
    if stream is not None:
        self._stream = stream
    else:
        self._stream = _sys.stdout

t()
