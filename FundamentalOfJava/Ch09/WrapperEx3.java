public class WrapperEx3 {
  public static void main(String[] args) {
    int i = 10;

    Integer intg = (Integer) i; // Integer.valueOf(i);
    Object obj = (Object) i; // (Object) Integer.valueof(i);

    Long lng = 100L;

    int i2 = intg + 10; // Wrapper + primitive
    long l = intg + lng; // Wrapper + Wrapper

    Integer intg2 = new Integer(20);
    int i3 = (int) intg2;
    Integer intg3 = (int) intg2 + i3;
  }
}
