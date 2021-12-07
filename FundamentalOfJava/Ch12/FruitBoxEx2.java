import java.util.*;

class Fruit implements Eatable { public String toString() { return "Fruit"; } }
class Apple extends Fruit { public String toString() { return "Apple"; } }
class Grape extends Fruit { public String toString() { return "Grape"; } }
class Toy { public String toString() { return "Toy"; } }
interface Eatable { }

class FruitBox<T extends Fruit & Eatable> extends Box<T> { }
// Fruit 클래스를 상속받고, Eatable 인터페이스를 구현한 클래스만 타입변수로 사용할 수 있다.
// 인터페이스만 요구할 때도 extends를 사용한다.(implements를 사용하지 않는다.)
// 여러 클래스와 인터페이스를 동시에 요구할 때는 &를 사용한다.

class Box<T> {
  ArrayList<T> list = new ArrayList<>();
  void add(T item) { list.add(item); }
  T get(int i) { return list.get(i); }
  int size() { return list.size(); }
  public String toString() { return list.toString(); }
}

public class FruitBoxEx2 {
  public static void main(String[] args) {
    FruitBox<Fruit> fruitBox = new FruitBox<>();
    FruitBox<Apple> appleBox = new FruitBox<>();
    FruitBox<Grape> grapeBox = new FruitBox<>();
    // FruitBox<Grape> grapxBox = new FruitBox<Apple>(); // 타입 불일치
    // FruitBox<Toy> toyBox = new FruitBox<>(); // Toy는 Fruit를 상속받지 않는다.

    fruitBox.add(new Fruit());
    fruitBox.add(new Apple());
    fruitBox.add(new Grape());
    appleBox.add(new Apple());
    // appleBox.add(new Grape()); // Grape는 Apple의 자손이 아님
    grapeBox.add(new Grape());

    System.out.println("fruitBox-" + fruitBox);
    System.out.println("appleBox-" + appleBox);
    System.out.println("grapeBox-" + grapeBox);
  }  
}
