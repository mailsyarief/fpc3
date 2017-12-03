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
	
	if((f1 = open(argv[1], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[1]);
		exit();
	}
	if((f2 = open(argv[2], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[2]);
		exit();
	}
	int counter1 = 0, counter2 = 0, counter = 0;
	n1 = read(f1, buf1, sizeof(buf1));
	n2 = read(f2, buf2, sizeof(buf2));
	int p1, p2;
	p1 = length(buf1);
	p2 = length(buf2);
	
	if(n1 > 0 || n2 > 0){
		while(p1 || p2){	
			while(buf1[counter1] != '\n'){
				hasil[counter] = buf1[counter1];
				counter++; counter1++;
			}			
			while(buf2[counter2] != '\n'){
				hasil[counter] = buf2[counter2];
				counter++; counter2++;
			}
			hasil[counter] = '\n';
			counter++; counter1++; counter2++;
			p1-=counter1; p2-=counter2;
		}
	}
	close(f1);
	close(f2);
	printf(1, "%s\n", hasil);
	exit();
}
