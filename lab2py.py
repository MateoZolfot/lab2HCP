import random
import time

def generate_matrix(n):
    return [[random.random() for _ in range(n)] for _ in range(n)]

def multiply_matrices(a, b):
    n = len(a)
    result = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += a[i][k] * b[k][j]
    return result

n = 1000  # Por ejemplo, n = 1000

# Medir el tiempo para generar una matriz
start_time = time.time()
a = generate_matrix(n)
generation_time = time.time() - start_time
print(f"Time to generate a matrix: {generation_time:.6f} seconds")

# Medir el tiempo para la multiplicación de matrices
b = generate_matrix(n)  # Generar la segunda matriz
start_time = time.time()
result = multiply_matrices(a, b)
multiplication_time = time.time() - start_time
print(f"Time to do the product: {multiplication_time:.6f} seconds")
