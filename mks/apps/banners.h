#ifndef BANNER_H
#define BANNER_H

#include "../stdout.h"

void v1_banner() {
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    WELCOME TO MKS - THE MINIMAL KERNEL SYSTEM    |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("|    CREATED BY M.V.HARISH KUMAR                   |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("  ", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("|    ENTER ", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
      cprint("<HELP> ", VGA_COLOUR_RED, VGA_COLOUR_BLUE);
      cprintln("for more information             |", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
    cprintln("====================================================", VGA_COLOUR_BROWN, VGA_COLOUR_BLUE);
}

void v2_banner() {
    print("                           ");
  cprint(",---------------------------,\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("|  /---------------------\\  |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("                       ", VGA_COLOUR_WHITE, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("       WELCOME TO      ", VGA_COLOUR_BLACK, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("        MKS v2.0       ", VGA_COLOUR_BLACK, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("   THE MINIMAL KERNEL  ", VGA_COLOUR_BLACK, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("        SYSTEM         ", VGA_COLOUR_BLACK, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("                       ", VGA_COLOUR_BLACK, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("| |", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("  USER@MKS $>>>        ", VGA_COLOUR_BLACK, VGA_COLOUR_WHITE);
  cprint("| |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("|  \\_____________________/  |\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                           ");
  cprint("|___________________________|\n", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  print("                         ");
  cprint(",---", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  cprint("\\_____     ", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("[]", VGA_COLOUR_RED, VGA_COLOUR_BLACK);
  cprint("     _______/", VGA_COLOUR_WHITE, VGA_COLOUR_BLACK);
  cprint("------,\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  print("                       ");
  cprint("/         /______________\\           /|\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  print("                     ");
  cprint("/___________________________________ /  |\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  print("                     ");
  cprint("|                                   |   |\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  print("                     ");
  cprint("|  _ _ _                 [-------]  |   |\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  print("                     ");
  cprint("|  ", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  cprint("o ", VGA_COLOUR_BLUE, VGA_COLOUR_LIGHT_GREY);
  cprint("o ", VGA_COLOUR_GREEN, VGA_COLOUR_LIGHT_GREY);
  cprint("o                 ", VGA_COLOUR_RED, VGA_COLOUR_LIGHT_GREY);
  cprint("[-------]  |  /\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);
  print("                     ");
  cprint("|__________________________________ |/\n", VGA_COLOUR_WHITE, VGA_COLOUR_LIGHT_GREY);

}

#endif