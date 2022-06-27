package config;

import org.springframework.context.annotation.*;

import spring.*;

@Configuration
@Import(AppConf2.class) // AppConf2 설정 클래스도 함께 사용한다.
//@Import({AppConf1.class, AppConf2.class}) // 여러 개 Import 할 땐
public class AppConfImport {
	@Bean
	public MemberDao memberDao() {
		return new MemberDao();
	}
	@Bean
	public MemberPrinter memberPrinter() {
		return new MemberPrinter();
	}
}
