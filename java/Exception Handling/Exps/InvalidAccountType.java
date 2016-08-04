package Exps;

public class InvalidAccountType extends Exception
{
	String s1;
	public InvalidAccountType(String err)
	{
		s1=err;
	}
	public InvalidAccountType()
	{
		s1="";
	}
	public String toString()
	{
		return "ERROR:Account type should be current or Savings"+s1;
	}
}