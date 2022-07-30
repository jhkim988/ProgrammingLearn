package config;

import org.apache.tomcat.jdbc.pool.DataSource;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Profile;

@Configuration
@Profile("dev") // @Profile("real", "many", "!notMe")
public class DsDevConfig {
	@Bean(destroyMethod="close")
	public DataSource dataSource() {
		DataSource ds = new DataSource();
		ds.setDriverClassName("com.mysql.jdbc.Driver");
		ds.setUrl("jdbc:mysql://localhost/spring5fs?characterEncoding=utf8");
		ds.setUsername("spring5");
		ds.setPassword("spring5");
		ds.setInitialSize(2);
		ds.setMaxActive(10);
		ds.setTestWhileIdle(true);
		ds.setMinEvictableIdleTimeMillis(60000*3);
		ds.setTimeBetweenEvictionRunsMillis(10*1000);
		return ds;
	}
}

// 설정 적용 방법
// (1) 컨테이너 설정
// AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(); // 컨테이너 생성
// context.getEnvirnment().setActivePrifiles("dev"); // 프로필 설정
// context.register(MemberConfig.class, DsDevConfig.class, DsReadlConfig.class); // 설정 파일 목록 전달
// context.refresh(); // 컨테이너 초기화

// (2) 시스템 프로퍼티
// java -Dspring.profiles.active=dev main.Main
// spring.profiles.active 라는 프로퍼티에 "dev"가 설정된 채로 실행된다.
// OS 환경변수에 spring.profiles.active의 값을 설정해도 된다.

// (3) 웹 앱의 경우
// web.xml에서 아래와 같이 추가한다.

//<init-param>
//<param-name>spring.profiles.active</param.name>
//<param-value>dev</param-value>
//</init-param>