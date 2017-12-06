#include "types.h"
#include "user.h"

int main(int argc, char *argv[]) {
	int sleep_sec;
	//validasi input
	if (argc < 2)
	{
		printf(2, "Usage: sleep seconds\n");
		exit();
	}
//merubah input
	sleep_sec = atoi(argv[1]);
	
	if (sleep_sec > 0)
	{
		
		sleep(sleep_sec);
	} 
	else 
	{
		printf(2, "Invalid interval %s\n", argv[1]);
	}
	
	exit();
}
