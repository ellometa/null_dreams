class Account
{
    private int balance;
    
    public Account(int initialBalance)
    {
        this.balance = initialBalance;
    }
    
    public synchronized void credit(int amount)
    {
        balance += amount;
        System.out.println(Thread.currentThread().getName() + " credited " +
            amount + ". Balance: " + balance);
    }
    
    public synchronized void debit(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            System.out.println(Thread.currentThread().getName() + " debited " +
                amount + ". Balance: " + balance);
        }
        else
        {
            System.out.println(Thread.currentThread().getName() + " attempted to debit " +
                amount + " but insufficient funds.");
        }
    }
    
    public int getBalance()
    {
        return balance;
    }
}

class TransactionHandler implements Runnable
{
    private Account account;
    
    public TransactionHandler(Account account)
    {
        this.account = account;
    }
    
    @Override
    public void run()
    {
        for (int i = 0; i < 5; i++)
        {
            int amount = (int) (Math.random() * 200) + 1;
            if (Math.random() > 0.5)
            {
                account.credit(amount);
            }
            else
            {
                account.debit(amount);
            }
            try
            {
                Thread.sleep(100);
            }
            catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

class ConcurrentAccountSystem
{
    public static void main(String[] args)
    {
        Account account = new Account(1000);
        Thread t1 = new Thread(new TransactionHandler(account), "Client 1");
        Thread t2 = new Thread(new TransactionHandler(account), "Client 2");
        Thread t3 = new Thread(new TransactionHandler(account), "Client 3");
        t1.start();
        t2.start();
        t3.start();
        try
        {
            t1.join();
            t2.join();
            t3.join();
        }
        catch (InterruptedException e)
        {
            e.printStackTrace();
        }
        System.out.println("Final Balance: " + account.getBalance());
    }
}

