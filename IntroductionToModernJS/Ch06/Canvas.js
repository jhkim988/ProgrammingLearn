// Canvas: 웹브라우저에서 그래픽을 처리하기 위해 추가된 HTML5 구성요소
// 즉시 실행형 저수준 API다.
// 저수준: 선, 원, 사각형 등 기본적인 그리기 기능마 제공하여 속도가 빠르다.
// 즉시 실행형: 그리기 명령은 호출하는 즉시 실행된다. 그림 상태를 저장하는 중간 데이터 계층이 없다.
// 6-5.html

// 사각형 그리기
// 6-5-1.html

// 패스로 그리기
// 6-5-2.html ~ 6-5-7.html

// graphics 속성 설정
// 6-6-1.html

// 그림 읽어 들이기
// 6-7.html

// 픽셀 제어
// getImageData(x, y, width, height);
// 이미지 내부에서 (x, y, width, height) 영역의 imageData 객체를 가져온다.
// imageData 의 프로퍼티: width, height, data(픽셀값이 저장돼 있는 1차원 배열(unsigned 8bit int[]))
// data는 RGBA값이 하나씩 들어있다. 따라서 width * height * 4 크기의 배열이다.
// getImageData() 역시 크로스 도메인 이슈에 따른 정보 유출을 방지하기 위해 origin-clean한 canvas 요소에서만 작동한다.
// 6-8.html