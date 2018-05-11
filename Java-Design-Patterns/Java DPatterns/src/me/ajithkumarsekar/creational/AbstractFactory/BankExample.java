/**
 * 
 */
package me.ajithkumarsekar.creational.AbstractFactory;

/**
 * @author ajithkumar sekar
 *
 */

enum ALL_BANK {
	HDFC, IndianBank
}

enum ALL_LOAN {
	HomeLoan, EducationLoan
}

interface Bank {
	String getBankName();

}

class HDFC implements Bank {
	final String bankName;

	public HDFC() {
		bankName = "HDFC";
	}

	@Override
	public String getBankName() {
		return bankName;
	}
}

class IndianBank implements Bank {
	final String bankName;

	public IndianBank() {
		bankName = "Indian Bank";
	}

	@Override
	public String getBankName() {
		return bankName;
	}
}

abstract class Loan {
	protected double rate;

	public void calculateLoanPayment(final double loanAmount, final float years) {
		double EMI;
		float n;

		n = years * 12;
		rate = rate / 1200;
		EMI = ((rate * Math.pow((1 + rate), n)) / ((Math.pow((1 + rate), n)) - 1)) * loanAmount;

		System.out.println("your monthly EMI is " + EMI + " for the amount " + loanAmount + " you have borrowed");
	}
}

class HomeLoan extends Loan {

	public HomeLoan() {
		this.rate = 12;
	}

}

class EducationLoan extends Loan {

	public EducationLoan() {
		this.rate = 6;
	}

}

interface AbstractFactory {
	public Bank getBank(String bankName);

	public Loan getLoan(String loanName);
}

class LoanFactory implements AbstractFactory {

	@Override
	public Bank getBank(String bankName) {
		return null;
	}

	@Override
	public Loan getLoan(String loanName) {
		if (ALL_LOAN.HomeLoan.toString().equals(loanName)) {
			return new HomeLoan();
		} else if (ALL_LOAN.EducationLoan.toString().equals(loanName)) {
			return new EducationLoan();
		} else {
			return null;
		}
	}

}

class BankFactory implements AbstractFactory {

	@Override
	public Bank getBank(String bankName) {
		if (ALL_BANK.HDFC.toString().equals(bankName)) {
			return new HDFC();
		} else if (ALL_BANK.IndianBank.toString().equals(bankName)) {
			return new IndianBank();
		} else {
			return null;
		}
	}

	@Override
	public Loan getLoan(String loanName) {
		return null;
	}

}

class FactoryCreator {

	public static AbstractFactory getFactory(String choice) {
		if (choice.equalsIgnoreCase("Bank")) {
			return new BankFactory();
		} else if (choice.equalsIgnoreCase("Loan")) {
			return new LoanFactory();
		}
		return null;
	}
}

public class BankExample {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		final String bankName = ALL_BANK.HDFC.toString();
		final AbstractFactory bankFactory = FactoryCreator.getFactory("Bank");
		final Bank b = bankFactory.getBank(bankName);

		final double loanAmount = 732694;
		final float years = 2.5f;
		final String loanName = ALL_LOAN.EducationLoan.toString();
		final AbstractFactory loanFactory = FactoryCreator.getFactory("Loan");
		final Loan l = loanFactory.getLoan(loanName);
		l.calculateLoanPayment(loanAmount, years);

	}

}
