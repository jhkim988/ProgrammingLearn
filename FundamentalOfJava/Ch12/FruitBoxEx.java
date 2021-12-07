import java.util.*;

// 참조변수와 생성자에 대입된 타입변수가 일치해야한다.
// 타입변수 간에 상속관계가 있더라도 안된다.(일치해야한다)
// 지네릭 클래스 간에 상속관계가 있고, 타입변수가 같은 것은 괜찮다.

class Fruit { public String toString() {return "Fruit";} }
class Apple extends Fruit { public String toString() {return "Apple";} }
class Grape extends Fruit { public String toString() {return "Grape";} }
class Toy { public String toString() {return "Toy";} }

class Box<T> {
  ArrayList<T> list = new ArrayList<>();
  void add(T item) { list.add(item); }
  T get(int i) { return list.get(i); }
  int size() { return list.size(); }
  public String toString() { return list.toString(); }
}

public class FruitBoxEx {
  public static void main(String[] args) {
    Box<Fruit> fruitBox = new Box<Fruit>();
    Box<Apple> appleBox = new Box<Apple>();
    Box<Toy> toyBox = new Box<Toy>();
    // Box<Grape> grapeBox = new Box<Apple>(); // 타입 불일치, 에러
  
    fruitBox.add(new Fruit());
    fruitBox.add(new Apple()); // Fruit와 Apple이 상속관계에 있기 때문에 가능하다.

    appleBox.add(new Apple());
    appleBox.add(new Apple());
    // appleBox.add(new Toy()); // 에러

    toyBox.add(new Toy());
    // toyBox.add(new Apple()); // 에러

    System.out.println(fruitBox);
    System.out.println(appleBox);
    System.out.println(toyBox);
  }
}
