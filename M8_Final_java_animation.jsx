

import java.util.*;

public class AvengersBattle {

    static Scanner scanner = new Scanner(System.in);
    static Random random = new Random();

    public static void main(String[] args) {
        // Rooms
        String[] roomNames = { "Avengers HQ", "New York City", "Wakanda", "Villain's Lair" };
        String[] roomDescriptions = {
                "The Avengers HQ is buzzing with activity. Heroes gather here to plan.",
                "The streets of New York are chaotic with villains attacking civilians.",
                "Wakanda's advanced tech city glows with energy. Allies stand ready.",
                "The villain's lair is dark and full of traps. Danger lurks everywhere."
        };
        String[] roomObjects = { "Mjolnir", "Shield", "Vibranium Suit", "Infinity Stone" };
        String[] healthItems = { "", "Medkit", "Healing Potion", "" };

        // Villain HP (-1 = no villain)
        int[] villainHP = { -1, 30, 40, 100 }; // final boss in lair

        // Room connections [north, east, south, west]
        int[][] connections = {
                { 1, 2, -1, -1 },  // HQ
                { -1, -1, 0, -1 }, // New York
                { -1, 3, -1, 0 },  // Wakanda
                { -1, -1, -1, 2 }  // Villain Lair
        };

        int currentRoom = 0;
        int playerHP = 100;
        List<String> inventory = new ArrayList<>();
        boolean running = true;

        System.out.println("\nWelcome to the Avengers Battle!");

        while (running) {
            System.out.println("\nYou are in " + roomNames[currentRoom]);
            System.out.println(roomDescriptions[currentRoom]);
            System.out.println("You see a " + roomObjects[currentRoom] + " here.");

            if (!healthItems[currentRoom].isEmpty()) {
                System.out.println("There is a " + healthItems[currentRoom] + " here.");
            }

            // Exits
            System.out.print("Exits: ");
            String[] directions = { "north", "east", "south", "west" };
            for (int i = 0; i < 4; i++) {
                if (connections[currentRoom][i] != -1) System.out.print(directions[i] + " ");
            }
            System.out.println();

            // Villain encounter
            if (villainHP[currentRoom] > 0) {
                System.out.println("A villain appears with " + villainHP[currentRoom] + " HP!");
                while (villainHP[currentRoom] > 0 && playerHP > 0) {
                    System.out.println("\nYour HP: " + playerHP + " | Villain HP: " + villainHP[currentRoom]);
                    System.out.print("Do you want to 'attack', 'run', or 'use' a health item? ");
                    String action = scanner.next().toLowerCase();

                    if (action.equals("attack")) {
                        int playerDamage = random.nextInt(20) + 5;
                        int villainDamage = random.nextInt(15) + 5;

                        if (currentRoom == 3) villainDamage += 10; // Final boss stronger

                        // Item effects
                        if (inventory.contains("Mjolnir")) playerDamage += 10;
                        if (inventory.contains("Infinity Stone")) playerDamage += 20;
                        if (inventory.contains("Shield")) villainDamage -= 5;
                        if (inventory.contains("Vibranium Suit")) villainDamage -= 10;
                        if (villainDamage < 0) villainDamage = 0;

                        villainHP[currentRoom] -= playerDamage;
                        System.out.println("You deal " + playerDamage + " damage to the villain!");

                        if (villainHP[currentRoom] > 0) {
                            playerHP -= villainDamage;
                            System.out.println("The villain hits back for " + villainDamage + " damage!");
                        } else {
                            System.out.println("You defeated the villain!");
                        }
                    } else if (action.equals("run")) {
                        System.out.println("You retreat to the previous room.");
                        // Simple retreat: south > west > north > east
                        if (connections[currentRoom][2] != -1) currentRoom = connections[currentRoom][2];
                        else if (connections[currentRoom][3] != -1) currentRoom = connections[currentRoom][3];
                        else if (connections[currentRoom][0] != -1) currentRoom = connections[currentRoom][0];
                        else if (connections[currentRoom][1] != -1) currentRoom = connections[currentRoom][1];
                        break;
                    } else if (action.equals("use")) {
                        if (!healthItems[currentRoom].isEmpty()) {
                            int healAmount = random.nextInt(30) + 20;
                            playerHP += healAmount;
                            System.out.println("You use the " + healthItems[currentRoom] + " and recover " + healAmount + " HP!");
                            healthItems[currentRoom] = "";
                        } else {
                            System.out.println("No health items here!");
                        }
                    } else {
                        System.out.println("Unknown action.");
                    }

                    if (playerHP <= 0) {
                        System.out.println("You were defeated! Game over.");
                        running = false;
                        break;
                    }
                }
                if (!running) break;
            }

            // Check win condition
            boolean allVillainsDefeated = true;
            for (int hp : villainHP)
                if (hp > 0) allVillainsDefeated = false;

            if (allVillainsDefeated) {
                System.out.println("\nCongratulations! You defeated all the villains, including the final boss, and saved the world!");
                break;
            }

            // Player command outside combat
            System.out.print("\nWhat do you do? ");
            String cmd = scanner.next().toLowerCase();

            switch (cmd) {
                case "north":
                case "n":
                    if (connections[currentRoom][0] != -1) currentRoom = connections[currentRoom][0];
                    else System.out.println("You can't go that way.");
                    break;
                case "east":
                case "e":
                    if (connections[currentRoom][1] != -1) currentRoom = connections[currentRoom][1];
                    else System.out.println("You can't go that way.");
                    break;
                case "south":
                case "s":
                    if (connections[currentRoom][2] != -1) currentRoom = connections[currentRoom][2];
                    else System.out.println("You can't go that way.");
                    break;
                case "west":
                case "w":
                    if (connections[currentRoom][3] != -1) currentRoom = connections[currentRoom][3];
                    else System.out.println("You can't go that way.");
                    break;
                case "look":
                    System.out.println("You inspect the " + roomObjects[currentRoom] + ".");
                    break;
                case "take":
                    System.out.println("You take the " + roomObjects[currentRoom] + ".");
                    inventory.add(roomObjects[currentRoom]);
                    break;
                case "quit":
                case "q":
                    running = false;
                    break;
                default:
                    System.out.println("Unknown command.");
            }
        }

        System.out.println("\nThanks for playing the Avengers Battle!");
    }
}