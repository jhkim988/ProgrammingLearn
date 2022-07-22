package config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;

import spring.Client;

@Configuration
public class AppCtxWithPrototype {
	@Bean
	@Scope("prototype") // 명시적으로 @Scope("singleton")을 줄 수 있다.
	public Client client() {
		Client client = new Client();
		client.setHost("host");
		return client;
	}
	// prototype 범위를 갖는 빈은 완전한 라이프사이클을 따르지 않는다.
	// 빈 객체를 생성하고, 프로퍼티 설정, 초기화 작업까지는 수행하지만 소멸 메서드는 실행하지 않는다.
	// 소멸처리를 직접 해야한다.
}
