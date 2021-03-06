#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/mman.h>


#define SHMSZ     sizeof(char)*40
;
int  main()
{
    int shmid;
    key_t key;
    char  *s;
    char *shm;

    /*
     * We'll name our shared memory segment
     * "5678".
     */
    key = 5679;

    /*
     * Create the segment.
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    /*
     * Now we attach the segment to our data space.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     * Now put some things into the memory for the
     * other process to read.
     */
    s = shm;
    *s='1';
    scanf("%s", s);


    /*
     * Finally, we wait until the other process 
     * changes the first character of our memory
     * to '*', indicating that it has read what 
     * we put there.
     */
    while (*s != '*')
        system("sleep 1");

    exit(0);
}