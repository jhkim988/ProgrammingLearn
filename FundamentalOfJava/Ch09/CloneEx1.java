// Object 클래스의 clone 메서드는 단순히 인스턴스 변수의 값만 복사한다.
// 인스턴스 변수가 참조타입이라면 완전한 복제가 이루어지지 않는다.
// 그런 경우에 clone을 오버라이딩 해야한다.

// Object 클래스의 clone 메서드의 접근제어자는 protected이다.
// public으로 바꿔줘야 상속관계가 없는 다른 클래스에서 clone()을 호출할 수 있다.

class Point implements Cloneable {
  // Clonable 인터페이스를 구현한 클래스에서만 clone()을 호출할 수 있다.
  int x, y;
  Point(int x, int y) {
    this.x = x;
    this.y = y;
  }
  public String toString() {
    return "x=" + x + ", y=" + y;
  }
  public Object clone() {
    Object obj = null;
    try { // Clone은 예외처리를 반드시 해주어야 한다.
      obj = super.clone();
    } catch (CloneNotSupportedException e) { }
    return obj;
  }
}

public class CloneEx1 {
  public static void main(String[] args) {
    Point original = new Point(3, 5);
    Point copy = (Point) original.clone();
    System.out.println(original);
    System.out.println(copy);
  }
}
