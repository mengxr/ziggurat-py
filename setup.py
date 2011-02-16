from distutils.core import setup, Extension
import numpy as np 

_ziggurat = Extension( '_ziggurat',
                       sources = ['ziggurat/_ziggurat.c'],
                       include_dirs = [np.get_include()],
                       extra_compile_args = ['-O3'] )

setup ( name = 'ziggurat',
        version = '0.1',
        description = 'Ziggurat RNG',
        author = 'Xiangrui Meng',
        author_email = 'mengxr@stanford.edu',
        packages = ['ziggurat'],
        package_dir = {'ziggurat': 'ziggurat/'},
        ext_package = 'ziggurat',
        ext_modules = [_ziggurat] )
