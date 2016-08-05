
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
	    	String[] s2=new String[wordlen.length];
	    	int len=0;
	    	for(int j=0;j<wordlen.length;j++)
	 	    {
	 	      if(wordlen[j]==i)
	 	      {
	 	    	  wordcount++;
	 	    	  s2[len]=StringArray[j];
	 	    	  len++;
	 	      }
	 	    }
	    	if(wordcount>0)
	    	{
	    	 System.out.println("\nNo. of word that have "+i+" Character : "+wordcount);
	    	 if(wordcount==1)
	    	 {
	    		 s1=s1.concat(s2[0]+" ");
	    	 }
	    	 else
	    	 {
	    		 for(int j=0;j<len;j++)
	    		 {
	    			 for(int k=j+1;k<len;k++)
	    			 {
	    				if(s2[j].compareTo(s2[k])>0)
	    				{
	    					String temp=s2[j];
	    					s2[j]=s2[k];
	    					s2[k]=temp;
	    				}
	    			 }
	    		 }
	    		 for(int j=0;j<len;j++)
	    		 {
	    			 s1=s1.concat(s2[j]+" ");
	    		 }
	    	 }
	    	}
	    }
    	System.out.println("\n"+s1);	
	    
	}
}
