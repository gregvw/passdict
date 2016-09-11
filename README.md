# passdict
Pass a Python dictionary to the C API and print out its keys/value and their types.

This code iterates over the list of keys and gets the corresponding values and reports their 
types and data if they are string (Python 3 equivalent being unicode) or 
long. Extension to other types looks pretty straightforward.
