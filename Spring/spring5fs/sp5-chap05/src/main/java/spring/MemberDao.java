package spring;

import java.util.*;
import org.springframework.stereotype.*;

@Component // 이름을 설정하지 않으면, 클래스이름 첫 글자를 소문자로 바꾼 이름을 빈 이름으로 설정한다.
public class MemberDao {
	private static long nextId = 0;
	private Map<String, Member> map = new HashMap<>();
	public Member selectByEmail(String email) {
		return map.get(email);
	}
	public void insert(Member member) {
		member.setId(++nextId);
		map.put(member.getEmail(), member);
	}
	public void update(Member member) {
		map.put(member.getEmail(), member);
	}
	public Collection<Member> selectAll() {
		return map.values();
	}
}
