class MyMath2 {
  long a, b;
  // 인스턴스 변수 a, b만을 사용하여 작업하므로, 매개변수가 필요 없다.
  long add() {
    return a + b;
  }
  long subtract() {
    return a - b;
  }
  long multiply() {
    return a * b;
  }
  double divide() {
    return (double) a / (double) b;
  }

  // 인스턴스 변수와 관계없이 매개수만으로 작업이 가능하다.
  static long add(long a, long b) {
    return a + b;
  }
  static long subtract(long a, long b) {
    return a - b;
  }
  static long multiply(long a, long b) {
    return a * b;
  }
  static double divide(double a, double b) {
    return a / b;
  }
}
public class MyMathTest2 {
  public static void main(String[] args) {
    System.out.println(MyMath2.add(200L, 100L));
    System.out.println(MyMath2.subtract(200L, 100L));
    System.out.println(MyMath2.subtract(200L, 100L));

    MyMath2 mm = new MyMath2();
    mm.a = 200L;
    mm.b = 100L;
    System.out.println(mm.add());
    System.out.println(mm.subtract());
    System.out.println(mm.multiply());
    System.out.println(mm.divide());
  }
}
