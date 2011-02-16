from time import time

from numpy import reshape, floor

import _ziggurat

def seed(s):
    _ziggurat.seed(int(s))

def randn(*dims):
    if len(dims) > 0:
        sz = dims[0]
        for dim in dims[1:]:
            sz *= dim
        A = reshape(_ziggurat.randn(int(sz)),dims)
    else:
        A = None
    return A

# initialize seed using current time
t = time()
seed((t-floor(t))*1e6)
