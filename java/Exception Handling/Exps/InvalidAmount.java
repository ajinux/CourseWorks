package Exps;

public class InvalidAmount extends Exception
{
	String s1;
	public InvalidAmount(String err)
	{
		s1=err;
	}
	public InvalidAmount()
	{
		s1="";
	}
	public String toString()
	{
		return "ERROR:Aoumt should be no negative and minimum balance should be 500rs"+s1;
	}
}