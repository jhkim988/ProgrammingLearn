#include "MyLibrary.h"

#include <stdio.h>

// 라이브러리
// main()함수가 없다. -> 라이브러리는 다른 프로그래머가 작성한 프로그램에 들어가 도와주는 것..
// properties -> configuration properties -> general -> Configuration Type -> Application(.exe)를 Library로 바꾼다.
// 정적 라이브러리(.lib), 동적 라이브러리(.dll)
// .lib 파일이 생성된다. (debug/release 폴더에) 해당 파일을 이용해서 다른 프로젝트에서 사용할 수 있다. (debug 모드, release 모드 둘 다 설정)
// lib파일을 사용할 때 release모드에서 사용 - release 모드에서 생성된 lib파일을 사용.. (debug모드도 마찬가지)
// 사용할 곳에서 헤더파일 #include -> 링킹 에러가 발생한다.(lib파일을 안 넣어줬기 때문)
// properties -> linker -> input -> additional dependencies -> .lib 파일 연결

void say_hello()
{
	printf("Hello\n");
}

void say_world()
{
	printf("World\n");
}