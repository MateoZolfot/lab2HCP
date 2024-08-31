import numpy as np
import time

def generate_matrix(n):
    return np.random.rand(n, n)

def multiply_matrices(a, b):
    return np.dot(a, b)

n = 10000

# Medir el tiempo para generar una matriz
start_time = time.time()
a = generate_matrix(n)
generation_time = time.time() - start_time
print(f"Time to generate a matrix: {generation_time:.6f} seconds")

# Medir el tiempo para la multiplicación de matrices
b = generate_matrix(n)
start_time = time.time()
result = multiply_matrices(a, b)
multiplication_time = time.time() - start_time
print(f"Time to do the product: {multiplication_time:.6f} seconds")
