package dbquery;

import java.sql.*;
import javax.sql.DataSource;

public class DbQuery {
	private DataSource dataSource;
	public DbQuery(DataSource dataSource) {
		this.dataSource = dataSource;
	}
	public int count() {
		Connection conn = null;
		try {
			conn = dataSource.getConnection(); // Data pool에서 구한다.
			try (Statement stmt = conn.createStatement();
				ResultSet rs = stmt.executeQuery("select count(*) from MEMBER")) {
				rs.next();
				return rs.getInt(1);
			}
		} catch (SQLException e) {
			throw new RuntimeException(e);
			
		} finally {
			if (conn != null)
				try {
					conn.close(); // pool에 반환
				} catch (SQLException e) {
			
			}
		}
	}
}
