package config;

import org.springframework.beans.factory.annotation.*;
import org.springframework.context.annotation.*;

import spring.*;

@Configuration
@ComponentScan(basePackages = {"spring"})
public class AppCtx {
	@Bean
	@Qualifier("printer")
	public MemberPrinter memberPrinter1() {
		return new MemberPrinter();
	}
	@Bean
	@Qualifier("summaryPrinter")
	public MemberSummaryPrinter memberPrinter2() {
		return new MemberSummaryPrinter();
	}
	@Bean
	public VersionPrinter versionPrinter() {
		VersionPrinter versionPrinter = new VersionPrinter();
		versionPrinter.setMajorVersion(5);
		versionPrinter.setMinorVersion(0);
		return versionPrinter;
	}
}


// 컴포넌트 스캔 주의
// 1. 빈 이름 충돌
// basePackages에 여러 패키지를 할당하고, 각각의 패키지에 같은 이름의 빈이 있으면 충돌이 일어난다.
// 2. 수동 등록 충돌
// 자동등록된 빈의 이름은 클래스 앞글자를 소문자로 바꾼 이름, 수동등록 빈과 이름이 중복되면 수동등록 빈이 우선순위를 갖는다.
