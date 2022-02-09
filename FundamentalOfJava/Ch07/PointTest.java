public class PointTest {
  public static void main(String[] args) {
    Point3D p3 = new Point3D(1, 2, 3);
  }  
}

class Point {
  int x, y;
  Point() { } // 임의로 추가
  Point(int x, int y) {
    this.x = x;
    this.y = y;
  }
  String getLocation() {
    return "x: " + x + ", y : " + y;
  }
}
class Point3D extends Point {
  int z;
  Point3D(int x, int y, int z) { 
    // 컴파일러가 이 곳에 super()를 추가한다.
    // super()는 Point의 생성자인데, Point의 생성자 중에 인자를 받지 않는 생성자가 없기 때문에 컴파일 에러가 난다.
    this.x = x;
    this.y = y;
    this.z = z;
  }
}
