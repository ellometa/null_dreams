package exp06;
import java.util.Scanner;
import java.util.Vector;
import java.util.Enumeration;

class Item {
    String name;
    double price;
    int quantity;

    Item(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public String toString() {
        return "Item: " + name + ", Price: " + price + ", Quantity: " + quantity;
    }
}

public class exp602 {
    public static void main(String[] args) {
        Vector<Item> shoppingList = new Vector<>();
        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Shopping List Menu ---");
            System.out.println("1. Add item");
            System.out.println("2. Delete item");
            System.out.println("3. Add item at specific position");
            System.out.println("4. Display items");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // consume newline

            switch (choice) {
                case 1:
                    System.out.println("Enter item name:");
                    String name = sc.nextLine();
                    System.out.println("Enter price:");
                    double price = sc.nextDouble();
                    System.out.println("Enter quantity:");
                    int quantity = sc.nextInt();
                    shoppingList.add(new Item(name, price, quantity));
                    System.out.println("Item added to the list.");
                    break;

                case 2:
                    System.out.println("Enter the name of the item to delete:");
                    String deleteItem = sc.nextLine();
                    deleteItemFromList(shoppingList, deleteItem);
                    break;

                case 3:
                    System.out.println("Enter position to add an item (0-based index):");
                    int position = sc.nextInt();
                    sc.nextLine();
                    System.out.println("Enter item name:");
                    String posItemName = sc.nextLine();
                    System.out.println("Enter price:");
                    double posItemPrice = sc.nextDouble();
                    System.out.println("Enter quantity:");
                    int posItemQuantity = sc.nextInt();
                    shoppingList.add(position, new Item(posItemName, posItemPrice, posItemQuantity));
                    System.out.println("Item added at position " + position);
                    break;

                case 4:
                    System.out.println("Your shopping list:");
                    printList(shoppingList);
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice, please try again.");
            }
        } while (choice != 5);

        sc.close();
    }

    public static void deleteItemFromList(Vector<Item> list, String itemName) {
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).name.equalsIgnoreCase(itemName)) {
                list.remove(i);
                System.out.println(itemName + " removed from the shopping list.");
                return;
            }
        }
        System.out.println(itemName + " not found in the shopping list.");
    }

    public static void printList(Vector<Item> list) {
        if (list.isEmpty()) {
            System.out.println("The shopping list is empty.");
        } else {
            Enumeration<Item> items = list.elements();
            while (items.hasMoreElements()) {
                System.out.println(items.nextElement());
            }
        }
    }
}
