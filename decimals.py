import random


with open('/home/tati/school/matrix/matrix.txt', 'w') as matrix_file:
    i = 0
    while i < 3:
        row = random.randrange(1, 3)
        col = random.randrange(1, 3)
        print(row, file = matrix_file)
        print(col, file = matrix_file)
        for j in range(row * col):
            print(random.uniform(-10, 10), file = matrix_file)
               
        i += 1
        print(file = matrix_file)
    print(file = matrix_file)

