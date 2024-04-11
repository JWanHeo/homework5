#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void print_matrix(int ** matrix, int row, int col);
void addition_matrix(int **matrixA, int **matrixB, int row, int col);
void free_matrix(int **matrix, int rows);

int main(void) 
{
  int aRow, aCol, bRow, bCol;

  printf("A의 행/열 : ");
  scanf("%d %d", &aRow, &aCol); // A의 행과 열 입력
  printf("B의 행/열 : ");
  scanf("%d %d", &bRow, &bCol); // B의 행과 열 입력
  printf("\n");

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