
#include <stdio.h>
#include <ctype.h>
#include "D:\group8_function\zodiac.c"

int main()
{

  char name[80];
  int bm, bd;
  int tryAgain = 0;
  int confirm;

  // Get user name
  do
  {
    printf("Please enter your name: ");
    if (scanf("%s", name) != 1)
    {
      printf("Error: Invalid input!\n");
      return 1;
    }

    // Get birth month
    do
    {
      printf("Input Birth Month in Number Form: ");
      if (scanf("%d", &bm) != 1 || bm < 1 || bm > 12)
      {
        printf("Error: Invalid birth month! Must be between 1 and 12.\n");
      }
    } while (bm < 1 || bm > 12);

    // Get birth date
    do
    {
      printf("Input Birth Date in Number Form: ");
      if (scanf("%d", &bd) != 1)
      {
        printf("Error: Invalid input!\n");
      }
      if ((bm == 2 && bd > 29) ||
          (bm == 4 && bd > 30) ||
          (bm == 6 && bd > 30) ||
          (bm == 9 && bd > 30) ||
          (bm == 11 && bd > 30) ||
          (bd < 1 || bd > 31))
      {
        printf("Error: Invalid birth date for the given month!\n");
      }
    } while (bd < 1 || bd > 31 || bm == 2 && bd > 28 || bm == 4 && bd > 30 || bm == 6 && bd > 30 || bm == 9 && bd > 30 || bm == 11 && bd > 30);

    printf("%s's Zodiac Sign: ", name);
    zodiac_sign(bm, bd);

    do
    {
      printf("Do you want to try again? 1- Yes | 0 - No: ");
      scanf("%d", &tryAgain);
      if (tryAgain == 0)
      {
        do
        {
          printf("Terminate? This can't be undone. 1- Yes | 0 - No: ");
          scanf("%d", &confirm);
        } while (confirm > 1 || confirm < 0);
      }
    } while (tryAgain > 1 || tryAgain < 0);

  } while (tryAgain == 1 || confirm == 0);

  return 0;
}
