package Exps;

public class InvalidAccountNumber extends Exception
{
	String s1;
	public InvalidAccountNumber(String err)
	{
		s1=err;
	}
	public InvalidAccountNumber()
	{
		s1="";
	}
	public String toString()
	{
		return "ERROR:Account number should be 10 digits"+s1;
	}
}