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

void createFile();
void setRights(int oct);
void writeToFile();

int main(int argc, const char * argv[])
{
  int oct = 0600;

    createFile();
    setRights(oct);
    writeToFile();
    oct = 0660;
    setRights(oct); 
    return 0;
}

void createFile(){
    
    system("touch hwk3-4.txt");
    
}
void setRights(int oct){
    int flag;
    flag = chmod ("hwk3-4.txt", oct); /* Use an octal encoding */
    if (flag == -1) perror ("hwk3-4.txt");
}
void writeToFile(){
    int file;
    file = open("hwk3-4.txt", O_WRONLY); /* Open file for writing */
    write(file,"POSIX rocks!\n", 20);
    close(file);
}
