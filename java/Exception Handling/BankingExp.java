/*
 * Write a Java program to handle exceptions for a banking system. 
 * Get the details like account no, name of customer, account type, amount. 
 * If the balance goes below a threshold limit, raise a WithdrawalNotPossible exception.
 * [Hint: account no should have 10 digits, name should have only alphabets, account type should be savings or current, amount to be non-negative. 
 * If any discrepancy occurs, raise and InvalidCredentials exception]
 */

import java.util.*;
import java.util.regex.*;
import Exps.*;

class Banking
{
	String AccountNumber,AccountName,AccountType,Amount;
	Banking(String Anum,String Anam,String Atyp,String Amnt)
	{     
		AccountNumber=Anum;
		AccountName  =Anam;
		AccountType  =Atyp;
		Amount       =Amnt;
	}
	void AccountDetails()
	{
		System.out.println("\nAccountName :"+AccountName+"\nAccountNumber :"+AccountNumber+"\nAccountType :"+AccountType+"\nAmount :"+Amount+"\n");
	}
}

class BankingExp
{
	public static void main(String[] args)
	{
	  String AccountNumber,AccountName,AccountType,Amount;
	  Scanner input=new Scanner(System.in);
	  try
	  { 
          //-----------------------------------------
		  System.out.println("\nEnter the Name:");
		  AccountName=input.nextLine();
		  for(int i=0;i<AccountName.length();i++)
		  {
			  char ch=AccountName.charAt(i);
			  if(!Character.isLetter(ch) && ch!=' ')
		          throw new InvalidName("");
			 			  
		  }
		  
		  //-----------------------------------------
		  System.out.println("\nEnter the Account Number :");
		  AccountNumber=input.nextLine();
		  
		  if(AccountNumber.length()!=10 || Pattern.matches("[0-9]+", AccountNumber) == false)
			  throw new InvalidAccountNumber("");
		  
		  //-----------------------------------------
		  System.out.println("\nEnter the Account type:");
		  AccountType=input.nextLine();
		  if(!(AccountType.equalsIgnoreCase("savings") || AccountType.equalsIgnoreCase("current")))
		     throw new InvalidAccountType("");
		  
		  //-----------------------------------------
		  System.out.println("\nEnter the Deposited Amount:");
		  Amount=input.nextLine();
		  int amt=Integer.parseInt(Amount);
		  if(amt<500)
			  throw new InvalidAmount("");
		  
		  //-----------------------------------------
		  Banking b1=new Banking(AccountNumber,AccountName,AccountType,Amount);
		  System.out.println("Hi "+AccountName+", Your account has beek created successfully!");
		  
	  }
	  catch(InvalidAmount e)
	  {
		  System.out.println(e);
	  }
	  catch(InvalidAccountType e)
	  {
		  System.out.println(e);
	  }
	  catch(InvalidAccountNumber e)
	  {
		  System.out.println(e);
	  }
	  catch(InvalidName e)
	  {
		  System.out.println(e);
	  }
	  catch(Exception e)
	  {
		  System.out.println("Invalid input");
	  }
	  finally
	  {
		  System.out.println("Thanking for using our service");
	  }
	}
	


}


















