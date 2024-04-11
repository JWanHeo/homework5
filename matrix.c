#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void print_matrix(int ** matrix, int row, int col);
void addition_matrix(int **matrixA, int **matrixB, int row, int col);
void free_matrix(int **matrix, int rows);
void substraction_matrix(int **matrixA, int **matrixB, int row, int col);
void transpose_matrix(int **matrix, int row, int col);
void multiply_matrix(int **matrixA, int **matrixB, int aRow, int aCol, int bRow, int bCol);

int main(void) 
{

  printf("[----- 허제완 2020069031 -----]\n\n");

  int aRow, aCol, bRow, bCol;

  printf("A의 행/열 : ");
  scanf("%d %d", &aRow, &aCol); // A의 행과 열 입력
  printf("B의 행/열 : ");
  scanf("%d %d", &bRow, &bCol); // B의 행과 열 입력
  printf("\n");

  if(aRow != bRow || aCol != bCol) {
    printf("A + B 및 A - B 수행을 위해 A의 행/열과 B의 행/열은 같아야 합니다.");
    return 1;
  }

  /*행렬 A를 동적할당을 통해 생성*/
  int **A = (int**)malloc(aRow * sizeof(int)); // A의 행 생성
  for(int i = 0; i < aRow; i++) { 
    A[i] = (int*)malloc(aCol * sizeof(int)); // A의 행에 맞추어 열 생성
  }  

  /*행렬 B를 동적할당을 통해 생성*/
  int **B = (int**)malloc(bRow * sizeof(int)); // B의 행 생성
  for(int i = 0; i < bRow; i++) {
    B[i] = (int*)malloc(bCol * sizeof(int)); // B의 행에 맞추어 열 생성
  }  

  /*A의 요소들에 랜덤한 값 넣기*/
  for(int i = 0; i < aRow; i++) {
    for(int j = 0; j < aCol; j++) {
      A[i][j] = rand(); // A의 요소들을 순회하며 랜덤한 int 값 할당
    }
  }

  printf("[행렬 A]\n");
  print_matrix(A, aRow, aCol); // A의 요소를 채운 후 값을 출력하여 확인

  /*A의 요소들에 랜덤한 값 넣기*/
  srand(time(NULL)); // rand 값 초기화
  for(int i = 0; i < bRow; i++) {
    for(int j = 0; j < bCol; j++) {
      B[i][j] = rand(); // B의 요소들을 순회하며 랜덤한 int 값 할당
    }
  }

  printf("[행렬 B]\n");
  print_matrix(B, bRow, bCol); // B의 요소를 채운 후 값을 출력하여 확인

  printf("[A + B]\n");
  addition_matrix(A, B, aRow, aCol);

  printf("[A - B]\n");
  substraction_matrix(A, B, aRow, aCol);

  printf("[A의 전치행렬 T]\n");
  transpose_matrix(A, aRow, aCol);

  printf("[A x B]\n");
  multiply_matrix(A, B, aRow, aCol, bRow, bCol);


  free_matrix(A, aRow);
  free_matrix(B, bRow);

  return 0;
}

/*행렬의 값을 출력하는 함수*/
void print_matrix(int ** matrix, int row, int col) { // 행렬과 행렬의 행과 열을 매개변수로 받음

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      printf("%d\t", matrix[i][j]); // 각 행의 열을 순회하며 각 값 출력
    }
    printf("\n"); // 각 행의 열을 전부 출력하면 줄바꿈
  }
    printf("\n");
}

/*두 행렬을 더하는 함수*/
void addition_matrix(int **matrixA, int **matrixB, int row, int col) { // 연산을 수행할 행렬 A와 B, 행과 열을 매개변수로 받음

  int **C = (int**)malloc(row * sizeof(int)); // 결과를 저장할 행렬 C 생성
  for(int i = 0; i < row; i++) { 
    C[i] = (int*)malloc(col * sizeof(int));
  }
  
  for(int i = 0; i < row; i++) { // C에 A+B를 수행한 결과를 저장
    for(int j = 0; j < col; j++) {
      C[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }

  print_matrix(C, row, col); // C 행렬을 출력

  free_matrix(C, row); // C에 할당된 메모리 해제

} 

/*행렬을 위해 할당했던 메모리 해제 함수*/
void free_matrix(int **matrix, int rows) { // 행렬과 행의 개수를 매개변수로 받음
    for (int i = 0; i < rows; i++) { // 반복문을 돌며 각 행의 열에 할당했던 메모리 해제
        free(matrix[i]);
    }
    free(matrix); // 행에 할당했던 메모리 해제
}

/*두 행렬의 뺄셈을 수행하는 함수*/
void substraction_matrix(int **matrixA, int **matrixB, int row, int col) {

  int **C = (int**)malloc(row * sizeof(int)); // 결과를 저장할 행렬 C 생성
  for(int i = 0; i < row; i++) { 
    C[i] = (int*)malloc(col * sizeof(int));
  }

  for(int i = 0; i < row; i++) { // C에 A-B를 수행한 결과를 저장
    for(int j = 0; j < col; j++) {
      C[i][j] = matrixA[i][j] - matrixB[i][j];
    }
  }

  print_matrix(C, row, col); // C 행렬을 출력

  free_matrix(C, row); // C에 할당된 메모리 해제
}

/*행렬의 전치행렬을 구하는 함수*/
void transpose_matrix(int **matrix, int row, int col) { // 전치할 행렬과 그 행렬의 행과 열을 매개변수로 받음

  int **T = (int**)malloc(row * sizeof(int)); // 결과를 저장할 행렬 T 생성
  for(int i = 0; i < row; i++) { 
    T[i] = (int*)malloc(col * sizeof(int));
  }

  for(int i = 0; i < row; i++) { // T에 matrix를 전치한 결과를 저장
    for(int j = 0; j < col; j++) {
      T[i][j] = matrix[j][i];
    }
  }

  print_matrix(T, row, col); // T 행렬을 출력

  free_matrix(T, row); // T에 할당된 메모리 해제
}

/*두 행렬의 곱셈을 수행하는 함수*/
void multiply_matrix(int **matrixA, int **matrixB, int aRow, int aCol, int bRow, int bCol) {

  int **C = (int**)malloc(aRow * sizeof(int)); // 결과를 저장할 행렬 C 생성
  for(int i = 0; i < aRow; i++) { 
    C[i] = (int*)calloc(bCol, sizeof(int));
  }

  for(int i = 0; i < aRow; i++) { // C에 A x B를 수행한 결과를 저장
    for(int j = 0; j < bCol; j++) {
      for(int k = 0; k < aCol; k++) {
        C[i][j] += matrixA[i][k] * matrixB[k][i]; // A의 행의 원소들과 B의 열의 원소들을 곱한 값을 더하여 C의 각 행과 열에 저장
      }
    }
  }

  print_matrix(C, aRow, bCol); // C 행렬을 출력

  free_matrix(C, aRow); // C에 할당된 메모리 해제
}