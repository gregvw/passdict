import sys
from distutils.core import setup, Extension

if sys.version_info[0] == 3:

  module = Extension('passdict',sources = ['passdict.cpp'])

  setup(name='passdict', 
        version='1.0',
        description='Pass a Python dictionary to C++ and print out all of its keys',
        ext_modules=[module])

else:
  print("This example requires building with Python 3")

