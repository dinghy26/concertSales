// C code
// This code will compute the values of the sales ticket sales for concerts
// and sort the entries by those values
// Developer: Faculty CMIS102
// Date: Jan 31, XXXX

#include <stdio.h>

#define MAXN 100 // max characters in a group/concert name
#define MAXG  50 // max concerts/groups
#define MAXC   4 // max categories- change max to 4 Brian

char  group  [MAXG][MAXN];
int   fans   [MAXG][MAXC];
float prices [MAXC];
float sales  [MAXG];
int   count = 0;

void intro ()
{
    printf("\t\tBrian Miranda Perez\n");
    printf("\t\tThis code will compute the values of the sales\n");
    printf("\t\tsales ticket sales for concerts and\n");
    printf("\t\tsort the entries by those values\n");
    printf("\t\tCMIS 102\n");
    printf("\t\tDec 07, 2019\n");
}

void printArray () {
  printf ("%15s%5s%5s%5s%5s%10s\n", 
  "Concert", "s1", "s2", "s3","s4", "Sales"); // add S4 Brian
  for (int i = 0; i < count; i++) {
    printf ("%15s", group [i]);
    for (int j = 0; j < MAXC; j++) {
      printf ("%5d", fans[i][j]);
    } // end for each category
    printf ("%10.2f\n", sales [i]);
  } // end for each group
} // end function printArray

void computeSales () {
  for (int i = 0; i < count; i++) {
    sales [i] = 0;
    for (int j = 0; j < MAXC; j++) {
      sales [i] += prices [j] * fans [i][j];
    } // end for each category
  } // end for each group
} // end function computeSales

// ***** totalSales **** Brian Miranda
void totalSales()
{
    float tsales;
    for(int i = 0; i <= MAXC; i++){
        tsales += sales [i];

    }
printf("\n\t\tThe total sales are: $%.2f\n",tsales);

}
// ***********************************

void switchRows (int m, int n) {
  char tc;
  int  ti;
  float v;
  // printf ("Switching %d with %d\n", m, n);
  for (int i = 0; i < MAXN; i++) {
    tc = group [m][i];
    group [m][i] = group [n][i];
    group [n][i] = tc;
  } // end for each character in a group name
  for (int i = 0; i < MAXC; i++) {
    ti = fans [m][i];
    fans [m][i] = fans [n][i];
    fans [n][i] = ti;
  } // end for each fan category
  v = sales [m];
  sales [m] = sales [n];
  sales [n] = v;
} // end switch

int findMinSales (int m) {
  float min = sales [m];
  int target = m;
  for (int i = m+1; i < count; i++)
    if (sales [i] < min) {
      min = sales [i];
      target = i;
    } // end new max found
  return target;
} // end function findMinSales


void sortBySales () {
  int target;
  for (int i = 0; i < count; i++) {
    target = findMinSales (i);
    if (target > i)
      switchRows (i, target);
  } // for each concert
} // end function sortBySales

//**********sort by fans************* Brian Miranda

int minFans (int b) {
  float min = fans [b][0];
  int target = b;
  for (int i = b; i < count; i++)
    if (fans [i][0] < min) {
      min = fans [i][0];
      target = i;
    } // end new max found
  return target;
}

void sortByFans () {
  int target = 0;
  //int result;
  
  for (int i = 0; i < count; i++) {
     target = minFans(i); 
    if (target > i)
    //result = target;   
    switchRows (i,target);
    
  } 
} 
//********************************

void getData () {
  // for (int i = 0; i < MAXG; i++) sales [i] = 0;
  printf ("\nEnter ticket prices in each of %d cateogories: ", MAXC);
  for (int i = 0; i < MAXC; i++)
    scanf ("%f", &prices [i]);
  printf ("-- Enter group and fans in %d categories\n", MAXC);
  printf ("   . to finish entries:\n");
  for (int i = 0; i < MAXG; i++) {
    scanf ("%s", group[i]);
    if (group [i][0] == '.') 
      break;
    count++;
    for (int j = 0; j < MAXC; j++)
      scanf ("%d", &fans[i][j]);
  } // end for each group
} // end function getData

int main(void) {
  intro ();
  getData ();
  computeSales ();
  printArray ();
  printf ("\n --- Sorted sales ---\n");
  sortBySales ();
  printArray ();
  totalSales ();
  printf("--- sorted by fans ---\n");
  sortByFans ();
  printArray ();
  totalSales ();
  printf("\t\t ... Bye ...\n");
  return 0;
}