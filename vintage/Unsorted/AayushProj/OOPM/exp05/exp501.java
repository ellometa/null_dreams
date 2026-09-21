package exp05;
import java.util.Scanner;

class Customer {
    int accountId;
    String name;
    double balance;

    Customer(int accountId, String name, double balance) {
        this.accountId = accountId;
        this.name = name;
        this.balance = balance;
    }

    void display() {
        System.out.println("Account ID: " + accountId);
        System.out.println("Name: " + name);
        System.out.println("Balance: " + balance);
        System.out.println();
    }
}

class exp501 {
    static Customer[] customers;
    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of customers: ");
        int n = sc.nextInt();
        customers = new Customer[n];

        int choice;
        do {
            System.out.println("\n1. Add Account");
            System.out.println("2. Delete Account");
            System.out.println("3. Display Accounts");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    addAccount(sc);
                    break;
                case 2:
                    deleteAccount(sc);
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 4);

        sc.close();
    }

    static void addAccount(Scanner sc) {
        if (count == customers.length) {
            System.out.println("Error: Maximum number of customers reached.");
            return;
        }

        System.out.print("Enter Account ID: ");
        int id = sc.nextInt();
        sc.nextLine(); 
        System.out.print("Enter Name: ");
        String name = sc.nextLine();
        System.out.print("Enter Balance: ");
        double balance = sc.nextDouble();

        customers[count] = new Customer(id, name, balance);
        count++;
        System.out.println("Account added successfully!");
    }

    static void deleteAccount(Scanner sc) {
        if (count == 0) {
            System.out.println("No accounts to delete.");
            return;
        }

        System.out.print("Enter Account ID to delete: ");
        int id = sc.nextInt();
        boolean found = false;

        for (int i = 0; i < count; i++) {
            if (customers[i].accountId == id) {
                found = true;
                for (int j = i; j < count - 1; j++) {
                    customers[j] = customers[j + 1];
                }
                customers[count - 1] = null;
                count--;
                System.out.println("Account deleted successfully!");
                break;
            }
        }

        if (!found) {
            System.out.println("Account ID not found.");
        }
    }

    static void display() {
        if (count == 0) {
            System.out.println("No accounts to display.");
            return;
        }

        System.out.println("\nCustomer Details:");
        for (int i = 0; i < count; i++) {
            customers[i].display();
        }
    }
}
