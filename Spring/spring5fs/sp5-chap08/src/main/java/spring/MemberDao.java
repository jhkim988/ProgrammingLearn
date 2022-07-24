package spring;

import java.util.*;
import java.sql.*;

import javax.sql.*;
import org.springframework.jdbc.core.*;

class MemberRowMapper implements RowMapper<Member>{
	@Override
	public Member mapRow(ResultSet rs, int rowNum) throws SQLException {
		Member member = new Member(
				rs.getString("EMAIL"),
				rs.getString("PASSWORD"),
				rs.getString("NAME"),
				rs.getTimestamp("REGDATE").toLocalDateTime());
		member.setId(rs.getLong("ID"));
		return member;
	}
	// Use Lambda
//	List<Member> results = jdbcTemplate.query(
//			"select * from MEMBER where EMAIL = ?",
//			(ResultSet rs, int rowNum) -> {
//				Member member = new Member(
//					rs.getString("EMAIL"),
//					rs.getString("PASSWORD"),
//					rs.getString("NAME"),
//					rs.getTimestamp("REGDATE").toLocalDateTime());
//				member.setId(rs.getLong("ID"));
//				return member;
//			}, email);
}

public class MemberDao {
	private JdbcTemplate jdbcTemplate;
	
	public MemberDao(DataSource dataSource) {
		this.jdbcTemplate = new JdbcTemplate(dataSource);
	}
	
	public Member selectByEmail(String email) {
		List<Member> results = jdbcTemplate.query("select * from MEMBER where EMAIL = ?",	new MemberRowMapper(), email);
		return results.isEmpty() ? null : results.get(0);
	}
	public void insert(Member member) {
		
	}
	public void update(Member member) {
		jdbcTemplate.update("update Member set NAME = ?, PASSWORD = ? WHERE EMAIL = ?",
				member.getName(), member.getPassword(), member.getEmail());

		// 직접 파라미터값을 변경하고 싶다면
//		jdbcTemplate.update(new PreparedStatementCreator() {
//			@Override
//			public PreparedStatement createPreparedStatement(Connection con) throws SQLException {
//				PreparedStatement pstmt = con.prepareStatement("insert info MEMBER (EMAIL, PASSWORD, NAME, REGDATE) value(?, ?, ?, ?)");
//				pstmt.setString(1, member.getEmail());
//				pstmt.setString(2, member.getPassword());
//				pstmt.setString(3, member.getName());
//				pstmt.setString(4, Timestamp.valueOf(member.getRegisterDateTime()));
//				return pstmt;
//			}
//		});
	}
	public Collection<Member> selectAll() {
		return jdbcTemplate.query("select * from MEMBER", new MemberRowMapper());
	}
	public int count() {
		// queryForObject 는 결과가 1행인 경우에 사용할 수 있다. 0개나 2개 이상이면 Exception 발생한다.
		int count = jdbcTemplate.queryForObject("select count(*) from MEMBER", Integer.class);
		return count;
	}
}
