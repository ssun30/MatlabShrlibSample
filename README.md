# MatlabShrlibSample
Matlab shared library sample to test various string operations


### MacOS X
>>> conda activate cantera-dev
>>> g++ -c shrlibsample.cpp -o shrlibsample.o
>>> g++ -dynamiclib shrlibsample.o -o shrlibsample.dylib

Then in Matlab

>>> loadShrLib
>>> longString
>>> getArray
