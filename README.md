# Zorks: The Silent Castle 🏰
An interactive fiction adventure developed for the Advanced Programming for AAA Video Games examination.

---

## Project & Authorship
* **Author:** Víctor Andujar Terrón
* **Repository:** [[Link to GitHub]](https://github.com/VictorAnTe/Zorks-Game)
* **License:** MIT License (Free for educational and personal use).

---

## Quick Start (How to Run)
You don't need to compile the code to play. A pre-compiled executable is provided for Windows.

1.  Download and extract the **Zorks_v1.0.zip** file.
2.  Open the folder and run **Zorks.exe**.
3.  *Note:* If Windows Defender flags the file, click "More Info" and "Run Anyway" (this occurs with unsigned custom executables).

---

## Gameplay Guide
Interaction is handled entirely through text commands in the console. If you get stuck, type any unrecognized word to display the help menu.

### Navigation & Exploration
* **`look`**: Describe the current room, its exits, and visible items.
* **`look [item]`**: Examine a specific object for clues or details.
* **`go [north/south/east/west]`**: Move between rooms.
* **`inventory`**: List all items currently in your possession.

### Interaction & Inventory Management
* **`get [item]`**: Pick up an item from the floor.
* **`drop [item]`**: Remove an item from your inventory and leave it in the room.
* **`save [item] [container]`**: Place an item from your inventory into a container (e.g., a chest or bag).
* **`open [container]`**: Open a container and move its entire contents to your inventory.
* **`use [item]`**: Consume or trigger an item (like potions or keys).

### Combat & Equipment
* **`equip [weapon]`**: Equip a weapon to increase your attack power.
* **`unequip`**: Remove your current weapon.
* **`battle [enemy]`**: Engage an NPC in a fight to the death.

### Riddles
* **`solve`**: Display the riddle associated with the current room.
* **`solve [answer]`**: Attempt to answer the riddle to unlock paths or items.

---

## Victory Guide (How to Win)
To defeat the darkness of the castle, follow these strategic steps:

1.  **Thorough Exploration:** Do not rush the castle gates. Explore the surrounding forest and outskirts to find essential gear and consumables.
2.  **Gear Optimization:** Check the damage output of different weapons. Always `equip` your best gear before a fight.
3.  **Riddle Mastery:** Critical paths are often blocked. Use `solve` to understand the challenge in case it is a riddle and find the right answer. (*The answer is "dracula"/"vampire"*).
4.  **The Final Encounter:** The game concludes when you defeat **Dracula** in his inner sanctum.
    * *Pro Tip:* Combat involves **RNG** (luck). Ensure your health is at maximum before initiating the final battle.
    * *Pro Tip:* Combat is turn by turn mode, but you can health in the combat without being damage.
