import numpy as np

# 행렬의 크기와 초기 행렬 입력
n = int(input("행렬의 크기를 입력하세요: "))

# 초기 행렬 입력
initial_matrix = []
print("행렬의 각 행을 공백으로 구분하여 입력하세요:")
for _ in range(n):
    row = list(map(float, input().split()))
    initial_matrix.append(row)

# NumPy 배열로 변환
A = np.array(initial_matrix)

# 행렬의 n 제곱 계산
n_power = int(input("n을 입력하세요: "))
result_matrix = np.linalg.matrix_power(A, n_power)

# 결과 출력
print(f"{n} 제곱 결과:")
print(result_matrix)

