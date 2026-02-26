import numpy as np
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
