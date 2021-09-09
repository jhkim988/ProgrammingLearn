public class ArrayEx1 {
  public static void main(String[] args) {
    int[] score = new int[5];
    int k = 1;

    score[0] = 50;
    score[1] = 60;
    score[k + 1] = 70;
    score[3] = 80;
    score[4] = 90;

    int tmp = score[k + 2] + score[4];
    for (int i = 0; i < 5; i++) {
      System.out.printf("score[%d]: %d\n", i, score[i]);
    }
    System.out.printf("tmp:%d\n", tmp);
    // System.out.printf("score[%d]: %d\n", 7, score[7]); // ArrayIndexOutOfBoundsException

    // 배열 길이는 0이 될 수도 있다.
    
    // 배열이름.length
    // JVM이 모든 배열읠 길이를 별도로 관리한다.
    // 배열은 한 번 생성하면 길이를 변경할 수 없기 때문에 배열이름.length는 상수다.(읽기만 가능하고 수정은 불가능하다.)
  }
}