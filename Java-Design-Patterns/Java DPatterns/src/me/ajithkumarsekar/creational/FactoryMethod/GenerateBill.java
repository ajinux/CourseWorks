package me.ajithkumarsekar.creational.FactoryMethod;

/*
 * @author ajithkumar sekar
 * */

enum PlanTypes{
	DOMESTIC, COMMERCIAL, PREMIUM
}

abstract class PricingPlan {
	protected double rate;

	abstract void setRate();

	public double calculateBill(int usageUnits) {
		return rate * usageUnits;
	}
}

class DomesticPlan extends PricingPlan {
	@Override
	void setRate() {
		rate = 2.34;
	}
}

class CommercialPlan extends PricingPlan {

	@Override
	void setRate() {
		rate = 4.56;
	}
}

class PermiumPlan extends PricingPlan {
	
	@Override
	void setRate() {
		rate = 7;
	}
}

class GetPlanFactory{
	public PricingPlan getPricingPlan(final String plan){
		if(plan == null || plan.length() == 0){
			return null;
		}
		if(PlanTypes.DOMESTIC.toString().equals(plan)){
			return new DomesticPlan();
		}else if(PlanTypes.COMMERCIAL.toString().equals(plan)){
			return new CommercialPlan();
		}else if(PlanTypes.PREMIUM.toString().equals(plan)){
			return new PermiumPlan();
		}else{
			return null;
		}
	}
}

public class GenerateBill {

	public static void main(String[] args) {
		final GetPlanFactory planFactory = new GetPlanFactory();
		final PricingPlan pricingPlan = planFactory.getPricingPlan(PlanTypes.PREMIUM.toString());
		pricingPlan.setRate();
		System.out.println(pricingPlan.calculateBill(20));
	}

}
