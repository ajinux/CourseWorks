/**
 * 
 */
package me.ajithkumarsekar.creational.singleton;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 * @author ajithkumar sekar
 * reference : https://www.geeksforgeeks.org/singleton-design-pattern/
 */
public class JDBCDBHandler {

	private static JDBCDBHandler DBHandler;
	private Connection con = null;

	private JDBCDBHandler() {
		try {
			// initializing DB Connection
			Class.forName("com.mysql.jdbc.Driver");
			con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ashwanirajput", "root", "ashwani");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public static JDBCDBHandler getInstance() {
		if (DBHandler == null) {
			// to make thread safe
			synchronized (JDBCDBHandler.class) {
				// check again as multiple threads
				// can reach above step
				if (DBHandler == null) {
					DBHandler = new JDBCDBHandler();
				}
			}
		}
		return DBHandler;

	}
	
	private Connection getConnection(){
		return con;
	}
	
	public static void main(String[] args){
		final JDBCDBHandler dbHandler = JDBCDBHandler.getInstance();
		final Connection con = dbHandler.getConnection();
		// do all the queries
	}
	
}



