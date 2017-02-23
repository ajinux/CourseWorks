import java.util.Scanner;

import java.sql.*;

public class Books
{
 public static void main(String args[])
 {
	 System.out.println("\nEnter 1 - to create the database\n2 - search author\n3 - order information");
	 Scanner input=new Scanner(System.in);
	 int s=input.nextInt();
	 switch(s) 
	 {
     case 1 :
        System.out.println("\nCreating the books database");
        //createdb();
        break;
     case 2:
    	 searchauthor();
    	 break;
     case 3:
    	 orderinformation();
    	 break;
     default :
        System.out.println("Invalid INPUT");
  }
}

private static void orderinformation() 
{	
	try
	{  
		Class.forName("com.mysql.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:8080/books","root","myroot");  
		Statement stmt=con.createStatement();  
		String sql="SELECT FirstName,Title,Edition,Copyright FROM author INNER JOIN authorisbn ON author.ID = authorisbn.ID INNER JOIN title ON authorisbn.isbn = title.isbn order by Firstname";
		
		ResultSet rs=stmt.executeQuery(sql);  
		while(rs.next())  
	    System.out.println(rs.getString(1)+"  "+rs.getString(2)+"  "+rs.getString(3)+"  "+rs.getString(4));  
	    con.close();  
	}
	catch(Exception e)
	{ 
		System.out.println(e);
	}  
	
}

private static void searchauthor() 
{
	 Scanner input=new Scanner(System.in);
	
	try
	{  
		Class.forName("com.mysql.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:8080/books","root","myroot");  
		Statement stmt=con.createStatement(); 
		System.out.println("Enter the name of the author:");
		String authorname=input.nextLine();
		String sql="SELECT FirstName,Title,Edition,Copyright FROM author INNER JOIN authorisbn ON author.ID = authorisbn.ID INNER JOIN title ON authorisbn.isbn = title.isbn where FirstName='"+authorname+"'";
		//System.out.println(sql);-
		ResultSet rs=stmt.executeQuery(sql);  
		while(rs.next())  
	    System.out.println(rs.getString(1)+"  "+rs.getString(2)+"  "+rs.getString(3)+"  "+rs.getString(4));  
	    con.close();  
	}
	catch(Exception e)
	{ 
		System.out.println(e);
	}  
}

private static void createdb() 
{
	System.out.println("Creating the database..");
	try
	{  
		Class.forName("com.mysql.jdbc.Driver");  
		Connection con=DriverManager.getConnection("jdbc:mysql://localhost:8080/books","root","myroot");  
		Statement stmt=con.createStatement();  
		int rs=stmt.executeUpdate("create table author ( ID int NOT NULL AUTO_INCREMENT,Firstname varchar(255) NOT NULL,Lastname varchar(255),PRIMARY KEY(ID));");  
		stmt.executeUpdate(" create table Title (ISBN  int NOT NULL,Title varchar(255),Edition varchar(255),Copyright varchar(255),PRIMARY KEY (ISBN));");  
		stmt.executeUpdate("create table Authorisbn (ID int,ISBN int, FOREIGN KEY (ID) REFERENCES author(ID),FOREIGN KEY(ISBN) REFERENCES title(ISBN));");
		con.close();  
		System.out.println("Database successfully created");
	}
	catch(Exception e)
	{ 
		System.out.println(e);
	}  
	
}
	 
}
