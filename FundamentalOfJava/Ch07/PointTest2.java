public class PointTest2 {
  public static void main(String[] args) {
    Point3D p3 = new Point3D(1, 2, 3);
    System.out.println("p3.x = " + p3.x);
    System.out.println("p3.y = " + p3.y);
    System.out.println("p3.z = " + p3.z);
  }  
}

class Point {
  int x, y;
  Point(int x, int y) {
    // 컴파일러는 여기에도 super()를 삽입한다. Point는 Object 클래스를 기본으로 상속받는다.
    this.x = x;
    this.y = y;
  }
  String getLocation() {
    return "x: " + x + ", y : " + y;
  }
}
class Point3D extends Point{
  int z;
  Point3D(int x, int y, int z) { 
    super(x, y);
    this.z = z;
  }
}
