import numpy as np
#define the coordinates as 1-dim array v_b
v_b = np.array ([3,5,8,-1])
# end

#Use the definitions of the transformation matrices from above to calculate the coordinates v_f in the f basis and print
b_1 = np.array([1,1,1,1])
b_2 = np.array([1,1,-1,1])
b_3 = np.array([1,-1,1,1])
b_4 = np.array([1,1,1,-1])
b = np.column_stack([b_1, b_2, b_3, b_4])
print(b)

f_1 = np.array ([1,-14,23,1])
f_2 = np.array ([1,0,-1,1])
f_3 = np.array ([1,-1,1,0])
f_4 = np.array ([1,1,0,-1])
f = np.column_stack((f_1,f_2,f_3,f_4))
print(f)

v_f = np.linalg.inv(f) @ b @ v_b
print(v_f)

#end
# Verify the result. This can be done by using np.allclose(a,b) which compares all data in the two arrays
# And then comparing B@v_b and F@v_f. why?
print(np.allclose(b @ v_b, f @ v_f))