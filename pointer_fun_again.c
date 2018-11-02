#include <stdio.h>

struct PlayStruct{
  int int_value;
  double double_value;
  char a_string[64];
};

void print_struct(struct PlayStruct ps,struct PlayStruct *pps)
{
  printf("Values of struct ps: %d %lf %s\n",ps.int_value, ps.double_value, ps.a_string);
  printf("Values of struct pps: %d %lf %s\n",pps->int_value, pps->double_value, pps->a_string);
}
void change_struct(struct PlayStruct ps,struct PlayStruct *pps)
{
  ps.int_value = 19;
  ps.double_value = 18.5;
  ps.a_string[0] = 'S';
  ps.a_string[1] = 'B';

  pps->int_value = 20;
  pps->double_value = 20.3;
  pps->a_string[0] = 'T';
  pps->a_string[1] = 'E';
  pps->a_string[2] = 'S';
  pps->a_string[3] = 'T';

}
void print_string(char string_to_print[])
{
  printf("String to print: %s\n",string_to_print);
}
void change_string(char string1[], char *p_string)
{
  string1[2] = 'X';
  p_string[1] = '\0';
}

int main(int argc, char const *argv[]) {
  /*I assigned the values by watching what I have in struct.
  ** int, double and a char[] (string). Simple.
  */
  struct PlayStruct play_struct = {18, 17.5, "Sebastijan"};
  struct PlayStruct *play_struct_pointer = &play_struct;
  print_struct(play_struct, play_struct_pointer);
  change_struct(play_struct, play_struct_pointer);
  /*Every value I have entered is the same of the pointer (pps-> values).
  **Pointer points to the values of play_struct and also takes the values from play_struct_pointer.
  **In change struct the first 3 slots of the char changed as expected but the rest of char slots didn't change.
  ** Which completely makes sence, since I only changed the the 1st three slots anyway.
  */
  print_struct(play_struct, play_struct_pointer);
  print_string(play_struct.a_string);

  char another_string[16] = "BOGDAN";
  char *p_another_string = another_string;
  change_string(another_string, p_another_string);
  print_string(another_string);
  /* Now this is a similar situation as with change struct. Every value after 1st slot where we entered '\0' got deleted or just stopped printing.
  ** The another_string only saved it's 1st slot, the rest got cut off because the p_another_string is a pointer.
  */
  return 0;
}
