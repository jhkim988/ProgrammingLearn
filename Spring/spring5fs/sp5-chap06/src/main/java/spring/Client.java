package spring;

import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

public class Client implements InitializingBean, DisposableBean {
	private String host;
	
	public void setHost(String host) {
		this.host = host;
	}
	
	// 컨테이너가 생성되고 초기화 과정에서 실행된다.
	@Override
	public void afterPropertiesSet() throws Exception {
		System.out.println("Client.afterPropertiesSet() 실행");
	}
	
	public void send() {
		System.out.println("Client.send() to " + host);
	}
	
	// 컨테이너가 소멸되는 과정에서 실행된다.
	@Override
	public void destroy() throws Exception {
		System.out.println("Client.destroy() 실행");
	}
	
}
