class Data1 {
  // 생성자가 없으므로 Default 생성자가 추가된다.
  int value;
}
class Data2 {
  // 생성자가 존재하므로 Default 생성자가 추가되지 않는다.
  int value;
  Data2(int x) {
    value = x;
  }
}

public class ConstructorTest {
  public static void main(String[] args) {
    Data1 d1 = new Data1();
    // Data2 d2 = new Data2(); // 컴파일 에러, 인자를 받지 않는 생성자(Default)가 없다.
  }
}
