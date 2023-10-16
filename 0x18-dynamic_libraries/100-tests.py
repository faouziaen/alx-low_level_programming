# 100-tests.py

import random
import ctypes

# Load the shared library
cops = ctypes.CDLL('./100-operations.so')

# Generate random integers
a = random.randint(-111, 111)
b = random.randint(-111, 111)

# Call the C functions from the shared library
result_add = cops.add(a, b)
result_sub = cops.sub(a, b)
result_mul = cops.mul(a, b)
result_divide = cops.divide(a, b)  # Updated function name
result_mod = cops.mod(a, b)

# Print the results
print("{} + {} = {}".format(a, b, result_add))
print("{} - {} = {}".format(a, b, result_sub))
print("{} x {} = {}".format(a, b, result_mul))
print("{} / {} = {}".format(a, b, result_divide))  # Updated function name
print("{} % {} = {}".format(a, b, result_mod))