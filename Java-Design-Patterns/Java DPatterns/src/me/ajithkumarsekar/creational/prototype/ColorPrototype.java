/**
 * 
 */
package me.ajithkumarsekar.creational.prototype;

import java.util.HashMap;
import java.util.Map;

/**
 * @author ajithkumar sekar
 * reference: https://www.geeksforgeeks.org/prototype-design-pattern/
 * https://www.geeksforgeeks.org/clone-method-in-java-2/
 */

abstract class Color implements Cloneable {
	protected String colorName;

	abstract String getColor();

	public Object Clone() {
		Object clone = null;
		try {
			clone = super.clone();
		} catch (CloneNotSupportedException e) {
			e.printStackTrace();
		}

		return clone;
	}
}

class BlackColor extends Color{
	
	public BlackColor(){
		colorName = "Black";
	}
	
	@Override
	public String getColor() {
		return colorName;
	}
	
}

class WhiteColor extends Color{
	public WhiteColor(){
		colorName = "White";
	}
	
	@Override
	public String getColor(){
		return colorName;
	}
	
}

class ColorStore{
	private static Map<String, Color> colorMap = new HashMap<String, Color>();
	
	static{
		// here the cost of creation should be usually high like DB operations 
		colorMap.put("Black", new BlackColor());
		colorMap.put("White", new WhiteColor());
	}
	
	public static Color getColor(String color){
		return (Color)colorMap.get(color).Clone();
	}
}

public class ColorPrototype {

	public static void main(String[] args) {
		final Color black = ColorStore.getColor("Black");
		System.out.println("Color : "+ black.getColor() + " , hashCode : "+black.hashCode());
		
		final Color white = ColorStore.getColor("White");
		System.out.println("Color : "+ white.getColor() + " , hashCode : "+white.hashCode());
		
		final Color black1 = ColorStore.getColor("Black");
		System.out.println("Color : "+ black1.getColor() + " , hashCode : "+black1.hashCode());
	}

}
