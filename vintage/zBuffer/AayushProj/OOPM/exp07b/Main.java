class BankAccount {
    private double balance;

    public BankAccount(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: $" + amount);

        } else {
            System.out.println("Invalid deposit amount");
        }
    }

    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException("Insufficient funds! Available balance: $" + balance + ", Requested amount: $" + amount);
        } else {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        }
    }

    public double getBalance() {
        return balance;
    }
}


public class Main {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(500.00);

        System.out.println("Current Balance: $" + account.getBalance());
        account.deposit(200.00);
        System.out.println("Balance after deposit: $" + account.getBalance());
        try {
            account.withdraw(100.00);
            System.out.println("Balance after withdrawal: $" + account.getBalance());
        } 
        catch (InsufficientFundsException e) {
            System.out.println(e.getMessage());
        }
        try {
            System.out.println("Trying to withdraw $700.00");
            account.withdraw(700.00);
        } 
        catch (InsufficientFundsException e) {
            System.out.println(e.getMessage());
        }
        System.out.println("Final Balance: $" + account.getBalance());

    }
}
