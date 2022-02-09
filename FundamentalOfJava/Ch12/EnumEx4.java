class MyEnum<T extends MyEnum<T>> implements Comparable<T> {
  static int id = 0;
  int ordinal;
  String name = "";
  MyEnum(String name) {
    this.name = name;
    ordinal = id++;
  }
  public int ordinal() { return ordinal; }
  public int compareTo(T t) {
    return ordinal - t.ordinal();
  }
}

abstract class MyTransportation extends MyEnum { // 내부적으로 아래와 같이 구현돼 있기 때문에, 각 열거형 상수마다 추상 메서드를 구현해줘야 했던 것이다.
  public MyTransportation(String name, int basicFare) {
    super(name);
    BASIC_FARE = basicFare;
  }
  static final MyTransportation BUS = new MyTransportation("BUS", 100){
    int fare(int distance) {
      return distance * BASIC_FARE;
    }
  };
  static final MyTransportation TRAIN = new MyTransportation("TRAIN", 150){
    int fare(int distance) {
      return distance * BASIC_FARE;
    }
  };
  static final MyTransportation SHIP = new MyTransportation("SHIP", 100){
    int fare(int distance) {
      return distance * BASIC_FARE;
    }
  };
  static final MyTransportation AIRPLANE = new MyTransportation("AIRPLANE", 300){
    int fare(int distance) {
      return distance * BASIC_FARE;
    }
  };
  protected final int BASIC_FARE;
  public String name() { return name; }
  public String toString() { return name; }
  abstract int fare(int distance);
}

public class EnumEx4 {
  public static void main(String[] args) {
    MyTransportation t1 = MyTransportation.BUS;
    MyTransportation t2 = MyTransportation.BUS;
    MyTransportation t3 = MyTransportation.TRAIN;
    MyTransportation t4 = MyTransportation.SHIP;
    MyTransportation t5 = MyTransportation.AIRPLANE;

    System.out.printf("t1=%s, %d\n", t1.name(), t1.ordinal());
    System.out.printf("t2=%s, %d\n", t2.name(), t2.ordinal());
    System.out.printf("t3=%s, %d\n", t3.name(), t3.ordinal());
    System.out.printf("t4=%s, %d\n", t4.name(), t4.ordinal());
    System.out.printf("t5=%s, %d\n", t5.name(), t5.ordinal());

    System.out.println("t1 == t2 ? " + (t1 == t2));
    System.out.println("t1.colmpareTo(t3) = " + t1.compareTo(t3));
  }
}
