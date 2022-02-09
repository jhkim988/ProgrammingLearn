// 웹 브라우저에서 동작하는 프로그램은 기본적으로 이벤트 주도형 프로그램
// 이벤트: 단말기와 애플리케이션이 처리할 수 있는 동작/사건
// Event Driven Program
// 이벤트 주도형 프로그램: 이벤트가 발생할 때까지 기다렸다가, 발생했을 때 미리 등록해 둔 작업을 수행하는 프로그램
// 이벤트 처리기: 이벤트가 발생됐을 때 실행되는 함수

// 함수를 이벤트 처리기로 등록한는 방법
// 1. HTML 요소의 속성으로 등록하는 방법
// 2. DOM 요소의 프로퍼티로 등록하는 방법
// 3. addEventListener 메서드를 사용하는 방법

// HTML 요소 속성에 이벤트 처리기 등록
// 6-1.html

// DOM에서 가져온 HTML 요소에 이벤트 처리기 지정하기
// DOM: Document Object Model: JS 등의 프로그램이 HTML 요소를 조작할 수 있게 하는 인터페이스
// DOM의 주요 객체: window(웹 브라우저 윈도우 하나 / 탭), document(HTML 문서 전체)
// 6-2 htmls

// 웹 브라우저의 Window 객체에는 setTimeout과 setTimeInterval 메서드가 있다.
// 지정된 시간이 흐른 후 함수를 실행하거나, 일정한 시간 간격에 따라 함수를 반복실행할 수 있다.
var timer = setTimeout(function() {
  console.log(new Date());
}, 2000); // 2초 후 함수 실행

clearTimeout(timer); // 함수실행 취소

var timer = setInterval(function() {
  console.log(new Date());
}, 1000);
clearInterval(timer);