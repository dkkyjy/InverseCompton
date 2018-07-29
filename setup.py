import numpy as np
from distutils.core import setup, Extension

InverseCompton_module = Extension('InverseCompton',
                             sources=['InverseCompton.c', 'ElectronDistribution.c'],
                             include_dirs=['/usr/local/include', np.get_include()],
                             library_dirs=['/usr/local/lib'],
                             libraries=['gsl', 'gslcblas'],
                            )

setup(name = 'InverseCompton',
      version = '0.1',
      author = 'Duan Kaikai',
      description = 'InverseCompton emission',
      ext_modules = [InverseCompton_module],
      py_modules = ['InverseCompton'],
     )
