#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <random>

using namespace std;
// 초기화



void Convert3x3To4x4(int** matrix3x3, int** matrix4x4) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			matrix4x4[i][j] = matrix3x3[i][j];
		}
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i < 3 && j < 3) {
				continue;
			}
			matrix4x4[i][j] = (i == j) ? 1 : 0;
		}
	}
}

int GetDeterminant_4x4(int** matrix) {
	int result = 0;
	result += matrix[0][0] * (matrix[1][1] * (matrix[2][2] * matrix[3][3] - matrix[2][3] * matrix[3][2]) -
		matrix[1][2] * (matrix[2][1] * matrix[3][3] - matrix[2][3] * matrix[3][1]) +
		matrix[1][3] * (matrix[2][1] * matrix[3][2] - matrix[2][2] * matrix[3][1]));
	result -= matrix[0][1] * (matrix[1][0] * (matrix[2][2] * matrix[3][3] - matrix[2][3] * matrix[3][2]) -
		matrix[1][2] * (matrix[2][0] * matrix[3][3] - matrix[2][3] * matrix[3][0]) +
		matrix[1][3] * (matrix[2][0] * matrix[3][2] - matrix[2][2] * matrix[3][0]));
	result += matrix[0][2] * (matrix[1][0] * (matrix[2][1] * matrix[3][3] - matrix[2][3] * matrix[3][1]) -
		matrix[1][1] * (matrix[2][0] * matrix[3][3] - matrix[2][3] * matrix[3][0]) +
		matrix[1][3] * (matrix[2][0] * matrix[3][1] - matrix[2][1] * matrix[3][0]));
	result -= matrix[0][3] * (matrix[1][0] * (matrix[2][1] * matrix[3][2] - matrix[2][2] * matrix[3][1]) -
		matrix[1][1] * (matrix[2][0] * matrix[3][2] - matrix[2][2] * matrix[3][0]) +
		matrix[1][2] * (matrix[2][0] * matrix[3][1] - matrix[2][1] * matrix[3][0]));
	return result;
}



void Initialize(int** matrixA, int** matrixB)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			matrixA[i][j] = rand() % 3;
			matrixB[i][j] = rand() % 3;
		}
	}
}
// 행렬 곱셈 함수
void matrixMultiply(int** a, int** b, int** result) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			result[i][j] = 0;
			for (int k = 0; k < 3; ++k) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
// 행렬 덧셈 함수
void matrixPlus(int** a, int** b, int** result) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			result[i][j] = a[i][j] + b[i][j];

		}
	}
}

void matrixMulti(int** a, int** b, int** resultA,int**resultB,const int num) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			resultA[i][j] = a[i][j]*num;
			resultB[i][j] = b[i][j] * num;
		}
	}
}

void matrixMinus(int** a, int** b, int** result) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			result[i][j] = a[i][j] - b[i][j];

		}
	}
}


// 행렬 출력 함수
void printMatrix(int** matrix) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void printMatrix_4X4(int** matrix) {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void printALL(int** a, int** b, int** result)
{
	cout << "Matrix A:" << std::endl;
	printMatrix(a);

	cout << "Matrix B:" << std::endl;
	printMatrix(b);

	cout << "Result Matrix:" << std::endl;
	printMatrix(result);
}

int Get_Determinent_3X3(int matirx_11, int matirx_12, int matirx_13, int matirx_21
	, int matirx_22, int matirx_23, int matirx_31, int matirx_32, int matirx_33)
{
	int result;
	result = matirx_11 * (matirx_22 * matirx_33 - matirx_23 * matirx_32) - matirx_12 * (matirx_21 * matirx_33 - matirx_23 * matirx_31)
		+ matirx_13 * (matirx_21 * matirx_32 - matirx_22 * matirx_31);

	return result;
}


int main()
{
	int** matrixA = new int* [3];

	for (int i = 0; i < 3; ++i) {
		matrixA[i] = new int[3];
	}
	int** matrixB = new int* [3];

	for (int i = 0; i < 3; ++i) {
		matrixB[i] = new int[3];
	}
	int** resultMatrix = new int* [3];

	for (int i = 0; i < 3; ++i) {
		resultMatrix[i] = new int[3];
	}
	int** resultMatrixA = new int* [3];

	for (int i = 0; i < 3; ++i) {
		resultMatrixA[i] = new int[3];
	}
	int** resultMatrixB = new int* [3];

	for (int i = 0; i < 3; ++i) {
		resultMatrixB[i] = new int[3];
	}

	int Determinant_A;
	int Determinant_B;


	Initialize(matrixA, matrixB);


	char order = 'b';

	while (order!= 'q') {
		cout << "프로그램을 시작합니다 단축키를 입력해주세요: ";
		cin >> order;
		//if (char c1 = getchar();) {
		//	cout << "문자 여러개를 입력하시마세요!!!!" << endl;
		//break;
		//}
		
		switch (order) {
			
			

		case 'm':
		case 'M':
			matrixMultiply(matrixA, matrixB, resultMatrix);
			printALL(matrixA, matrixB, resultMatrix);
			break;
		case 'a':
		case 'A':
			matrixPlus(matrixA, matrixB, resultMatrix);
			printALL(matrixA, matrixB, resultMatrix);
			break;
		case'd':
		case'D':
			matrixMinus(matrixA, matrixB, resultMatrix);
			printALL(matrixA, matrixB, resultMatrix);
			break;

		case 'q':
		case 'Q':
			cout << "프로그램을 종료합니다!!" << endl;
			break;

		case 'r':
		case 'R':
			cout << "MatirxA: " << endl;
			printMatrix(matrixA);
			cout << "MatirxB: " << endl;
			printMatrix(matrixB);

			cout << "RESULT_A: " << Get_Determinent_3X3(matrixA[0][0], matrixA[0][1], matrixA[0][2], matrixA[1][0]
				, matrixA[1][1], matrixA[1][2], matrixA[2][0], matrixA[2][1], matrixA[2][2]) << endl;

			cout << "RESULT_B: " << Get_Determinent_3X3(matrixB[0][0], matrixB[0][1], matrixB[0][2], matrixB[1][0]
				, matrixB[1][1], matrixB[1][2], matrixB[2][0], matrixB[2][1], matrixB[2][2]) << endl;

			break;


		case't':
		case 'T':

			for (int i = 0; i < 3; ++i) {
				for (int j = i; j < 3; ++j) {
					int temp = 0;
					temp = matrixA[i][j];
					matrixA[i][j] = matrixA[j][i];
					matrixA[j][i] = temp;

				}
			}


			for (int i = 0; i < 3; ++i) {
				for (int j = i; j < 3; ++j) {
					int temp = 0;
					temp = matrixB[i][j];
					matrixB[i][j] = matrixB[j][i];
					matrixB[j][i] = temp;

				}
			}


			cout << "MatirxA: " << endl;
			printMatrix(matrixA);
			cout << "MatirxB: " << endl;
			printMatrix(matrixB);


			cout << "RESULT_A: " << Get_Determinent_3X3(matrixA[0][0], matrixA[0][1], matrixA[0][2], matrixA[1][0]
				, matrixA[1][1], matrixA[1][2], matrixA[2][0], matrixA[2][1], matrixA[2][2]) << endl;

			cout << "RESULT_B: " << Get_Determinent_3X3(matrixB[0][0], matrixB[0][1], matrixB[0][2], matrixB[1][0]
				, matrixB[1][1], matrixB[1][2], matrixB[2][0], matrixB[2][1], matrixB[2][2]) << endl;
			break;

		case 'h':
		case 'H':
		{
			// 3x3 행렬을 4x4 행렬로 확장
			int** matrixA_4x4 = new int* [4];
			for (int i = 0; i < 4; ++i) {
				matrixA_4x4[i] = new int[4];
			}

			int** matrixB_4x4 = new int* [4];
			for (int i = 0; i < 4; ++i) {
				matrixB_4x4[i] = new int[4];
			}
			Convert3x3To4x4(matrixA, matrixA_4x4);
			cout << "MatirxA: " << endl;
			printMatrix_4X4(matrixA_4x4);
			cout << endl;
			cout << "RESULT_A: " << GetDeterminant_4x4(matrixA_4x4) << endl << endl;


			Convert3x3To4x4(matrixB, matrixB_4x4);
			cout << "MatirxB: " << endl;
			printMatrix_4X4(matrixB_4x4);
			cout << endl;
			cout << "RESULT_B: " << GetDeterminant_4x4(matrixB_4x4) << endl << endl;
			break;
			for (int i = 0; i < 4; ++i) {
				delete[] matrixA_4x4[i];
			}
			delete[] matrixA_4x4;
			matrixA_4x4 = nullptr;


			for (int i = 0; i < 4; ++i) {
				delete[] matrixB_4x4[i];
			}
			delete[] matrixB_4x4;
			matrixB_4x4 = nullptr;

			break;
		}
		case 's':
		case 'S':
			Initialize(matrixA, matrixB);
			cout << "MatirxA: " << endl;
			printMatrix(matrixA);
			cout << "MatirxB: " << endl;
			printMatrix(matrixB);
			break;
		case 'p':
		{
			int order;
			cout << "숫자를 입력해주세요: ";
			cin >> order;
			if (order <= 0 || order >= 10) {
				cout << "잘못입력했습니다!!" << endl;
				break;
			}
			matrixMulti(matrixA, matrixB, resultMatrixA, resultMatrixB, order);
			cout << "MatirxA: " << endl;
			printMatrix(matrixA);
			cout << "MatirxB: " << endl;
			printMatrix(matrixB);
			cout << "resultMatrixA: " << endl;
			printMatrix(resultMatrixA);
			cout << "resultMatrixB: " << endl;
			printMatrix(resultMatrixB);
			break;
		}
		default:
			cout << "제에발 다른거 입력하지마세요!!" << endl;
			break;
		}

	}
	delete(*matrixA);
	delete(*matrixB);
	delete(*resultMatrix);
	delete(*resultMatrixA);
	delete(*resultMatrixB);
	return 0;
}