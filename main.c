//
//  main.c
//  hwk3-4
//
//  Created by Jason Mansfield on 9/15/12.
//  Copyright (c) 2012 Jason Mansfield. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


void setRights(int oct);
void writeToFile(char * flink);
void appendToFile(char * flink);
void referenceFile(char * flink);

int main(int argc, const char * argv[])
{
  int oct = 0600;
  char *fileLink = "hwk3-4.txt";

    setRights(oct);
    writeToFile(fileLink);
    oct = 0660;
    setRights(oct); 
    appendToFile(fileLink);
    referenceFile(fileLink);
    return 0;
}


void setRights(int oct){
    int flag;
    flag = chmod ("hwk3-4.txt", oct); /* Use an octal encoding */
    if (flag == -1) perror ("hwk3-4.txt");
}
void writeToFile(char * flink){
    int file;
    file = open(flink, O_WRONLY | O_CREAT); /* Open file for writing */
    write(file,"All work and no play ", 21);
    close(file);
}
void appendToFile(char * flink){
  int file;
  file = open(flink,  O_WRONLY | O_APPEND); /* Open file for writing */
  write(file, "Makes Johnny a dull boy\n", 23);
  close(file);
}
void referenceFile(char * flink){
  FILE * pf;
  int c;
  
  pf = fopen(flink, "r");

  fseek(pf, 0L, SEEK_END);
  long sz = ftell(pf);
  fseek(pf, 10, SEEK_SET);

 while(sz != 0)
{
printf("%c",c);
c=fgetc(pf);
--sz;
printf("%ld",sz);
}
fclose(pf);
}
