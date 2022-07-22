package config;

import org.springframework.context.annotation.*;
import spring.*;

@Configuration
public class AppCtx {
	@Bean
	public Client client() {
		Client client = new Client();
		client.setHost("host");
		return client;
	}
	
	// InitializingBean, DesposableBean을 구현하지 않고 초기화/소멸 과정에서 실행하도록 메서드 지정
	@Bean(initMethod = "connect", destroyMethod = "close") // 두 메서드에는 파라미터가 없어야 한다.
	public Client2 client2() {
		Client2 client = new Client2();
		client.setHost("host");
		return client;
	}
}
