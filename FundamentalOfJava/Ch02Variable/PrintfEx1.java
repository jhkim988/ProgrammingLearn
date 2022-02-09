public class PrintfEx1 {
  public static void main(String[] args) {
    byte b = 1;
    short s = 2;
    char c = 'A';

    int finger = 10;
    long big = 100_000_000_000L;
    long hex = 0xFFFF_FFFF_FFFF_FFFFL;

    int octNum = 010;
    int hexNum = 0x10;
    int binNum = 0b10;

    System.out.printf("b=%d%n", b);
    System.out.printf("s=%d%n", s);
    System.out.printf("c=%c, %d %n", c, (int) c); // c 언어에서는 char 타입을 %d로 출력할 수 있지만, 자바에서는 형변환을 해줘야한다.
    System.out.printf("finger=[%5d]%n", finger);
    System.out.printf("finger=[%-5d]%n", finger);
    System.out.printf("finger=[%05d]%n", finger);
    System.out.printf("big=%d%n", big);
    System.out.printf("hex=%#x%n", hex); // #은 접두사 출력(0x, 0)
    System.out.printf("ocnNum=%o, %d%n", octNum, octNum);
    System.out.printf("hexNum=%x, %d%n", hexNum, hexNum);
    System.out.printf("binNum=%s, %d%n", Integer.toBinaryString(binNum), binNum);
    System.out.printf("boolean %b", true);
  }
}
