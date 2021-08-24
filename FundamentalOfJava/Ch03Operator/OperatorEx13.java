public class OperatorEx13 {
  public static void main(String[] args) {
    char c1 = 'a';
    // char c2 = c1 + 1; // 컴파일 에러, c1 + 1이 int로 변환된다.
    char c2 = 'a' + 1; // 에러가 발생하지 않는다.
    // 리터럴 간의 연산은 실행과정 동안 변하는 값이 아니기 때문에,
    // 컴파일 시 컴파일러가 계산해서 그 결과로 대체한다.
    // 리터럴 간의 연산이 아니라, 변수 간의 연산이라면 실행 도중 값이 바뀔 수 있기 때문에
    // 컴파일러가 미리 계산을 할 수 없다. 따라서 형변환을 해줘야 한다.
    // 리터럴의 연산을 풀어서 작성해도 컴파일러가 미리 계산하기 때문에 실행 시 성능 차이는 없다.
    System.out.println(c2); // b
  }  
}
