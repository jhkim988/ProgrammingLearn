import java.util.*;

public class ArrayEx2 {
  public static void main(String[] args) {
    int[] iArr1 = new int[10];
    int[] iArr2 = new int[10];
    // int[] iArr3 = new int[] {100, 95, 80, 70, 60}; // 선언과 초기화를 동시에 할 땐 new int[]를 생략할 수 있다.
    int[] iArr3 = {100, 95, 80, 70, 60};
    char[] chArr = {'a', 'b', 'c', 'd'};

    for (int i = 0; i < iArr1.length; i++) {
      iArr1[i] = i + 1;
    }
    for (int i = 0; i < iArr2.length; i++) {
      iArr2[i] = i + 1;
    }
    for (int i = 0; i < iArr1.length; i++) {
      System.out.print(iArr1[i] + ", ");
    }
    System.out.println();
    System.out.println(Arrays.toString(iArr2));
    System.out.println(Arrays.toString(iArr3));
    System.out.println(Arrays.toString(chArr));
    System.out.println(iArr3); // I@-------
    System.out.println(chArr); // println 메서드는 ch[]를 출력할 수 있다.
  }
}
