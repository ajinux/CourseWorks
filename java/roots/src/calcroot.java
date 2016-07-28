
/*Question :
 * Create an interface roots with the method calculate.
 *  Write a Java program to create classes to calculate the roots 
 *  of a quadratic equation in all cases.
 */

import Interfaceroot.RootInterface;
import java.util.Scanner;
import java.util.InputMismatchException;

class calcroot implements RootInterface 
{
   	public String quadraticroots(double a, double b, double c) 
	{  
		double d= b*b-4*a*c;
		if(d>0)
			return "The roots are real and unequal";
		else if(d==0)
			return "The roots are real and equal";
		else
			return "There are no real roots";
	
	}
	public static void main(String args[])
	{
		Scanner user_input=new Scanner(System.in);
		double a=0,b=0,c=0;
		calcroot r1=new calcroot();
	    System.out.println("Enter a, b and c");
	    try
	    {
	     a=user_input.nextDouble();
	     b=user_input.nextDouble();
	     c=user_input.nextDouble();
		 System.out.println(r1.quadraticroots(a, b, c));
	    }
	    catch(InputMismatchException e)
	    {
	      System.out.println("Inavlid input --program terminated");
	    }
	    
	}
   
}
