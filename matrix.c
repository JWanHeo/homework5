#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void print_matrix(int ** matrix, int row, int col);
void addition_matrix(int **matrixA, int **matrixB, int row, int col);
void free_matrix(int **matrix, int rows);

int main(void) 
{
  int aRow, aCol, bRow, bCol;

  printf("A�� ��/�� : ");
  scanf("%d %d", &aRow, &aCol); // A�� ��� �� �Է�
  printf("B�� ��/�� : ");
  scanf("%d %d", &bRow, &bCol); // B�� ��� �� �Է�
  printf("\n");

  /*��� A�� �����Ҵ��� ���� ����*/
  int **A = (int**)malloc(aRow * sizeof(int)); // A�� �� ����
  for(int i = 0; i < aRow; i++) { 
    A[i] = (int*)malloc(aCol * sizeof(int)); // A�� �࿡ ���߾� �� ����
  }  

  /*��� B�� �����Ҵ��� ���� ����*/
  int **B = (int**)malloc(bRow * sizeof(int)); // B�� �� ����
  for(int i = 0; i < bRow; i++) {
    B[i] = (int*)malloc(bCol * sizeof(int)); // B�� �࿡ ���߾� �� ����
  }  

  /*A�� ��ҵ鿡 ������ �� �ֱ�*/
  for(int i = 0; i < aRow; i++) {
    for(int j = 0; j < aCol; j++) {
      A[i][j] = rand(); // A�� ��ҵ��� ��ȸ�ϸ� ������ int �� �Ҵ�
    }
  }

  printf("[��� A]\n");
  print_matrix(A, aRow, aCol); // A�� ��Ҹ� ä�� �� ���� ����Ͽ� Ȯ��

  /*A�� ��ҵ鿡 ������ �� �ֱ�*/
  srand(time(NULL)); // rand �� �ʱ�ȭ
  for(int i = 0; i < bRow; i++) {
    for(int j = 0; j < bCol; j++) {
      B[i][j] = rand(); // B�� ��ҵ��� ��ȸ�ϸ� ������ int �� �Ҵ�
    }
  }

  printf("[��� B]\n");
  print_matrix(B, bRow, bCol); // B�� ��Ҹ� ä�� �� ���� ����Ͽ� Ȯ��

  printf("[A + B]\n");
  addition_matrix(A, B, aRow, aCol);


  free_matrix(A, aRow);
  free_matrix(B, bRow);

  return 0;
}

/*����� ���� ����ϴ� �Լ�*/
void print_matrix(int ** matrix, int row, int col) { // ��İ� ����� ��� ���� �Ű������� ����

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      printf("%d\t", matrix[i][j]); // �� ���� ���� ��ȸ�ϸ� �� �� ���
    }
    printf("\n"); // �� ���� ���� ���� ����ϸ� �ٹٲ�
  }
    printf("\n");
}

/*�� ����� ���ϴ� �Լ�*/
void addition_matrix(int **matrixA, int **matrixB, int row, int col) { // ������ ������ ��� A�� B, ��� ���� �Ű������� ����

  int **C = (int**)malloc(row * sizeof(int)); // ����� ������ ��� C ����
  for(int i = 0; i < row; i++) { 
    C[i] = (int*)malloc(col * sizeof(int));
  }
  
  for(int i = 0; i < row; i++) { // C�� A+B�� ������ ����� ����
    for(int j = 0; j < col; j++) {
      C[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }

  print_matrix(C, row, col); // C ����� ���

  free_matrix(C, row); // C�� �Ҵ�� �޸� ����

} 

/*����� ���� �Ҵ��ߴ� �޸� ���� �Լ�*/
void free_matrix(int **matrix, int rows) { // ��İ� ���� ������ �Ű������� ����
    for (int i = 0; i < rows; i++) { // �ݺ����� ���� �� ���� ���� �Ҵ��ߴ� �޸� ����
        free(matrix[i]);
    }
    free(matrix); // �࿡ �Ҵ��ߴ� �޸� ����
}