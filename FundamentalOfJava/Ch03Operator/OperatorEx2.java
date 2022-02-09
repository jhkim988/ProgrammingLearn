public class OperatorEx2 {
  public static void main(String[] args) {
    int i = 5;
    int j = 0;
    j = i++; // j = 5, i = 6
    System.out.println("j=i++, i = " + i + ", j = " + j);

    i = 5;
    j = 0;
    j = ++i; // i = 6, j = 6
    System.out.println("j=++i, i = " + i + ", j = " + j);
  }
}
