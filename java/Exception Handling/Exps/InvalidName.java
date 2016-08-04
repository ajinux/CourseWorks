package Exps;

public class InvalidName extends Exception
{
	String s1;
	public InvalidName(String err)
	{
		s1=err;
	}
	public InvalidName()
	{
		s1="";
	}
	public String tostring()
	{
		return "ERROR:Account name should be only in alphabets"+s1;
	}
}