import numpy as np

# Example NumPy array
array = np.array([1, 2, 3, 4, 5])

# Convert the array to a string with spaces separating the elements
array_string = np.array2string(array)[1:-1]

# Print the resulting string
print(array, array_string)
# [1 2 3 4 5] 1 2 3 4 5

print(np.where(array == 3))
print(np.where(array == 3)[0])
print(np.where(array == 3)[0][0])
# (array([2], dtype=int64),)
# [2]
# 2

print(np.random.choice(array, size=1)[0])
# 4 (any from 1, 2, 3, 4, 5)