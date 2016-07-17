public class Arithmetic
{
	public void add(int a,int b)
	{
	  System.out.println(a+b);	
	}
    public void add(int a,int b,int c,int d)
    {
    	System.out.println(a+c+"+"+(b+d)+"i");
    }
    
    public void subtract(int a,int b)
	{
	  System.out.println(a-b);	
	}
    public void subtract(int a,int b,int c,int d)
    {
    	System.out.println(a-c+"+"+(b-d)+"i");
    }
    
    public void multiply(int a,int b)
	{
	  System.out.println(a*b);	
	}
    public void multiply(int a,int b,int c,int d)
    {
    	System.out.println((a*c-b*d)+" "+(a*d+b*c)+"i");
    }
    public static void main(String args[])
    {
    	Arithmetic inst1=new Arithmetic();
    	inst1.multiply(3,4,6,2);
    }
}