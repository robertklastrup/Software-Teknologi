import numpy as np


#opgave 1
print("Opgave 2")


#Task 1
print("Task 1")

array1 = np.array([1,2])
array2 = np.array([1.2, 3.14, 5.5])
array3 = np.array([1 + 2j, 2 + 2j,3 + 3j, 4 + 4j, 5 + 5j])
array4 = np.array([1, 2.2, 3 + 4j, 2, 3.14, 5 + 3j])

print(array1)
print(array2)
print(array3)
print(array4)

print("\n\n")

#Task 2
print("Task 2")

print(array1.dtype)
print(array2.dtype)
print(array3.dtype)
print(array4.dtype)

print("\n\n")

#opgave 2

print ("Opgave 2")

#Task 1
print("Task 1")
#your code
array1 = np.array([1,2])
array2 = np.array([1.2, 3.14, 5.5])
array3 = np.array([1 + 2j, 2 + 2j,3 + 3j, 4 + 4j, 5 + 5j])
array4 = np.array([1, 2.2, 3 + 4j, 2, 3.14, 5 + 3j])

print(array1.shape)
print(array2.shape)
print(array3.shape)
print(array4.shape)
print("\n\n")


#end your code
print("\n\n")

#Task 2
print("Task 2")
#your code
array5 = np.array ([[1,2,3,4,5],
                    [6,7,8,9,10]])

print(array5)
print(array5.shape)

# end your code
print("\n\n")

#Task 3
print("Task 3")
#your code

array6 = np.array ([[[1,2],[3,4],[5,6],[7,8],[9,10],[11,12]],
                    [[13,14],[15,16],[17,18],[19,20],[21,22],[23,24]],
                    [[25,26],[27,28],[29,30],[31,32],[33,34],[35,36]]])

print(array6)
print(array6.shape)


# end your code
print("\n\n")


#opgave 3
print ("Opgave 3")

#Task 1
print("Task 1")
#your code
v_1 = np.array ([4,5])
v_2 = np.array ([9,-4])

v_3 = v_1 + v_2
print (v_3)



# end your code
print("\n\n")

#Task 2
print("Task 2")
#your code
v_1_s = v_1 * 5
v_2_s = v_2 * 5
print(v_1_s)
print(v_2_s)

# end your code
print("\n\n")

#Task 3
print("Task 3")
#your code

x_1 = np.array ([-1,9])
x_2 = np.array ([13,5])
x_3 = x_1 + x_2

x_1_s = x_1 * 5
x_2_s = x_2 * 5

print(x_1, "\n\n", x_2, "\n\n", x_3, "\n\n", x_1_s, "\n\n", x_2_s)

#end your code
print("\n\n")


#Task 4
print("Task 4")
#your code

b = np.array ([[1,-1],[1,1]])

original_s_1 = b @ v_1_s
original_s_2 = b @ v_2_s
original_sum = b @ v_3

print(original_sum)
print(original_s_1)
print(original_s_2)

print("Eftersom overstående resultater matcher dem vi fik i vores udregninger i standardbasen er jeg overbevist")




#end your code


