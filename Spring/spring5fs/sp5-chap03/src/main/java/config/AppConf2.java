package config;

import org.springframework.beans.factory.annotation.*;
import org.springframework.context.annotation.*;

import spring.*;

@Configuration
public class AppConf2 {
	// @Autowired를 사용하면 Bean 메서드에서 setter로 의존주입을 하지 않아도 자동으로 된다.
	// Spring 내부에서 @Configuration 클래스를 빈으로 등록하고 @Autowired가 붙은 대상에 알맞은 빈을 자동으로 등록한다. 
	@Autowired
	private MemberDao memberDao;
	@Autowired
	private MemberPrinter memberPrinter;
	@Bean
	public MemberRegisterService memberRegSvc() {
		return new MemberRegisterService(memberDao)
;	}
	@Bean
	public ChangePasswordService changePwdSvc() {
		ChangePasswordService pwdSvc = new ChangePasswordService();
		pwdSvc.setMemberDao(memberDao);
		return pwdSvc;
	}
	@Bean
	public MemberListPrinter listPrinter() {
		return new MemberListPrinter(memberDao, memberPrinter);
	}
	@Bean
	public MemberInfoPrinter infoPrinter() {
		MemberInfoPrinter infoPrinter = new MemberInfoPrinter();
		infoPrinter.setMemberDao(memberDao);
		infoPrinter.setPrinter(memberPrinter);
		return infoPrinter;
	}
	@Bean
	public VersionPrinter versionPrinter() {
		VersionPrinter versionPrinter = new VersionPrinter();
		versionPrinter.setMajorVersion(5);
		versionPrinter.setMinorVersion(0);
		return versionPrinter;
	}
}
