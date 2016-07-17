import java.util.Scanner;
class Date
{
	int day,month,year;
	Date(int day,int month,int year)
	{
		this.day=day;
		this.month=month;
		this.year=year;
	}
	public boolean CheckValid()
	{
		boolean leap_year;
		if(year%4==0)
			leap_year=true;
		else
			leap_year=false;
		if(day<=31 && month<=12 && year>=0)
		{
			if(month==2 && leap_year)
			{
				if(day<=29)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(month==2 && !leap_year)
			{
				if(day<=28)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(month%2==0)
			{
				if(day<=30)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if(day<=31)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
			return false;
	}
	public static void main(String[] args)
	{
		Scanner read=new Scanner(System.in);
		System.out.println("Enter the day:");
		int day=read.nextInt();
		System.out.println("Enter the month:");
		int month=read.nextInt();
		System.out.println("Enter the year:");
		int year=read.nextInt();
		Date inst1=new Date(day,month,year);
		if(inst1.CheckValid())
			System.out.println("Valid date");
		else
			System.out.println("Invalid date");
		
	}
}