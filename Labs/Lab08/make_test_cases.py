import numpy as np
import random

number_of_test_cases = 100

# Function to generate random increasing arrays
def random_increasing_array(length, max_value):
    distinct_numbers = set()

    while len(distinct_numbers) < length:
        distinct_numbers.add(random.randint(1, max_value))

    random_array = np.array(list(distinct_numbers))
    # random_array = np.random.randint(1, max_value, length)
    random_array.sort()
    return random_array

json_file = open("trials.json", "w")

# First 2 test cases
json_file.write("{\n\t\"test_cases\": [\n")
json_file.write("\t{\n\t\"id\": 1,\n\t\"time_out\": 2,\n\t\"input\": \"1\\n6\\n1 3 4 6 8 9\\n3\\n\",\n\t\"output\": \"This program supports these operations:\\n\\t1. Search a key in a non-decreasing sequence of integers.\\n\\n\\t2. Count the number of vowels in a string.\\n\\nChoose an operation: How many numbers do you want to enter (between 1 and 100)? Enter 6 integers in non-decreasing order (no duplicates): Enter the key to search: 3 found at index 1.\\n\"\n\t},\n\t{\n\t\"id\": 2,\n\t\"time_out\": 2,\n\t\"input\": \"2\\nred\\n\",\n\t\"output\": \"This program supports these operations:\\n\\t1. Search a key in a non-decreasing sequence of integers.\\n\\n\\t2. Count the number of vowels in a string.\\n\\nChoose an operation: Enter a string: red has 1 vowels\\n\"\n\t},\n")

for id_num in range(3, number_of_test_cases + 1):
    json_file.write("\t{\n")
    json_file.write(f"\t\"id\": {id_num},\n")
    json_file.write(f"\t\"time_out\": 2,\n")

    # Change this if you want
    arr_length = random.randint(6, 15)
    # Change this if you want
    max_value = random.randint(15, 30)

    arr = random_increasing_array(arr_length, max_value)
    arr_str = np.array2string(arr, separator=' ')[1:-1]
    
    # Either the number is in the array or else it is not
    if random.randint(0, 1) == 0:
        key = random.randint(max_value + 1, max_value + 100)
        #key = random.randint(1, max_value)
        #while(np.isin(key, arr)):
        #    key = random.randint(1, max_value)
        result = f"{key} not found"
    else:
        index = random.randint(0, arr_length-1)
        key = arr[index]
        result = f"{key} found at index {index}"

    inp = f"1\\n{arr_length}\\n{arr_str}\\n{key}\\n"
    json_file.write(f"\t\"input\": \"{inp}\",\n")

    outp = f"This program supports these operations:\\n\\t1. Search a key in a non-decreasing sequence of integers.\\n\\n\\t2. Count the number of vowels in a string.\\n\\nChoose an operation: How many numbers do you want to enter (between 1 and 100)? Enter {arr_length} integers in non-decreasing order (no duplicates): Enter the key to search: {result}\\n"
    json_file.write(f"\t\"output\": \"{outp}\"\n")
    json_file.write("\t}")

    if id_num != number_of_test_cases:
        json_file.write(",")
    json_file.write("\n")

json_file.write("]\n}")

