// https://github.com/HassanIQ777/Neverland

#include <cctype>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#include "libutils/src/funcs.hpp"

using namespace std;

// VARIABLES
string name = "Lost Kin", race = "Warrior"; // default name and race
int level = 0, XP = 0, next_level = 0, healAmount = 0, max_health = 100,
    heal = 0;
int enemy_level = 0, enemy_xp = 0, past_enemy_hp;
float money_charm = 1;
bool has_bought_first_charm = false;
float sword_upgrade = 1;
bool can_upgrade_sword = true;
short enemy_hp = 0, health = 0;
int dist = 0, story = 1; // distance unit is called Bosels in Neverland
int max_dist = dist;
int money = 0; // Zyniolax is the running currency in Neverland
int healing_potions = 0;
string enemy_list1[] = {"Goblin", "Centipede",    "Tryonix",
                        "Elf",    "Aspid Minion", "Troll"};
string enemy_list2[] = {"Witch", "Wizard", "Aspid Minion", "Primal Aspid",
                        "Chinchilasaur"};
string enemy_list3[] = {"Aspid Minion", "Aspid Warrior", "Primal Aspid",
                        "Acid Hermit", "Acid Slime"}; // citizens
string enemy_list4[] = {"Aspid Guard", "Queen Servant", "Acidmold",
                        "Aspid Minion"};

int enemy_count1 = sizeof(enemy_list1) / sizeof(enemy_list1[0]);
int enemy_count2 = sizeof(enemy_list2) / sizeof(enemy_list2[0]);
int enemy_count3 = sizeof(enemy_list3) / sizeof(enemy_list3[0]);
int enemy_count4 = sizeof(enemy_list4) / sizeof(enemy_list4[0]);

int enemy_dmg;
string current_enemy = "";
string good_bye_message = "";
bool has_the_player_encountered_and_talked_to_the_first_villager_yet_or_not =
    false;
bool has_the_player_encountered_and_talked_to_the_second_villager_yet_or_not =
    false;
bool has_the_player_encountered_and_talked_to_the_third_villager_yet_or_not =
    false;
bool has_tamed_the_horse = false;
bool has_met_acid_watcher = false;
bool free_potion = true;
bool has_city_access = false;
bool has_the_player_encountered_and_talked_to_the_fourth_villager_yet_or_not =
    false;
bool has_met_citizen = false;
bool has_talked_with_golem = false;
bool has_defeated_golem = false;
int sword_upgrade_cost = 200;
int adrenaline = 0;
bool has_obtain_crystalized_goop = false;
bool has_obtained_rancid_egg = false;
bool has_encountered_queen = false;
bool has_defeated_queen = false;
bool killed_by_queen = false;
int queen_hp; // declared here to avoid a declaration error

//                                                     ACHIEVEMENTS

bool prop_hunter = false;
bool slayer_of_worlds = false;
bool experienced = false;
bool master = false;
bool charmed = false;
bool spell_twister = false;
bool intruder = false;
bool honour = false;
bool true_friendship = false;
bool close_encounter = false;
bool heavy_drinker = false;
bool pet_owner = false;
bool sword_master = false;

//                                                     FUNCTIONS

void start();
void HUD();
void UI();
void Combat();
void Attacking();
void CombatHUD();
void Moving();
void CreateEnemy();
void respawn();
void CityGuard();
void CityGuardHUD();
void Citizen();
void Golem();
void QueenFight();
void QueenUI();

void BrewerNPC();
void meetOldMan();
void Swordsmith();
void FindHorse();
void meetAcidWatcher();
void meetTraitor();
void Shaman();
void Citizen();
void Queen();

void OpenMenu();
void OpenShop();
void MoveHorse();
void Credits();

void print(string text, int cd);
int MaxDist(int dist);
void Neverland();
void windowsNeverland();

int main() {
  // GAME
  srand(time(0));
  level = 1;
  XP = 0;
  next_level = (rand() % 30) + (level * 30);
  health = 80 + (20 * level);
  max_health = 80 + (20 * level);
  funcs::clearTerminal();

  start();

  //  The Main Loop of the Game (lmao)
  while (true) {
    HUD();
  }
}

void start() {
#ifdef __ANDROID__
  print("NOTICE:\nIT IS HIGHLY ADVISED TO PLAY THIS GAME ON PC.", 20);
#elif __APPLE__
  print("NOTICE:\nIT IS HIGHLY ADVISED TO PLAY THIS GAME ON PC.", 20);
#endif
  funcs::msleep(750);
  funcs::clearTerminal();
  funcs::printCentered("********************The Prophecy********************");
  cout << endl << endl;
  funcs::msleep(1500);
  funcs::printCentered("In a vast kingdom, there exists a nurturing Queen,");
  cout << endl;
  funcs::msleep(3500);
  funcs::printCentered("So powerful yet caring, so easy yet keen.");
  cout << endl;
  funcs::msleep(3500);
  funcs::printCentered("Ages will pass, then a warrior will arise,");
  cout << endl;
  funcs::msleep(3500);
  funcs::printCentered("That warrior will bring this kingdom to its demise.");
  cout << endl;
  funcs::msleep(6500);
#ifdef __linux__
  print("Press 'Enter' to continue.", 60);
  getchar();
#elif _WIN32
  system("pause");
#endif
  funcs::clearTerminal();
  print("Enter your name: ", 50);
  while (true) {
    getline(cin, name);
    if (name.length() >= 18) {
      print("Name must be less than 18 characters long: ", 30);
    } else if (!name.empty()) {
      break;
    } else {
      print("Enter your name: ", 40);
    }
  }
  funcs::msleep(150);
  print("Enter your race: ", 60);
  while (true) {
    getline(cin, race);
    if (race.length() >= 18) {
      print("Race must be less than 18 characters long: ", 30);
    } else if (!race.empty()) {
      break;
    } else {
      print("Enter your race: ", 40);
    }
  }
  funcs::msleep(1750);
  funcs::clearTerminal();
  print(
      "You wake up in a dark cave.....\nyou don't remember how you got here\n",
      80);
  funcs::msleep(300);
  print("You're weak, tired, and hungry, you start looking around\n", 80);
  funcs::msleep(500);
  print("You see the cave exit.\n\n", 80);
  while (true) {
    string choice;
    print("What's your next step:\n\n", 50);
    print("1) Exit the cave\n2) Stay in the cave and sleep\n", 35);
    cout << "--> ";
    cin >> choice;
    if (choice == "1") {
      break;
    } else {
      print("You go to sleep\n", 50);
      print("ZZZZZZZZZZZZzzzzzzzzzzzzzz\n", 150);
      funcs::msleep(5000);
    }
  }
  print("You pick up a sword you found inside a rock.\n", 70);
  funcs::msleep(750);
  print(
      "You exit the cave and see a massive land extending beyond the horizon\n",
      70);
  print("Generating character", 150);
  print(".....", 200);
  funcs::msleep(750);
}
void UI() {
  funcs::clearTerminal();
  if (XP >= next_level) {
    XP -= next_level;
    level++;
    next_level = (40 + (rand() % 20)) + (level * 28);
    max_health += 20;
    health += 20;
  }
  if (dist >= 96) {
    cout << "*************************************************" << endl;
    cout << left << setw(5) << "Name: " << left << setw(18) << name
         << "| Health: " << health << endl;
    cout << left << setw(5) << "Race: " << left << setw(18) << race
         << "| XP: " << XP << endl;
    cout << left << setw(4) << "Level: " << left << setw(17) << level
         << "| Next Level: " << next_level << " XP" << endl;
    cout << left << setw(24) << "Distance: ???" << left << setw(8)
         << "| Money: " << money << " Zyniolax" << endl;
    cout << "*************************************************" << endl;
  } else {
    cout << "*************************************************" << endl;
    cout << left << setw(5) << "Name: " << left << setw(18) << name
         << "| Health: " << health << endl;
    cout << left << setw(5) << "Race: " << left << setw(18) << race
         << "| XP: " << XP << endl;
    cout << left << setw(4) << "Level: " << left << setw(17) << level
         << "| Next Level: " << next_level << " XP" << endl;
    cout << left << setw(4) << "Distance: " << left << setw(3) << dist << left
         << setw(11) << "Bosels"
         << "| Money: " << money << " Zyniolax" << endl;
    cout << "*************************************************" << endl;
  }
}

void HUD() {
  UI();
  Moving();
}

void CombatHUD() {
  funcs::clearTerminal();
  if (has_the_player_encountered_and_talked_to_the_fourth_villager_yet_or_not) {
    cout << "***************** FIGHT ********************" << endl;
    cout << left << setw(18) << name << "  VS " << current_enemy << endl;
    cout << left << setw(6) << "Health: " << left << setw(12) << health
         << "|  Enemy Health: " << enemy_hp << endl;
    cout << left << setw(5) << "Level: " << left << setw(13) << level
         << "|  Enemy Level: " << enemy_level << endl;
    cout << "Adrenaline: " << setw(8) << adrenaline << "|" << endl;
    cout << "********************************************" << endl;
  } else {
    cout << "***************** FIGHT ********************" << endl;
    cout << left << setw(18) << name << "  VS " << current_enemy << endl;
    cout << left << setw(6) << "Health: " << left << setw(12) << health
         << "|  Enemy Health: " << enemy_hp << endl;
    cout << left << setw(5) << "Level: " << left << setw(13) << level
         << "|  Enemy Level: " << enemy_level << endl;
    cout << "********************************************" << endl;
  }
}

void Combat() {
  CombatHUD();
  string choice;
  int player_dmg =
      (((rand() % 10) + 5) + ((float(level * 7) / 2) - 6) * sword_upgrade);

  float dmg_val = ((rand() % 10) + 3) + (float(enemy_level * 6) / 2);
  if (dist < 20) {
    enemy_dmg = (dmg_val - 5);
  } else if (dist >= 20 && dist < 65) {
    enemy_dmg = ((dmg_val - 5)) * 1.2;
  } else if (dist >= 65 && dist < 96) {
    enemy_dmg = ((dmg_val - 5)) * 1.4;
  } else if (dist >= 96) {
    enemy_dmg = ((dmg_val - 5)) * 1.6;
  }

  if (health > 0 && enemy_hp > 0) {
    cout << "\n A)ttack \n D)efend \n R)UN! \n";
    if (healing_potions >= 1) {
      cout << " H)ealing potion (" << healing_potions << ")\n";
    }
    if (adrenaline >= 15 &&
        has_the_player_encountered_and_talked_to_the_fourth_villager_yet_or_not) {
      cout << " U)se spell \n";
    }
    cout << " --> ";
    cin >> choice;
    choice[0] = tolower(choice[0]);
    if (choice == "a") { // Attacking
      print("Attacking...", 40);
      cout << "You dealt " << player_dmg << " damage to the " << current_enemy
           << endl;
      enemy_hp -= player_dmg;
      if (adrenaline <= 26) {
        int randi = (rand() % 3) + 2;
        adrenaline += randi;
      } else {
        adrenaline = 30;
      }
      Attacking();
    } else if (choice == "d") { // Defending
      print("Blocking the attack...", 40);
      int c = (rand() % 100) + 1;
      if (c <= 65) // 65% chance of blocking
      {
        heal = ceil((10 + ((level * 5)))); // awesome equation i know
        if (health + heal <= max_health) {
          print("You blocked the incoming attack and managed to heal by ", 30);
          cout << heal << endl;
          health += heal;
          funcs::msleep(500);
          Combat();
        } else {
          health = max_health;
          print("You blocked the incoming attack and fully healed.\n", 30);
          funcs::msleep(500);
          Combat();
        }
      } else {
        print("You failed to block the attack and the ", 30);
        cout << current_enemy;
        print(" managed to deal ", 30);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(700);
        if (health <= 0) {
          respawn();
        }
        Combat();
      }
    } else if (choice == "r") { // Running
      print("You attempt to run...\n", 40);
      int ch = (rand() % 100) + 1;
      if (ch <= 75) // 75% chance of success
      {
        print("You had successfully run away from the ", 30);
        cout << current_enemy << endl;
        funcs::msleep(1500);
        HUD();
      } else {
        print("You failed to run away and the ", 30);
        cout << current_enemy;
        print(" stabbed you and dealt ", 30);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(700);
        if (health <= 0) {
          respawn();
        }
        Combat();
      }
    } else if (choice == "h" && healing_potions >= 1) {
      if (health == max_health) {
        print("Your health is already at max.", 50);
        funcs::msleep(750);
        Combat();
      } else {
        healing_potions -= 1;
        health = max_health;
        print("You used a healing potion. You fully healed.\n", 40);
        funcs::msleep(1500);
        cin.clear();
        Combat();
      }
    }

    else if (choice == "u" && adrenaline >= 15) {
      print("You used an Energy Burst to deal ", 30);
      cout << ceil(player_dmg * 2.5) << " damage to the " << current_enemy
           << endl;
      adrenaline -= 15;
      enemy_hp -= ceil(player_dmg * 2.5);
      Attacking();
    } else {
      print("Invalid input! try again.", 30);
      funcs::msleep(750);
      Combat();
    }
  } else {
    print("Invalid input! try again.", 30);
    funcs::msleep(750);
    Combat();
  }
}
void CreateEnemy() {
  enemy_level = (rand() % 2) + level;
  enemy_hp = (rand() % 40) + (enemy_level * 23);
  if (current_enemy == enemy_list4[2]) {
    enemy_hp *= 1.8;
  }
  enemy_xp = enemy_hp;
  past_enemy_hp = enemy_hp;

  if (dist < 20) {
    current_enemy = enemy_list1[rand() % enemy_count1];
  } else if (dist >= 20 && dist < 65) {
    current_enemy = enemy_list2[rand() % enemy_count2];
  } else if (dist >= 60 && dist < 96) {
    current_enemy = enemy_list3[rand() % enemy_count3];
  } else if (dist >= 95) {
    current_enemy = enemy_list4[rand() % enemy_count4];
  }
}

void Attacking() {
  if (current_enemy == "ACID GOLEM") {
    funcs::msleep(1000);
    Golem();
  }

  funcs::msleep(750);
  if (enemy_hp > 0) {
    cout << "\nThe " << current_enemy;
    print(" attacked you and dealt ", 40);
    cout << enemy_dmg << " damage" << endl;
    health -= enemy_dmg;
    funcs::msleep(1500);
    Combat();
  }
  if (health < 1) {
    respawn();
  }

  else if (enemy_hp < 1) {
    int money_drop =
        abs((((rand() % 7) + 5) + ((past_enemy_hp * 0.10))) * money_charm);
    money += money_drop;
    enemy_hp = 0;
    CombatHUD();
    cout << "The " << current_enemy << " died and dropped " << money_drop
         << " Zyniolaxes" << endl;
    XP += enemy_xp;
    funcs::msleep(2000);
    HUD();
  }
  funcs::msleep(1000);
  Combat();
}

void Moving() {
  MaxDist(dist);
  string choice;
  cout << "\n M)ove Forward\n R)elax\n B)ack\n";
  if (has_tamed_the_horse && dist < 96) {
    cout << " T)ravel on Horse\n";
  }
  if (dist == 115 && story == 1) {
    cout << " A)scend the stairs\n";
  }
  if (dist == 115 && story == 2) {
    cout << " D)escend the stairs\n";
  }
  if (dist == 125 && story == 2) {
    cout << " A)scend the stairs\n";
  }
  if (dist == 125 && story == 3) {
    cout << " D)escend the stairs\n";
  }

  cout << " --> ";
  cin >> choice;
  choice = choice[0];
  choice[0] = tolower(choice[0]);
  if (choice == "m") {
    if (dist == 120 && story == 1) {
      print("You reached the end of the castle, go back!\n", 40);
      funcs::msleep(250);
      HUD();
    } else if (dist == 130 && story == 2) {
      print("You reached the end of the castle, go back!\n", 40);
      funcs::msleep(250);
      HUD();
    } else {
      print("You begin moving forward...\n", 30);
      dist++;
      if (dist == 18) {
        BrewerNPC();
      }
      if (dist == 35) {
        Swordsmith();
      }
      if (dist == 60 && !has_met_acid_watcher) {
        meetAcidWatcher();
      }
      if (dist == 61 && free_potion) {
        meetTraitor();
      }

      if (dist == 42 && !has_tamed_the_horse) {
        UI();
        print("\nYou see a horse\n", 60);
        funcs::msleep(750);
        print("Seems like it belongs to nobody\n", 60);
        funcs::msleep(750);
        FindHorse();
      }
      if (dist == 62 || dist == 64) {
        funcs::msleep(300);
        HUD();
      }
      if (dist == 63 && !has_city_access) {
        print("You feel the earth shaking... \n", 50);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 65) {
        if (!has_city_access) {
          enemy_hp = max_health * 3;
          print("Prepare for a boss battle....", 50);
          funcs::msleep(2500);
          CityGuard();
        }
      }
      if (dist == 72 &&
          !has_the_player_encountered_and_talked_to_the_fourth_villager_yet_or_not) {
        Shaman();
      }

      if (dist == 20 &&
          !has_the_player_encountered_and_talked_to_the_second_villager_yet_or_not) {
        meetOldMan();
        HUD();
      }
      if (dist == 80 && !has_met_citizen) {
        Citizen();
      }
      if (dist == 87 && !has_defeated_golem) {
        print("\nYou're getting closer to the castle... \n", 50);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 89 && !has_defeated_golem) {
        print("\nSeems like its door is protected by a large creature.\n", 50);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 95 && !has_defeated_golem) {
        UI();
        if (!has_talked_with_golem) {
          print("\n[ACID GOLEM]: Why are you here little one?\n\n", 70);
          funcs::msleep(1500);
          cout << "[" << name << "]: ";
          print("I want to enter this castle.\n\n", 70);
          funcs::msleep(1500);
          print("[ACID GOLEM]: *Laughs* nehehehehe, little one....you'd have "
                "to get through me first.\n",
                70);
          funcs::msleep(2000);
          has_talked_with_golem = true;
        }
        if (has_talked_with_golem)

          print("\n[ACID GOLEM]: So, do you accept the challenge?", 70);
        funcs::msleep(2000);
        string choice;
        print("\n\nAccept the challenge:\n\nY)es\nN)o\n--> ", 30);
        cin >> choice;
        choice[0] = tolower(choice[0]);
        if (choice == "y") {
          print("\n--> Challenge accepted <--\n", 50);
          funcs::msleep(1000);
          enemy_hp = floor(max_health * 4.5);
          Golem();
        } else {
          print("\n--> Challenge denied <--\n", 50);
          funcs::msleep(1000);
          print("\n[ACID GOLEM]: That's for your own good.\n", 70);
          funcs::msleep(3000);
          dist--;
          HUD();
        }
      }
      if (dist == 96) {
        print("\nYou entered the castle", 80);
        funcs::msleep(2500);
        HUD();
      }
      if (dist == 119 && story == 1 && !has_obtain_crystalized_goop) {
        has_obtain_crystalized_goop = true;
        UI();
        print("\nYou found a weird shiny solid sticking from the ground\n", 70);
        funcs::msleep(750);
        print("You smash it with your sword\n", 70);
        funcs::msleep(2000);
        print("You obtained the 'Crystalized Goop'\n", 70);
        funcs::msleep(750);
        print("Your health has been increased by 20%\n", 70);
        funcs::msleep(2000);
        max_health = ceil(max_health * 1.20);
        HUD();
      }
      if (dist == 128 && story == 2 && !has_obtained_rancid_egg) {
        has_obtained_rancid_egg = true;
        UI();
        print("\nYou find a golden egg hidden amongst other eggs\n", 70);
        print("It might be valuable, you take it.\n", 70);
        funcs::msleep(2000);
        print("You obtained the 'Rancid Egg'\n", 70);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 126 && story == 3 && !has_encountered_queen) {
        print("\nYou see lots of eggs scattered around in this room\n", 70);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 128 && story == 3 && !has_encountered_queen) {
        print("\nYou hear noises coming from the end of this corridor\n", 70);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 130 && story == 3 && !has_encountered_queen) {
        print("\nYou're walking on yellow royal carpet\n", 70);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 133 && story == 3 && !has_encountered_queen) {
        print("\nYou're by a big room\n", 70);
        funcs::msleep(2000);
        HUD();
      }
      if (dist == 134 && story == 3 && !has_encountered_queen) {
        print("\nYou take a look at what's inside the room\n", 70);
        funcs::msleep(1000);
        print("You see a large creature with a crown laying eggs\n", 70);
        funcs::msleep(3000);
        HUD();
      }
      if (dist >= 135 && !killed_by_queen && !has_defeated_queen) {
        Queen();
      } else if (dist >= 135 && killed_by_queen && !has_defeated_queen) {
        UI();
        print("\nRejoining the boss battle.....\n", 50);
        QueenFight();
      }

      if (has_defeated_queen) {
        Credits();
      }

      int temp = (rand() % 100) + 1;
      if (temp <= 50 && dist >= max_dist && story != 3) {
        CreateEnemy();
        print("You encountered a ", 30);
        cout << current_enemy;
        print(", prepare to fight!\n", 30);
        funcs::msleep(1500);
        Combat();
      } else if (temp <= 10 && dist < max_dist && story != 3) {
        CreateEnemy();
        print("You encountered a ", 30);
        cout << current_enemy;
        print(", prepare to fight!\n", 30);
        funcs::msleep(1500);
        Combat();
      } else {
        print("You find nothing of interest.\n", 20);
        funcs::msleep(200);
        HUD();
      }
    }
  } else if (choice == "r") {
    healAmount = floor((max_health * 0.34));

    print("You sit for a while to relax\n", 30);
    funcs::msleep(150);

    if (health == max_health) {
      print("Your health is already at max health.", 30);
      funcs::msleep(500);
      HUD();
    } else {
      health = min(max_health, health + healAmount);
      if (health != max_health) {
        print("You healed by resting, now your health is ", 30);
        cout << health << endl;
      } else {
        print("You healed by resting, now are fully healed. ", 30);
      }
      funcs::msleep(500);
      HUD();
    }
  } else if (choice == "b") {
    if (dist > 0) {
      dist--;
      if (dist == 18) {
        BrewerNPC();
      }
      if (dist == 35) {
        Swordsmith();
      }
      if (dist == 42 && !has_tamed_the_horse) {
        UI();
        print("\nYou see a horse\n", 60);
        funcs::msleep(750);
        print("Seems like it belongs to nobody\n", 60);
        funcs::msleep(750);
        FindHorse();
      }
      print("You begin moving backwards.....\n", 30);
      int temp = (rand() % 100) + 1;
      if (temp <= 10) { // much lower chance of encounters
        CreateEnemy();
        print("You encountered a ", 30);
        cout << current_enemy;
        print(", prepare to fight!\n", 30);
        funcs::msleep(1500);
        Combat();
      } else if (dist <= 115 && story == 2) {
        dist = 115;
        print("You're at the start of this floor!", 40);
        funcs::msleep(1250);
        HUD();
      } else if (dist <= 125 && story == 3) {
        dist = 125;
        print("You're at the start of this floor!", 40);
        funcs::msleep(1250);
        HUD();
      } else {
        print("You're back on track.\n", 20);
        funcs::msleep(200);
        HUD();
      }
    }

    else {
      print("You're at the starting point!", 40);
      funcs::msleep(250);
      HUD();
    }
  } else if (choice == "t" && has_tamed_the_horse && dist < 96) {
    MoveHorse();
  } else if (choice == "a" && dist == 115 && story == 1) {
    print("\nYou're climbing up the stairs to the second floor...\n", 50);
    funcs::msleep(2000);
    story = 2;
  } else if (choice == "d" && dist == 115 && story == 2) {
    print("\nYou're climbing down the stairs to the first floor...\n", 50);
    funcs::msleep(2000);
    story = 1;
  } else if (choice == "a" && dist == 125 && story == 2) {
    print("\nYou're climbing up the stairs to the third floor...\n", 50);
    funcs::msleep(2000);
    story = 3;
  } else if (choice == "d" && dist == 125 && story == 3) {
    print("\nYou're climbing down the stairs to the second floor...\n", 50);
    funcs::msleep(2000);
    story = 2;
  } else {
    print("Invalid input.", 50);
    cin.clear();
    cin.ignore();
    funcs::msleep(400);
    HUD();
  }
  HUD();
}

void BrewerNPC() {
  UI();
  if (!has_the_player_encountered_and_talked_to_the_first_villager_yet_or_not) {
    print("\nYou enter a dusty house", 60);
    print("\n\n[?]: Woah wow stop right there!\n", 100);
    funcs::msleep(750);
    print("[?]: What do you think you're doing here?\n", 100);
    funcs::msleep(750);
    cout << "[" << name;
    print("]: I intend no harm, my sword only cuts beasts.\n", 100);
    funcs::msleep(750);
    print("[?]: If so....you might be interested in some of my wares.\n", 100);
    funcs::msleep(750);
    cout << "[" << name;
    print("]: So you sell stuff, what do you sell?\n", 100);
    funcs::msleep(750);
    print("[Goblin Brewer]: *Grunts* ", 150);
    funcs::msleep(500);
    print("I...the Goblin Brewer, am the best potion maker around\n", 100);
    funcs::msleep(750);
    print("[Goblin Brewer]: But hey, I'm not selling a thing for free mehehehe "
          "*Laughs*\n",
          90);
    print("[Goblin Brewer]: You pay me money, you get what you want\n", 100);
    funcs::msleep(750);
    print("\n[Goblin Brewer]: Come back later, I'll get my stuff to display\n",
          100);
    has_the_player_encountered_and_talked_to_the_first_villager_yet_or_not =
        true;
    dist++;
    funcs::msleep(5000);
    HUD();
  } else if (
      has_the_player_encountered_and_talked_to_the_first_villager_yet_or_not) {
    print("\n[Goblin Brewer]: Welcome back brave warrior.\n", 40);
    print("[Goblin Brewer]: Buy items, or continue your journey!\n\n", 40);
    funcs::msleep(750);
    OpenMenu();
  }
}

void respawn() {
  health = 0;
  CombatHUD();
  cout.flush();
  int cha = rand() % 3;
  if (cha == 0) {
    cout << endl << name << " was put to death by a " << current_enemy << endl;
  } else if (cha == 1) {
    cout << endl << name << " got killed by a " << current_enemy << endl;
  } else {
    cout << endl << current_enemy << " ended " << name << "'s day" << endl;
  }
  funcs::msleep(2000);
  XP = 0;
  print("Respawning", 80);
  for (int i = 0; i < 10; i++) {
    cout.flush();
    cout << ".";
    funcs::msleep(175);
  }
  if (has_tamed_the_horse) {
    dist = 43;
  } else {
    dist = 0;
  }
  funcs::msleep(2000);
  cout.clear();
  cout.flush();
  funcs::clearTerminal();
  health = 10;
  free_potion = true;
  HUD();
}

void Swordsmith() {
  UI();
  if (!has_the_player_encountered_and_talked_to_the_third_villager_yet_or_not) {
    print("\n[Swordsmith]: Hello there warrior!", 100);
    print("\n[Swordsmith]: I know you've been looking for me.", 100);
    print(
        "\n[Swordsmith]: Everybody does, but who wields a blade worth molding?",
        100);
    cout << "\n[" << name << "]: ";
    print("Look at my sword big guy, I'll give you money for forging it!", 100);
    print("\n[Swordsmith]: Huh money? Gaha! Now were talking", 100);
    funcs::msleep(3000);
    has_the_player_encountered_and_talked_to_the_third_villager_yet_or_not =
        true;
  }
  if (has_the_player_encountered_and_talked_to_the_third_villager_yet_or_not)
    ;
  {
    print(
        "\n[Swordsmith]: I can reforge your blade if you have enough money.\n",
        50);
    funcs::msleep(750);
    OpenMenu();
  }
}

void OpenMenu() {
  string choice;
  UI();
  print("\n1) Open Shop\n2) Exit shop\n--> ", 30);
  cin >> choice;
  if (choice == "1") {
    funcs::msleep(750);
    UI();
    OpenShop();
  } else if (choice == "2") {
    if (dist == 18) {
      good_bye_message = "\n[Goblin Brewer]: Good Byeeee!";
    } else if (dist == 35) {
      good_bye_message = "\n[Swordsmith]: Good hunting!";
    }
    print(good_bye_message, 70);
    funcs::msleep(750);
    dist++;
    HUD();
  } else {
    cin.clear();
    cin.ignore();
    print("Invalid choice.", 40);
    funcs::msleep(750);
    UI();
    OpenMenu();
  }
}

void OpenShop() {
  UI();
  if (dist == 18) {
    print("\n[Goblin Brewer]: Here's what I currently have:\n\n", 40);
    string choice = "";
    print("1) Healing Potion (60 Zyniolax)\n2) Zyniolax Charm (120 "
          "Zyniolax)\n3) Exit\n--> ",
          30);
    cin >> choice;
    if (choice == "1") {
      if (money >= 60) {
        print("You successfully purchased one 'Healing Potion'\n", 50);
        healing_potions += 1;
        money -= 60;
        funcs::msleep(750);
        print("[Goblin Brewer]: Thanks for your money!", 70);
        funcs::msleep(1750);
        OpenShop();
      } else {
        print("[Goblin Brewer]: Sorry but you need more money!", 70);
        funcs::msleep(1750);
        OpenShop();
      }
    } else if (choice == "2") {
      if (!has_bought_first_charm) {
        if (money >= 120) {
          print("You successfully purchased the 'Zyniolax Charm'\n", 50);
          print("[Goblin Brewer]: Now you may profit more after defeating "
                "foes.\n",
                150);
          funcs::msleep(750);
          money -= 120;
          has_bought_first_charm = true;
          money_charm = 1.34;
          print("[Goblin Brewer]: Thanks for your money!", 70);
          funcs::msleep(750);
          OpenShop();
        } else {
          print("[Goblin Brewer]: Sorry but you need more money!", 70);
          funcs::msleep(1750);
          OpenShop();
        }
      } else {
        print("[Goblin Brewer]: You already own this charm.", 50);
        funcs::msleep(750);
        OpenShop();
      }
    } else if (choice == "3") {
      OpenMenu();
    } else {
      print("Invalid option. Try again", 40);
      choice.erase();
      funcs::msleep(750);
      OpenShop();
    }
  } else if (dist == 35) {
    string choice = "";
    print("\n[Swordsmith]: Upgrade your weapon or exit:\n\n", 30);
    print("1) Upgarde sword ", 30);
    cout << "(" << sword_upgrade_cost << " Zyniolax)";
    print("\n2) Exit\n--> ", 30);
    cin >> choice;
    if (choice == "1") {
      if (money >= sword_upgrade_cost && can_upgrade_sword) {
        print("[Swordsmith]: As you wish then. I'll get to work. ", 50);
        funcs::msleep(750);
        print("\n*Banging noises\a*\n", 50);
        funcs::msleep(750);
        cout << "\a";
        funcs::msleep(1400);
        cout << "\a";
        funcs::msleep(1000);
        cout << "\a";
        funcs::msleep(2000);
        print("[Swordsmith]: Alright, I'm done. \nNow your sword is a lot "
              "sharper.\n",
              60);
        money -= sword_upgrade_cost;
        sword_upgrade += 0.15; // 15% more dmg each upgrade
        sword_upgrade_cost += 150;
        if (sword_upgrade >= 1.45) {
          can_upgrade_sword = false;
          print("\n[Swordsmith]: By laws of this Kingdom, you can upgrade your "
                "blade no further. \n",
                100);
          funcs::msleep(2000);
          OpenMenu();
        }
        funcs::msleep(2000);
        OpenMenu();
      } else if (!can_upgrade_sword) {
        print("\n[Swordsmith]: You were prohibited from upgrading that sword, "
              "by law of this Kingdom.\nNow get out!!\n",
              30);
        funcs::msleep(3000);
        HUD();
      } else if (money < sword_upgrade_cost && can_upgrade_sword) {
        print("\n[Swordsmith]: You do not have enough money.\n", 30);
        funcs::msleep(750);
        OpenMenu();
      }
    } else if (choice == "2") {
      OpenMenu();
    } else {
      print("Invalid option. Try again", 40);
      choice.erase();
      funcs::msleep(750);
      OpenShop();
    }
  }
}

void meetOldMan() {
  UI();
  print("\n[Old Man]: Beware of the monsters beyond this area, "
        "adventurer!\nThey don't hit for nothing!!",
        70);
  has_the_player_encountered_and_talked_to_the_second_villager_yet_or_not =
      true;
  dist++;
  funcs::msleep(3500);
  funcs::clearTerminal();
}

void meetAcidWatcher() {
  UI();
  print("\n[Acid Watcher]: O' visitors, enter the Acid City in peace,", 70);
  print("\n[Acid Watcher]: O' warriors, shows us if you're truly fierce.", 70);
  print("\n[Acid Watcher]: And get ready for a battle as you've never seen.",
        70);
  print("\n[Acid Watcher]: A powerful Guard is the one you will face.", 70);
  print("\n[Acid Watcher]: For now you can return on your trace.", 70);
  funcs::msleep(5000);
  has_met_acid_watcher = true;
  HUD();
}

void meetTraitor() {
  UI();
  print("\n[Traitor]: Pssst, hey!", 60);
  print("\n[Traitor]: You'll need this *wink*", 60);
  print("\nYou received a 'Healing Potion' from the Traitor.", 60);
  healing_potions++;
  free_potion = false;
  funcs::msleep(3000);
  HUD();
}

void Shaman() {
  UI();
  print("\n\n[Acid Shaman]: What are you looking for warrior?", 60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: Perhaps a way to get into that castle?", 60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: You're not allowed to get in there.", 60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: But let me tell you something...", 60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: I was experimenting with some old recipes", 60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: And I think I crafted a powerful magical spell", 60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: Maybe you could try it? But I'm not sure of the side "
        "effects...",
        60);
  funcs::msleep(2000);
  cout << "\n[" << name << "]: ";
  print("I will risk it, give me what you have and we'll see what happens.",
        60);
  funcs::msleep(750);
  print("\n[Acid Shaman]: Here goes nothing...", 50);
  funcs::msleep(3000);
  UI();
  print("\nYou unlocked a new ability: *Energy Burst*", 70);
  print("\nYou can use this spell on your enemies whenever your Adrenaline is "
        "15 or higher.",
        60);
  has_the_player_encountered_and_talked_to_the_fourth_villager_yet_or_not =
      true;
  funcs::msleep(5000);
  UI();
  print("\nTip: you gain Adrenaline after striking foes.\n", 60);
  funcs::msleep(750);
  Moving();
}

void CityGuardHUD() {
  funcs::clearTerminal();
  current_enemy = "CITY GUARDIAN";
  cout << "**************** BOSS FIGHT ****************" << endl;
  cout << left << setw(18) << name << "  VS " << current_enemy << endl;
  cout << left << setw(6) << "Health: " << left << setw(12) << health
       << "|  Boss Health: " << enemy_hp << endl;
  cout << "********************************************" << endl;
}

void CityGuard() {
  CityGuardHUD();
  int player_dmg =
      (((rand() % 10) + 5) + ((float(level * 7) / 2) - 6) * sword_upgrade);
  int rando = rand() % 2;
  if (rando == 0) {
    enemy_dmg = player_dmg - (player_dmg * 0.1);
  } else {
    enemy_dmg = player_dmg + (player_dmg * 0.1);
  }
  if (health > 0 && enemy_hp > 0) {
    cout << "\nA)ttack \nD)efend\n";

    if (healing_potions >= 1) {
      cout << "H)ealing potion (" << healing_potions << ")\n";
    }
    if (enemy_hp < player_dmg) {
      cout.clear();
      cout.flush();
      CityGuardHUD();
      funcs::msleep(1200);
      cout << endl;
      funcs::printCentered("YOU WON!");
      print("\n\n[City Guardian]: *GAAAAAARHHH*", 90);
      funcs::msleep(750);
      print("\n[City Guardian]: ENOUGH!", 90);
      funcs::msleep(750);
      print("\n[City Guardian]: You proved yourself in combat, ", 100);
      funcs::msleep(750);
      print("\n[City Guardian]: Thereby I grant you access to our City.", 100);
      funcs::msleep(5000);
      has_city_access = true;
      HUD();
    }
    string choice;
    cin >> choice;
    if (choice == "a") { // Attacking
      print("Attacking...", 40);
      cout << "You dealt " << player_dmg << " damage to the " << current_enemy
           << endl;
      enemy_hp -= player_dmg;
      funcs::msleep(750);
      if (enemy_hp > 0) {
        cout << "\nThe " << current_enemy;
        print(" attacked you and dealt ", 40);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(1500);
        CityGuard();
      }
      if (health < 1) {
        health = 0;
        CityGuardHUD();
        cout.flush();
        int chan = rand() % 3;
        if (chan == 0) {
          cout << endl
               << name << " was smashed to death by the City Guardian." << endl;
        } else if (chan == 1) {
          cout << endl
               << name << " was brutally massacred by the City Guardian."
               << endl;
        } else {
          cout << endl
               << "The City Guardian wiped " << name << " against the floor."
               << endl;
        }
        funcs::msleep(3000);
        XP = 0;
        print("Respawning", 80);
        for (int i = 0; i < 10; i++) {
          cout.flush();
          cout << ".";
          funcs::msleep(175);
        }
        if (has_tamed_the_horse) {
          dist = 43;
        } else {
          dist = 0;
        }
        funcs::msleep(2000);
        cout.clear();
        cout.flush();
        funcs::clearTerminal();
        health = 10;
        free_potion = true;
        HUD();
      }
      funcs::msleep(1000);
      CityGuard();
    } else if (choice == "d") { // Defending
      print("Blocking the attack...", 40);
      int c = (rand() % 100) + 1;
      if (c <= 60) // 60% chance of blocking
      {
        heal = ceil((10 + ((level * 5)))); // awesome equation i know
        if (health + heal <= max_health) {
          print("You blocked the incoming attack and managed to heal by ", 30);
          cout << heal << endl;
          health += heal;
          funcs::msleep(500);
          CityGuard();
        } else {
          health = max_health;
          print("You blocked the incoming attack and fully healed.\n", 30);
          funcs::msleep(500);
          CityGuard();
        }
      } else {
        print("You failed to block the attack and the ", 30);
        cout << current_enemy;
        print(" managed to deal ", 30);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(700);
        if (health <= 0) {
          respawn();
        }
        CityGuard();
      }
    } else if (healing_potions >= 1 && choice == "h") {
      if (health == max_health) {
        print("Your health is already at max.", 50);
        funcs::msleep(750);
        CityGuard();
      } else {
        healing_potions -= 1;
        health = max_health;
        print("You used a healing potion. You fully healed.\n", 40);
        funcs::msleep(1500);
        cin.clear();
        CityGuard();
      }
    } else {
      print("Invalid input! try again.", 30);
      funcs::msleep(750);
      CityGuard();
    }
  }
}

void Citizen() {
  UI();
  print("\n\n[Acid Citizen 1]: Have you heard of that warrior that beat the "
        "City Guardian?",
        60);
  funcs::msleep(750);
  print("\n\n[Acid Citizen 2]: Yes what a battle it was, but do you think "
        "they'd make it into the castle?",
        60);
  funcs::msleep(750);
  print("\n\n[Acid Citizen 1]: To make it in they must beat the Acid Golem.",
        60);
  funcs::msleep(750);
  print("\n\n[Acid Citizen 2]: No way right?", 60);
  funcs::msleep(750);
  print("\n\n[Acid Citizen 1]: Yeah no way.", 60);
  funcs::msleep(4000);
  has_met_citizen = true;
  HUD();
}

void GolemHUD() {
  funcs::clearTerminal();
  current_enemy = "ACID GOLEM";
  cout << "**************** BOSS FIGHT ****************" << endl;
  cout << left << setw(18) << name << "  VS " << current_enemy << endl;
  cout << left << setw(6) << "Health: " << left << setw(12) << health
       << "|  Boss Health: " << enemy_hp << endl;
  cout << "Adrenaline: " << setw(8) << adrenaline << "|" << endl;
  cout << "********************************************" << endl;
}

void Golem() {
  GolemHUD();
  int player_dmg =
      (((rand() % 10) + 5) + ((float(level * 7) / 2) - 6) * sword_upgrade);
  int rando = rand() % 2;
  if (rando == 0) {
    enemy_dmg = abs(player_dmg - (rand() % 20));
  } else {
    enemy_dmg = abs(player_dmg - (rand() % 40));
  }
  if (health > 0 && enemy_hp > 0) {
    cout << "\nA)ttack \nD)efend\n";

    if (healing_potions >= 1) {
      cout << "H)ealing potion (" << healing_potions << ")\n";
    }
    if (adrenaline >= 15) {
      cout << "U)se spell\n";
    }
    cout << "--> ";

    string choice;
    cin >> choice;
    choice[0] = tolower(choice[0]);
    if (choice == "a") { // Attacking
      print("Attacking...", 40);
      if (adrenaline <= 26) {
        int randi = (rand() % 3) + 2;
        adrenaline += randi;
      } else {
        adrenaline = 30;
      }
      cout << "You dealt " << player_dmg << " damage to the " << current_enemy
           << endl;
      enemy_hp -= player_dmg;
      funcs::msleep(750);
      if (enemy_hp > 0) {
        cout << "\nThe " << current_enemy;
        print(" attacked you and dealt ", 40);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(1500);
        Golem();
      }
      if (health < 1) {
        health = 0;
        GolemHUD();
        cout.flush();
        int chan = rand() % 3;
        if (chan == 0) {
          cout << endl << name << " was smashed to death by the Golem." << endl;
        } else if (chan == 1) {
          cout << endl
               << name << " was brutally massacred by the Golem." << endl;
        } else {
          cout << endl
               << "The Golem wiped " << name << " against the floor." << endl;
        }
        funcs::msleep(3000);
        XP = 0;
        print("Respawning", 80);
        for (int i = 0; i < 10; i++) {
          cout.flush();
          cout << ".";
          funcs::msleep(175);
        }
        if (has_tamed_the_horse) {
          dist = 43;
        } else {
          dist = 0;
        }
        funcs::msleep(2000);
        cout.clear();
        cout.flush();
        funcs::clearTerminal();
        health = 10;
        free_potion = true;
        HUD();
      }
      funcs::msleep(1000);
      Golem();
    } else if (choice == "d") { // Defending
      print("Blocking the attack...", 40);
      int c = (rand() % 100) + 1;
      if (c <= 60) // 60% chance of blocking
      {
        heal = ceil((10 + ((level * 5)))); // awesome equation i know
        if (health + heal <= max_health) {
          print("You blocked the incoming attack and managed to heal by ", 30);
          cout << heal << endl;
          health += heal;
          funcs::msleep(500);
          Golem();
        } else {
          health = max_health;
          print("You blocked the incoming attack and fully healed.\n", 30);
          funcs::msleep(500);
          Golem();
        }
      } else {
        print("You failed to block the attack and the ", 30);
        cout << current_enemy;
        print(" managed to deal ", 30);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(700);
        Golem();
      }
      if (health < 1) {
        health = 0;
        GolemHUD();
        cout.flush();
        int chan = rand() % 3;
        if (chan == 0) {
          cout << endl << name << " was smashed to death by the Golem." << endl;
        } else if (chan == 1) {
          cout << endl
               << name << " was brutally massacred by the Golem." << endl;
        } else {
          cout << endl
               << "The Golem wiped " << name << " against the door." << endl;
        }
        funcs::msleep(3000);
        XP = 0;
        print("Respawning", 80);
        for (int i = 0; i < 10; i++) {
          cout.flush();
          cout << ".";
          funcs::msleep(175);
        }
        if (has_tamed_the_horse) {
          dist = 43;
        } else {
          dist = 0;
        }
        funcs::msleep(2000);
        cout.clear();
        cout.flush();
        funcs::clearTerminal();
        health = 10;
        free_potion = true;
        HUD();
      }
    } else if (choice == "h" && healing_potions >= 1) {
      if (health == max_health) {
        print("Your health is already at max.", 50);
        funcs::msleep(750);
        Golem();
      } else {
        healing_potions -= 1;
        health = max_health;
        print("You used a healing potion. You fully healed.\n", 40);
        funcs::msleep(1500);
        cin.clear();
        Golem();
      }
    } else if (choice == "u" && adrenaline >= 15) {
      print("You used an Energy Burst to deal ", 30);
      cout << ceil(player_dmg * 2.5) << " damage to the " << current_enemy
           << endl;
      adrenaline -= 15;
      enemy_hp -= ceil(player_dmg * 2.5);
      Attacking();
    } else {
      print("Invalid input! try again.", 30);
      funcs::msleep(750);
      Golem();
    }
  }
  if (enemy_hp <= 0) {
    enemy_hp = 0;
    cout.clear();
    cout.flush();
    GolemHUD();
    funcs::msleep(1200);
    cout << endl;
    funcs::printCentered("YOU WON!");
    funcs::msleep(2000);
    print("\n\n[ACID GOLEM]: powerful warrior, please don't harm the Queen",
          80);
    funcs::msleep(1500);
    print("\n*Dies*", 100);
    has_defeated_golem = true;
    funcs::msleep(2000);
    UI();
    print("\nThe gate of the castle opens...", 80);
    funcs::msleep(5000);
    HUD();
  }
}

void FindHorse() {
  string choice = "";
  UI();
  print("\nWhat do you do:\n\n1) Attempt to tame it!\n2) Leave it alone.\n--> ",
        13);
  cin >> choice;
  if (choice == "1") {
    int chance = (rand() % 100) + 1;
    if (chance >= 8) {
      int message = (rand() % 5) + 1;
      if (message == 1) {
        print("The horse denies you.\n", 40);
        funcs::msleep(750);
        FindHorse();
      } else if (message == 2) {
        print("You slipped while mounting the horse.\n", 40);
        funcs::msleep(750);
        FindHorse();
      } else if (message == 3) {
        print("The horse kicked you as you came.\n", 40);
        funcs::msleep(750);
        FindHorse();
      } else if (message == 4) {
        print("You trip in a bush.\n", 40);
        funcs::msleep(750);
        FindHorse();
      } else {
        print("You scared the horse!\n", 40);
        funcs::msleep(750);
        FindHorse();
      }
    } else {
      print("\aYou successfully \atamed the Horse.\a\n", 100);
      print("Now you may fast travel to places you've been to!\n", 100);
      print("* This area has been assigned as your Home point *\n", 60);
      print("* If you die you respawn here *", 60);
      has_tamed_the_horse = true;
      funcs::msleep(5000);
      HUD();
    }
  } else if (choice == "2") {
    print("You continue on your way...\n", 40);
    dist++;
    HUD();
  } else {
    print("Invalid input!", 30);
    FindHorse();
  }
}

void Queen() {
  if (!has_encountered_queen) {
    UI();
    print("\n[Queen]: Who are you warrior?\n", 50);
    funcs::msleep(2000);
    cout << "\n[" << name << "]:";
    print(" I've come here to end you...and become the new King\n", 50);
    funcs::msleep(2000);
    print("\n[Queen]: Ohhh you little cute guy, I bet you wish you could\n",
          50);
    funcs::msleep(2000);
    cout << "\n[" << name << "]:";
    print(" You know I can, so let's make it quick!\n", 50);
    funcs::msleep(2000);
    print("\n[Queen]: I will make you regret challenging me...\n", 50);
    funcs::msleep(2000);
    print("\nPrepare for a final battle...\n", 50);
    funcs::msleep(4000);
    has_encountered_queen = true;
    if (has_encountered_queen) {
      dist = 136;
      queen_hp =
          5200; //(max_health * 10) + ((rand() % 180) + 20); // old formula
      QueenFight();
    }
  }
  QueenFight();
}

void QueenUI() {
  funcs::clearTerminal();
  current_enemy = "Acid Queen";
  cout << "**************** BOSS FIGHT ****************" << endl;
  cout << left << setw(18) << name << "  VS " << current_enemy << endl;
  cout << left << setw(6) << "Health: " << left << setw(12) << health
       << "|  Queen Health: " << queen_hp << endl;
  cout << "Adrenaline: " << setw(8) << adrenaline << "|" << endl;
  cout << "********************************************" << endl;
}

void QueenFight() {
  QueenUI();
  int player_dmg =
      (((rand() % 10) + 5) + ((float(level * 7) / 2) - 6) * sword_upgrade);
  int rando = rand() % 2;
  if (rando == 0) {
    enemy_dmg = abs(player_dmg - (rand() % 20));
  } else {
    enemy_dmg = abs(player_dmg - (rand() % 40));
  }
  if (health > 0 && queen_hp > 0) {
    cout << "\nA)ttack \nD)efend\n";

    if (healing_potions >= 1) {
      cout << "H)ealing potion (" << healing_potions << ")\n";
    }
    if (adrenaline >= 15) {
      cout << "U)se spell\n";
    }
    cout << "--> ";

    cin.clear();
    cin.ignore();

    string choice;
    cin >> choice;
    choice = choice[0];
    choice[0] = tolower(choice[0]);
    if (choice == "a") { // Attacking
      print("Attacking...", 40);
      if (adrenaline <= 26) {
        int randi = (rand() % 3) + 2;
        adrenaline += randi;
      } else {
        adrenaline = 30;
      }
      cout << "You dealt " << player_dmg << " damage to the " << current_enemy
           << endl;
      queen_hp -= player_dmg;
      funcs::msleep(750);
      if (queen_hp > 0) {
        cout << "\nThe " << current_enemy;
        print(" attacked you and dealt ", 40);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(1500);
        QueenFight();
      }
      if (health < 1) {
        health = 0;
        QueenUI();
        cout.flush();
        int chan = rand() % 3;
        story = 1;
        killed_by_queen = true;
        if (chan == 0) {
          cout << endl
               << name << " was sentenced to death by the Queen." << endl;
        } else if (chan == 1) {
          cout << endl << name << " was destroyed by the Queen." << endl;
        } else {
          cout << endl
               << "The Queen wiped " << name << " against the door." << endl;
        }
        funcs::msleep(3000);
        XP = 0;
        print("Respawning", 80);
        for (int i = 0; i < 10; i++) {
          cout.flush();
          cout << ".";
          funcs::msleep(175);
        }
        if (has_tamed_the_horse) {
          dist = 43;
        } else {
          dist = 0;
        }
        funcs::msleep(2000);
        cout.clear();
        cout.flush();
        funcs::clearTerminal();
        health = 10;
        free_potion = true;
        HUD();
      }
      funcs::msleep(1000);
      QueenFight();
    } else if (choice == "d") { // Defending
      print("Blocking the attack...", 40);
      int c = (rand() % 100) + 1;
      if (c <= 40) // 40% chance of blocking
      {
        heal = ceil((10 + ((level * 5)))); // awesome equation i know
        if (health + heal <= max_health) {
          print("You blocked the incoming attack and managed to heal by ", 30);
          cout << heal << endl;
          health += heal;
          funcs::msleep(500);
          QueenFight();
        } else {
          health = max_health;
          print("You blocked the incoming attack and fully healed.\n", 30);
          funcs::msleep(500);
          QueenFight();
        }
      } else {
        print("You failed to block the attack and the ", 30);
        cout << current_enemy;
        print(" managed to deal ", 30);
        cout << enemy_dmg << " damage" << endl;
        health -= enemy_dmg;
        funcs::msleep(700);
        QueenFight();
      }
      if (health < 1) {
        health = 0;
        QueenUI();
        cout.flush();
        int chan = rand() % 3;
        if (chan == 0) {
          cout << endl
               << name << " was sentenced to death by the Queen." << endl;
        } else if (chan == 1) {
          cout << endl << name << " was destroyed by the Queen." << endl;
        } else {
          cout << endl
               << "The Queen wiped " << name << " against the door." << endl;
        }
        funcs::msleep(3000);
        XP = 0;
        story = 1;
        killed_by_queen = true;
        print("Respawning", 80);
        for (int i = 0; i < 10; i++) {
          cout.flush();
          cout << ".";
          funcs::msleep(175);
        }
        if (has_tamed_the_horse) {
          dist = 43;
        } else {
          dist = 0;
        }
        funcs::msleep(2000);
        cout.clear();
        cout.flush();
        funcs::clearTerminal();
        health = 10;
        free_potion = true;
        HUD();
      }
    } else if (choice == "h" && healing_potions >= 1) {
      if (health == max_health) {
        print("Your health is already at max.", 50);
        funcs::msleep(750);
        QueenFight();
      } else {
        healing_potions -= 1;
        health = max_health;
        print("You used a healing potion. You fully healed.\n", 40);
        funcs::msleep(1500);
        cin.clear();
        QueenFight();
      }
    } else if (choice == "u" && adrenaline >= 15) {
      print("You used an Energy Burst to deal ", 30);
      cout << ceil(player_dmg * 2.5) << " damage to the " << current_enemy
           << endl;
      adrenaline -= 15;
      queen_hp -= ceil(player_dmg * 2.5);
      QueenFight();
    } else {
      print("Invalid input! try again.", 30);
      funcs::msleep(750);
      QueenFight();
    }
  }
  if (queen_hp <= 0) {
    queen_hp = 0;
    cout.clear();
    cout.flush();
    QueenUI();
    funcs::msleep(1200);
    cout << endl;
    funcs::printCentered("YOU WON!");
    funcs::msleep(1500);
    print("Loading credits.....", 80);
    funcs::msleep(3000);
    has_defeated_queen = true;
    Credits();
  }
}

void MoveHorse() {
  string choice = "";
  UI();
  print("\nTravel to:\n1) Cancel\n2) The Goblin Brewer\n3) The Swordsmith\n4) "
        "Return Home",
        30);
  if (has_met_acid_watcher) {
    print("\n5) Acid City Entrance", 30);
  }
  if (has_defeated_golem) {
    print("\n6) Castle's Gate", 30);
  }
  cout << "\n--> ";
  cin >> choice;
  funcs::msleep(750);
  if (choice == "1") {
    funcs::msleep(750);
    HUD();
  } else if (choice == "2") {
    dist = 19;
    print("You're back by The Goblin Brewer.", 40);
    funcs::msleep(750);
    HUD();
  } else if (choice == "3") {
    dist = 36;
    print("You're back by The Swordsmith.", 40);
    funcs::msleep(750);
    HUD();
  } else if (choice == "4") {
    dist = 42;
    print("You're back by Home.", 40);
    funcs::msleep(750);
    HUD();
  } else if (has_met_acid_watcher && choice == "5") {
    dist = 60;
    print("You're back by the entrance of the Acid City.", 40);
    funcs::msleep(750);
    HUD();
  } else if (has_defeated_golem && choice == "6") {
    dist = 95;
    print("You're back by the gate of the Castle.", 40);
    funcs::msleep(750);
    HUD();
  } else {
    print("Invalid Input.", 30);
    funcs::msleep(750);
    MoveHorse();
  }
}
void print(string text, int cd) {
  funcs::msleep(200);
  for (int i = 0; i < text.size(); i++) {
    cout << text[i];
    funcs::msleep(cd);
    cout.flush();
  }
  funcs::msleep(100);
}

int MaxDist(int dist) {
  if (dist >= max_dist) {
    max_dist = dist;
  }
  return max_dist;
}

void Neverland() {
  cout << R"(
█████████████████████████████████████████████
██████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████
██████████▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░░░▄▄▄█████████
████████████▀▀▀▀▀░░░░░░░▄▄▄▄█████████████████
██████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████
██████████▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█████████
████████████▀▀▀░░░░░░░░░░▀▀▀█████████████████
██████████▀░░░░░░▄░░░░░▄░░░░░░███████████████
█████████░░░░░░███░░░░░███░░░░░██████████████
█████████▄░░░░░███░░░░░▀░░░░░░███████████████
███████████▄▄▄▄▄██░░░░░░░▄▄▄█████████████████
███████████████████████▀▀▀▀▀░░███████████████
████████████▀▀▀▀▀░░░░░░░░░░░▄▄███████████████
██████████░░░░░░░░▄▄▄▄▄██████████████████████
██████████▄▄░░░░░░░░░░▀▀▀▀▀▀█████████████████
█████████████████▄▄▄▄▄▄░░░░░░░███████████████
█████████████████▀▀▀▀▀▀████▄▄▄███████████████
███████████▀░░░░░░░░░░░░░░░▀▀████████████████
█████████▀░░░░░▄██░░░░░█▄▄░░░░▀██████████████
█████████░░░░░░███░░░░░██▀░░░░▄██████████████
██████████▄░░░░▀██░░░░░░░░░░▄▄███████████████
██████████████████▄▄▄▄▄▄▄████████████████████
██████████▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀███████████████
██████████░░░░░░░░░░░░░░░░░░░▄███████████████
████████████████████████▄▄░░░░▀██████████████
█████████████████████████▀░░░░░██████████████
█████████████████████████▄▄▄▄▄███████████████
██████████▀▀▀▀███████████████████▀▀▀▀▀███████
██████████░░░░▀██████████████████░░░░░███████
██████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████
██████████░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄███████
██████████░░░░███████████████████████████████
████████████▀▀▀▀▀▀▀▀███████▀▀████████████████
█████████▀░░░░░░░░░░░░██▄░░░░░███████████████
█████████░░░░░░███░░░░▀███░░░░░██████████████
██████████░░░░░▀▀▀░░░░░▀▀▀░░░░▄██████████████
██████████░░░░░░░░░░░░░░░░░▄▄▄███████████████
█████████████████████████████████████████████
██████████░░░░░░░░░░░░░░░░░░░░███████████████
█████████████████████▄▄▄▄░░░░░███████████████
█████████████████████████▀░░░░░██████████████
██████████░░░░░░░░░░░░░░░░░░░▄███████████████
██████████▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄███████████████████
███████████▀▀▀░░░░░░░░░░░▀▀▀█████████████████
█████████▀░░░░░▄▄▄▄▄▄▄▄▄░░░░░░▀██████████████
█████████░░░░░░███████████░░░░▄██████████████
██████████▀░░░░░░░░▀▀░░░░░░░░░▀▀▀▀▀▀▀▀███████
██████████▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄███████
█████████████████████████████████████████████
▀██████████████████████████████████████████▀▀
)";
}

void windowsNeverland() {
  cout << R"(
 _   _                     _                 _
| \ | | _____   _____ _ __| | __ _ _ __   __| |
|  \| |/ _ \ \ / / _ \ '__| |/ _` | '_ \ / _` |
| |\  |  __/\ V /  __/ |  | | (_| | | | | (_| |
|_| \_|\___| \_/ \___|_|  |_|\__,_|_| |_|\__,_|
	       )";
  cout << endl;
}
void Credits() {
  funcs::clearTerminal();
  funcs::msleep(1000);
  cout << endl << endl << endl;
#ifdef _WIN32
  windowsNeverland();
#else
  Neverland();
#endif
  cout << endl << endl;
  funcs::printCentered("CREDITS\n");
  cout << endl << endl;
  funcs::msleep(2000);
  funcs::printCentered("Directed By");
  funcs::printCentered("@HassanIQ777");
  cout << endl << endl;
  funcs::msleep(2000);
  funcs::printCentered("Coding By");
  funcs::printCentered("@HassanIQ777");
  cout << endl << endl;
  funcs::msleep(2000);
  funcs::printCentered("Game Design");
  funcs::printCentered("@HassanIQ777");
  cout << endl << endl;
  funcs::msleep(2000);
  funcs::printCentered("Character Design");
  funcs::printCentered("@HassanIQ777");
  cout << endl << endl;
  funcs::msleep(2000);
  funcs::printCentered("Game Idea");
  funcs::printCentered("@HassanIQ777");
  cout << endl << endl;
  funcs::msleep(2000);
  funcs::printCentered("Special Thanks");
  funcs::printCentered("@Permiss1on_Denied");
  cout << endl << endl;
  funcs::msleep(3000);
  print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", 100);
  funcs::msleep(2000);
  print("You had ventured out, met people, defeated monsters, and become a "
        "king for this kingdom.\n",
        80);
  funcs::msleep(3000);
  if (has_obtained_rancid_egg) {
    print("\nThe Rancid Egg starts hatching...\n", 50);
    funcs::msleep(3000);
    print("A baby Primal Aspid comes from it!\n", 50);
    funcs::msleep(3000);
    print("It now thinks you're its mom...\n", 50);
    funcs::msleep(3000);
  }
  print("\nYou had beaten Neverland!\n", 80);
  funcs::msleep(750);
  print("Thanks for playing.\n", 80);
  funcs::msleep(750);
  print("You may exit the game now.", 80);
  while (true) {
  }
}

// Game by @HassanIQ777

/*
LATEST FEATURES:
1. Smither NPC
2. even more error handling
3. completely balanced money
4. HORSEEEE :}
5. removed unnecessary functions
6. text aligned UI and CombatHUD
7. weapon upgrades
8. money charm :)
9. starting message is now centered across all devices
10.support for both Windows and Linux :)
11.Healing updated and upgraded!
12.Balanced the weapon upgrades
13.Visited places have less chance of encounters
14.Faster menus where they needed to be
15.You can respawn now
16.Acid Watcher
17.Traitor (gives a free potion)
18.FIRST BOSS FIGHT
19.Acid City :)
20.Acid Shaman NPC
21.Energy Burst Spell
22.Golem boss fight
23.Castle with unique mobs
24.Many bug fixes
25.Updated the menu of the horse
26.Crystalized goop
27.Rancid Egg
28.The queen
29.Credits

UPCOMING FEATURES:
1. Achievements Menu and implementation
*/