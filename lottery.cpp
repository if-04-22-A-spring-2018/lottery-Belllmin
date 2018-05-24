/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			lottery.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Implementation of a library for analyzing lottery tips.
 *-----------------------------------------------------------------------------
*/
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lottery.h"

#define TIP_SIZE 6
#define UUID_LEN 40
#define MAX_TIP_LEN 17
#define MAX_LINE_LEN (UUID_LEN + 1 + MAX_TIP_LEN + 1)

static int tips[1000000][TIP_SIZE] = {0};
static int valid_tips[TIP_SIZE] = {0};
static bool is_set = false;

bool init_lottery(const char *csv_file, char csv_separator)
{
  FILE *fd = fopen(csv_file, "r");
  if(fd != NULL) //&& csv_separator != ';')   bäume text files strings
  {
    int i = 0;
    while(!feof(fd))
    {
      char string[MAX_LINE_LEN] = {0};
      fgets(string , MAX_LINE_LEN, fd);
      char delimiter[] = ",;";
      char *line[TIP_SIZE] = {0};
      char *temp;
      int j = 0;

      temp = strtok(string, delimiter);
      while(temp != NULL)
      {
        temp = strtok(NULL, delimiter);
        line[j++] = temp;
      }
      for(int j = 0; j < TIP_SIZE; j++)
      {
        if(line[j] == NULL) line[j] = "";
        tips[i][j] = atoi(line[j]);
      }
      i++;
    }
    return true;
  }
  return false;
}
bool get_tip(int tip_number, int tip[TIP_SIZE])
{
  if(tip_number >= 0 && tip_number <= 45)
  {
    for(int i = 0; i < TIP_SIZE; i++) tip[i] = tips[tip_number][i];
    return true;
  }
  return false;
}
bool set_drawing(int drawing_numbers[TIP_SIZE])
{
  is_set = true;
  for(int i = 0; i < TIP_SIZE; i++) valid_tips[i] = drawing_numbers[i];

  return false;
}
int get_tip_result(int tip_number)
{
  if(!is_set) return -1;
  if(tip_number < 0 || tip_number > 43) return -2; // out of range or it doesn't refer to a valid tip

  int drawing_numbers[TIP_SIZE] = {0};
  get_tip(tip_number, drawing_numbers);

  int cnt = 0;
  for(int i = 0; i < TIP_SIZE; i++)
    for(int j = 0; j < TIP_SIZE; j++) if(drawing_numbers[i] == valid_tips[j]) cnt++;
  return cnt;
}
int get_right_tips_count(int right_digits_count)
{
  if(!is_set) return -1;
  return 0;
}
