import java.util.Scanner;
public class Armstrong
{
	int num;
	public Armstrong(int num)
	{
		this.num=num;
	}
	public boolean CheckNum()
	{
		int digits,n,sum;
		n=num;
		digits=0;
		sum=0;

		while(n>0)
		{
			n=n/10;
			digits++;
		}
		
		n=num;
		while(n>0)
		{
			double temp=n%10;
			sum=sum+(int)(Math.pow(temp, digits));
			n=n/10;
		}
        return sum==num;
		
	}
	public static void main(String[] args)
	{
		Scanner user_input = new Scanner( System.in );
		System.out.println("Enter a number:");
		int num=user_input.nextInt();
		Armstrong n1=new Armstrong(num);
		if(n1.CheckNum())
		{
			System.out.println("It is an armstrong number");
		}
		else
		{
			System.out.println("It is not an armstrong number");
		}
	}
}