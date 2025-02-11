#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum) {
   printf("Received SIGTERM. Exiting gracefully...\n");
   // Perform cleanup or other necessary actions before exiting
   _exit(0);
}

int main() {
   // Set custom signal handler for SIGTERM
   signal(SIGTERM, sig_handler); 
   while (1) {
       printf("Press Ctrl+C to send SIGTERM...\n");
       sleep(1);
    }
   return 0;
}