// 대화상자 표시
// 자주 사용되진 않지만, 입출력이 간단

// 웹 브라우저 전역객체: Window
// window.alert: 경고 대화상자 표시
// window.prompt: 사용자의 문자열 입력을 받는 대화상자 표시
// window.confirm: 확인/취소 버튼이 있는 대화상자를 표시

// 대화상자는 모달(modal)창이다. 대화상자가 떠있는 동안에 부모 창의 작업이 일시적으로 정지상태가 되어 조작할 수 없다.
// 대화상자에는 일반 텍스트만 표시할 수 있고, 줄 바꿈 문자 등은 이스케이프 시퀀스를 사용한다.
// window 객체의 메서드는 window. 을 생략하여 호출할 수 있다.

alert("안녕하세요!");

var name = prompt("이름을 입력하세요"); // 사용자로부터 입력받은 문자열이 반환된다. (name 변수에 저장된다.)
var name = prompt("이름을 입력하세요", "이현규"); // 두 번째 인자로 default 값을 지정할 수 있다.
// 문자열을 반환하기 때문에, 숫자 값을 구하려면 parseInt, parseFloat을 이용한다.

var ret = confirm("링크를 표시하시겠습니까?"); // 사용자의 응답에 따라 boolean 값을 반환한다.


// Console 객체
// 웹브라우저, Nodejs를 포함한 다양한 JS 런타임에서 사용할 수 있다.
// 부모 창의 동작을 간섭하지 않기 때문에 프로그램의 동작을 확인하거나 디버깅하는 데 자주 사용된다.

// console.dir(): 객체의 대화형 목록을 출력
// console.error(): 오류메세지를 출력
// console.info(): 메세지 타입 로그를 출력
// console.log(): 일반 로그를 출력
// console.time(): 처리 시간 측정용 타이머를 시작
// console.timeEnd(): 처리 시간 측정용 타이머를 정리시키고, 흐른 시간을 밀리초 단위로 출력
// console.trace(): 스택 트레이스를 출력
// console.warn(): 경고 메세지 출력

// log, info, warn, error: 로그 스타일이 다를 뿐이다.
// Console 객체의 메서드는 인수 여러 개를 쉼표로 구분해서 넘길 수 있다.
// 각각의 값을 쉼표로 구분하여 출력한다.
// 문자열 formatting을 이용할 수도 있다.
var a = [2, 4, 6];
console.log("배열", a, "의 길이는", a.length, "입니다.");
console.log("배열" + a + "의 길이는" + a.length + "입니다.");
console.log("배열 [2, 4, 6]의 길이는 %d 입니다.", a.length);
// %o: 객체를 가리키는 하이퍼링크로 변환(Nodejs 미지원)
// %d: 정숫값으로 변환(Nodejs는 숫자로 변환)
// %i: 정숫값으로 변환(Nodejs 미지원)
// %s: 문자열 변환
// %f: 부동소수점 값으로 변환(Nodejs 미지원)

var p = {x: 1, y: 2};
console.dir(p);

console.time("answer_time");
alert("확인 버튼을 누르십시오.");
console.timeEnd("answer_time");

// document.write()
// 인수로 받은 문자열을 HTML 문서의 body 요소 안에 출력한다.
// document.write("<p>안녕 세상아</p>");