package config;

import org.springframework.beans.factory.annotation.*;
import org.springframework.context.annotation.*;

import spring.*;

@Configuration // spring 설정 클래스
public class AppCtx {
	@Bean
	public MemberDao memberDao() {
		return new MemberDao();
	}
	@Bean
	public MemberRegisterService memberRegSvc() {
		return new MemberRegisterService();
	}
	@Bean
	public ChangePasswordService changePwdSvc() {
		return new ChangePasswordService();
	}
	@Bean
	@Qualifier("printer")
	// 같은 타입을 리턴하는 Bean이 2개 이상일 때 자동주입 대상 빈을 한정한다.
	// 자동주입을 사용하는 @Autowired 쪽에도 @Qualifier를 붙여준다.
	// @Qualifier 애노테이션이 없으면 빈의 이름을 한정자로 지정한다.
	// @Autowired 도 @Qualifier가 없으면 필드나 파라미터 이름을 한정자로 사용한다.
	// 상속관계에 있는 타입읠 리턴하는 Bean이 2개 이상일 때도 자동주입을 한정하지 않으면 익셉션이 발생한다.
	public MemberPrinter memberPrinter1() {
		return new MemberPrinter();
	}
	@Bean
	@Qualifier("summaryPrinter")
	public MemberSummaryPrinter memberPrinter2() {
		return new MemberSummaryPrinter();
	}
	@Bean
	public MemberListPrinter listPrinter() {
		return new MemberListPrinter();
	}
	@Bean
	public MemberInfoPrinter infoPrinter() {
		return new MemberInfoPrinter();
	}
	@Bean
	public VersionPrinter versionPrinter() {
		VersionPrinter versionPrinter = new VersionPrinter();
		versionPrinter.setMajorVersion(5);
		versionPrinter.setMinorVersion(0);
		return versionPrinter;
	}
}
