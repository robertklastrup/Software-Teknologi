import numpy as np
#define all b basis vectors as 1-dim arrays
b_1 = np.array ([1,1,1,1])
b_2 = np.array ([1,1,-1,1])
b_3 = np.array ([1,-1,1,1])
b_4 = np.array ([1,1,1,-1])

#end

#Stack to matrix and assert det non-zero
b = np.column_stack((b_1,b_2,b_3,b_4))
print(b)

detb = np.linalg.det(b)
print(detb)

assert detb != 0, "Determinaten er 0 og er ikke lineært uafhængige"
print ("Vektorerne udgør en gyldig basis")

#end

#define all f basis vectors as 1-dim arrays
f_1 = np.array ([1,-14,23,1])
f_2 = np.array ([1,0,-1,1])
f_3 = np.array ([1,-1,1,0])
f_4 = np.array ([1,1,0,-1])
#end

#Stack to matrix and assert det non-zero
f = np.column_stack((f_1,f_2,f_3,f_4))
print(f)

detf = np.linalg.det(f)
print(detf)

assert detb != 0, "Determinaten er 0 og er ikke lineært uafhængige"
print ("Vektorerne udgør en gyldig basis")
#end