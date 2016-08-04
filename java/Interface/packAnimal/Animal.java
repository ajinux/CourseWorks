/*Question:-
 * The Transport interface declares a deliver method. 
 * The abstract class Animal is the superclass of the Tiger, Camel, Deer and Donkey classes.
 * The Transport interface is implemented by the Camel and Donkey classes. 
 * Write a Java program to initialize an array of four Animal objects. 
 * If the object implements the Transport interface, the deliver method is invoked. 
 * Use suitable data members
 */

package packAnimal;
import Trans.Transport;

abstract class Animal
{
	abstract void animethod();
}

class Tiger extends Animal
{

	void animethod()
	{
	 System.out.println("From Tiger class-animethod");	
	}
	
}

class Camel extends Animal implements Transport
{
	public Camel()
	{
		animethod();
		deliver();
	}
	void animethod()
	{
		System.out.println("From Camel class --animethod");
	}
	
	public void deliver()
	{
		System.out.println("From Camel class --deliver");
	}
}

class Deer extends Animal
{
   void animethod()
   {
	   System.out.println("From class Deer --animethod");
   }
}

class Donkey extends Animal implements Transport
{
	public Donkey()
	{
		animethod();
		deliver();
	}
	void animethod()
	{
		System.out.println("From class Donkey --animethode");
	}
	public void deliver()
	{
		System.out.println("From class Donkey --deliver");
	}
}

class mainclass
{
	public static void main(String args[])
	{
		Tiger t1=new Tiger();
		Camel c1=new Camel();
		Deer d1=new Deer();
		Donkey do1=new Donkey();
		t1.animethod();
		d1.animethod();

	}
}













