    static void removeCarByMakeOrModel(Scanner scan) {
        if (carVector.isEmpty()) {
            System.out.println("No cars to remove.");
            return;
        }

        System.out.print("Enter make or model to remove: ");
        String inputRemoveText = scan.nextLine();

        boolean removedAny = false;

        // Use an iterator so we can safely remove while looping
        Iterator<Car> it = carVector.iterator();
        while (it.hasNext()) {
            Car carObject = it.next();
            if (carObject.matchesMakeOrModel(inputRemoveText)) {
                it.remove();   // remove this car
                removedAny = true;
            }
        }

        if (removedAny) {
            System.out.println("✅ Matching car(s) removed.");
        } else {
            System.out.println("No matching car found to remove.");
        }
    }
