#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int length(char *input){
    int length = 0;
    while(input[length]!='\0')  
    {
        length++;
    }
    return length;
}

int main(int argc, char *argv[]){
	int n1, n2, f1, f2;
	char buf1[500], buf2[500], hasil[500];
	//printf(1, "%s\n", argv[1]);
	//printf(1, "%s\n", argv[2]);
	
	if((f1 = open(argv[1], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[1]);
		exit();
	}
	if((f2 = open(argv[2], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[2]);
		exit();
	}
	int counter1 = 0, counter2 = 0, counter = 0, counters1 = 0, counters2 = 0, cs1 = 0, cs2 =0;
	n1 = read(f1, buf1, sizeof(buf1));
	n2 = read(f2, buf2, sizeof(buf2));
	int p1, p2;
	p1 = length(buf1);
	p2 = length(buf2);
	if(n1 > 0 || n2 > 0){
		//printf(1, "masuk ke if\n");
		while(p1 || p2){
		char kedua[50];
		char pertama[50];
			while(buf1[counters1] != ' '){
				pertama[cs1] = buf1[counters1];
				counters1++; cs1++;
			}
			while(buf2[counters2] != ' '){
				kedua[counters2] = buf2[cs2];
				counters2++; cs2++;
			}
			printf(1, "buf1 : %s\n", pertama);
			printf(1, "buf2: %s\n", kedua);
			while(buf1[counter1] != '\n'){
				hasil[counter] = buf1[counter1];
				counter++; counter1++;
			}	
			hasil[counter] = ' ';
			counter++;		
			while(buf2[counter2] != '\n'){
				hasil[counter] = buf2[counter2];
				counter++; counter2++;
			}
			hasil[counter] = '\n';
			counter++; counter1++; counter2++;
			counters1 = counter1; counters2 = counter2;
			p1-=counter1; p2-=counter2;
		//printf(1, "%s %d %d\n", hasil, p1, p2);
		}
	}
	close(f1);
	close(f2);
	printf(1, "%s\n", hasil);
	exit();
}
