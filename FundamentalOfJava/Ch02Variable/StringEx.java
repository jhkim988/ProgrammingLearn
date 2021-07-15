public class StringEx {
    public static void main(String[] args) {
        // 자료형 - 기본형, 참조형
        // 기본형 변수는 실제 값을 저장
        // 참조형 변수는 어떤 값이 저장되어 있는 주소를 값으로 갖는다.
        // C언어와 덜리 참조형 변수 간의 연산을 할 수 없다.
    
        // 기본형
        // boolean, char, byte, short, int, long, float, double
        // 참조형
        // 기본형 8개를 제외한 나머지
        
        // 참조변수는 null 또는 객체의 주소를 값으로 갖는다.
        // 참조변수의 초기화
        // Date today = new Date(); // 객체를 생성하는 연산자 new의 결과는 객체의 주소이다.
        // JVM이 32bit가 아니라 64bit라면 참조형 변수의 크기는 8byte가 된다.

        // char는 내부적으로 정수로 저장하기 때문에 정수형과 다르지 않으며, 정수형 실수형과 연산도 가능하다.
        // boolean을 제외한 나머지 7개의 기본형은 서로 연산과 변환이 가능하다.
        // int는 CPU가 가장 효율적으로 처리할 수 있는 타입이다.

        // boolean: 1byte
        // char : 2byte
        // byte: 1byte
        // short: 2byte
        // int: 4byte
        // long: 4byte
        // float: 4byte
        // double: 4byte
    }
}
