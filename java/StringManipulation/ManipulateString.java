
import java.util.*;

public class ManipulateString
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Enter the String :");
		String data=input.nextLine();
		String[] StringArray=data.trim().split("\\s+");
	    int[] wordlen=new int[StringArray.length];
		for(int i=0;i<StringArray.length;i++)
		{
			wordlen[i]=StringArray[i].length();
		}
	    int max=wordlen[0];
	    for(int i=0;i<wordlen.length;i++)
	    {
	    	if(wordlen[i]>max)
                 max=wordlen[i];
	    }
	    
    	String s1=new String("");
	    for(int i=1;i<=max;i++)
	    {
	    	int wordcount=0;
	    	for(int j=0;j<wordlen.length;j++)
	 	    {
	 	      if(wordlen[j]==i)
	 	      {
	 	    	  wordcount++;
	 	    	  s1=s1.concat(StringArray[j]+" ");
	 	      }
	 	    }
	    	if(wordcount>0)
	    	 System.out.println("\nNo. of word that have "+i+" Character : "+wordcount);
	    }
    	System.out.println("\n"+s1);	
	    
	}
}