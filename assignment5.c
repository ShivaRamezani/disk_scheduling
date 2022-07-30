#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Declare global variables, including dynamic array to store sequence of traversed tracks
int* sequence = NULL;
int sequenceSize;
/*********************************************************/
void optionOne() {
// prompt for the sequence size
printf("Enter size of sequence: ");
scanf("%d", &sequenceSize);

// allocate memory for the sequence of traversed tracks
sequence = (int*)malloc(sequenceSize * sizeof(int));

// prompt for starting track, store in index 0
printf("Enter starting track: ");
scanf("%d", &sequence[0]);

// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
printf("Enter sequence of tracks to seek: ");
for(int i =1; i <= sequenceSize-1; i++) {
   scanf("%d", &sequence[i]);
}

return;
} // "OPTION #1"
/*********************************************************/
void optionTwo() {
// declare local variables

int totalDistance = sequence[0];
// calculate total distance of traversed tracks
printf("Traversed sequence: \n");
printf("%d ", sequence[0]);
for(int i = 1; i <= sequenceSize-1; i++) {
   totalDistance += abs(sequence[i] - sequence[i-1]);
   // print sequence of traversal
   printf("%d ", sequence[i]);
   }
// print total distance of tracks traversed
printf("\n The distance of the traversed track is: \n");
printf("%d ", totalDistance);
return;
} // "OPTION #2"
/*********************************************************/
void optionThree() {
// declare local variables
int currentTrack = sequence[0];
int totalDistance = sequence[0];
int numDone = 1;
int shortest = 0;
int shortestIndex = 0;
int* checked = (int*)calloc(sequenceSize,sizeof(int));

// initialize current track and distance traversed to starting track

// begin printing sequence of traversal
printf("Traversed sequence: \n");
printf("%d ", sequence[0]);
// until every track is traversed
while(numDone < sequenceSize) {
// initilize shortest distance to INT_MAX
   shortest = INT_MAX;
// for each track in sequence
// if not already traversed
for(int i = 1; i <= sequenceSize - 1; i++) {
//if distance to traverse is shorter than current shortest distance
   if(checked[i] == 0) {
      if(abs(sequence[i] - currentTrack) < shortest) {
         shortest = abs(sequence[i] - currentTrack);
         shortestIndex = i;
        }
       }
      }
      
    checked[shortestIndex] = 1;
    numDone++;
    totalDistance += shortest;
    
    currentTrack = sequence[shortestIndex];
    printf("%d ", sequence[shortestIndex]);
    }
    printf("\n The distance of the traversed track is: \n");
    printf("%d ", totalDistance);
// set current shortest distance and index of the track w/ shortest distance

// set "done" value for track w/shortest distance to 1 (mark as traversed)
// increment number of tracks that have been traversed
// update total distance traversed
//set current track to new position, print position
// print total distance traversed
return;
} // "OPTION #3"
/*********************************************************/
void optionFour() {
// declare local variables
int direction;
//prompt for initial direction (0=descreasing, 1=increasing)
printf("Enter initial direction: (0=decreasing, 1 increasing): ");
scanf("%d", &direction);

int currentTrack = sequence[0];
int totalDistance = sequence[0];
int numDone = 1;
int shortest = 0;
int shortestIndex = 0;
int* checked = (int*)calloc(sequenceSize,sizeof(int));
int atLeastOne = 0;
printf("Traversed sequence: \n");
printf("%d ", sequence[0]);
// until every track is traversed
while(numDone < sequenceSize) {
atLeastOne = 0;
// initilize shortest distance to INT_MAX
shortest = INT_MAX;
// for each track in sequence
// if not already traversed
for(int i = 1; i <= sequenceSize - 1; i++) {
//if distance to traverse is shorter than current shortest distance
   if(checked[i] == 0) {
      if(abs(sequence[i] - currentTrack) < shortest) {
         if(((sequence[i] - currentTrack > 0) && (direction == 1))||((sequence[i] - currentTrack < 0) && (direction == 0))) {
            shortest = abs(sequence[i] - currentTrack);
            shortestIndex = i;
            atLeastOne = 1;
        }
       }
      }
     }
     
    if(atLeastOne == 1) { 
    checked[shortestIndex] = 1;
    numDone++;
    totalDistance += shortest;
    
    currentTrack = sequence[shortestIndex];
    printf("%d ", sequence[shortestIndex]);
    }
    else {
    direction = 1 - direction;
    }
  }
  printf("\n The distance is: \n");
  printf("%d ", totalDistance);
  
return;
} 
/*********************************************************/
void optionFive() {

int currentTrack = sequence[0];
int totalDistance = sequence[0];
int numDone = 1;
int shortest = 0;
int shortestIndex = 0;
int* checked = (int*)calloc(sequenceSize,sizeof(int));
int atLeastOne = 0;
int endReached = 0;
printf("Traversed sequence: \n");
printf("%d ", sequence[0]);
// until every track is traversed
while(numDone < sequenceSize) {
atLeastOne = 0;
// initilize shortest distance to INT_MAX
shortest = INT_MAX;

for(int i = 1; i <= sequenceSize - 1; i++) {
//if distance to traverse is shorter than current shortest distance
   if(checked[i] == 0) {
      if(abs(sequence[i] - currentTrack) < shortest) {
         if((sequence[i] - currentTrack) > 0) {
            shortest = (sequence[i] - currentTrack);
            shortestIndex = i;
            atLeastOne = 1;
        }
       }
      }
     }
     
    if(atLeastOne == 1) {
      if(endReached == 0) {
         totalDistance += shortest;
       }
       else {
         totalDistance -= shortest; 
         endReached = 0;
       }
       
    checked[shortestIndex] = 1;
    numDone++;
    
    currentTrack = sequence[shortestIndex];
    printf("%d ", sequence[shortestIndex]);
    }
    else {
      totalDistance += currentTrack;
      currentTrack = 0;
      endReached = 1;
    }
  }
  printf("\n The total distance: \n");
  printf("%d ", totalDistance);

return;
} 
/***************************************************************/
void optionSix() {
if(sequence != NULL) {
   free(sequence);
   }
return;
}
/***************************************************************/
int main() {


  int answer = 0;
  
  while (answer != 6) {
     printf("\nchoose an option: \n");
     printf("--------------------------------\n");
     printf("1) Enter parameters\n");
     printf("2) Calculate distance to traverse tracks using FIFO \n");
     printf("3) Calculate distance to traverse tracks using SSTF \n");
     printf("4) Calculate distance to traverse tracks using Scan \n");
     printf("5) Calculate distance to traverse tracks using C-Scan \n");
     printf("6) Quit program\n");


     printf("\nEnter selection: ");
     scanf("%d", &answer);
    
     switch(answer) {
        case 1: optionOne();
        break;
        case 2: optionTwo();
        break;
        case 3: optionThree(); 
        break;
        case 4: optionFour(); 
        break;
        case 5: optionFive(); 
        break;
        case 6: optionSix(); 
        break;
        default: 
        printf("Invalid option!\n"); 
        break;
     }    
   }    
  return 1;
}

