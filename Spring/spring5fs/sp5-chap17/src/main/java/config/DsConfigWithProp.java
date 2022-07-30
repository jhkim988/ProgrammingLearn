package config;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Configuration;

@Configuration
public class DsConfigWithProp {
	@Value("${db.driver}") // db.properties 파일의 driver 값을 읽어와 할당한다. Bean으로 사용할 클래스에도 @Value 사용 가능하다.
	private String driver;
}
