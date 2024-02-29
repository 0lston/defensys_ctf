#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>


/* OPCODES : 
 * ADN : 3**4 // 81 opcode allowed sequence of ATGC three per opcode
 * registers : AMX only for return value and primitive stack
 * 	       RNA generale prupose register (size of regs 6 bytes)
 * 124 : ATC : PUSH WORD [next value of 6 rep 123456] decimal
 * 123 : ATG : PUSH BYTE [next value of 3 rep 123   ] decimal
 * 111 : AAA : XOR       [the last 2 values pushed  ] and put result into register AMX
 * 444 : GGG : ADD       [the last 2 values pushed  ] and put result into register AMX
 * 333 : CCC : SUB       [the last 2 values pushed  ] and put result into register AMX
 * 324 : GTC : PUSH AMX  [move value of AMX to stack] and set it to NULL
 * 313 : GAG : POP       [get the last value pushed ] into RNA
 * 312 : GAT : PUSH RNA
 * 314 : GAC : POP RNA
 * 213 : TAG : MOV [SEQ 3] TO RNA 
 * 341 : GCA : INC [reg]
 * 244 : TCC : PUSH CMX TO STACK
 *
 * encoding : A:1,T:2,G:3,C:4
 * */

void halt(char *msg){
	puts(msg);
	exit(0);
}
int getcode(uint64_t *page, uint64_t cursor, int bytes){
	char *tmp = page;
	int code[3] = {0};
	for(int i=0;i!=3;i++){
		//printf("checking %p = %c\n", tmp+i, tmp[i]);
		if(tmp[i+cursor] == 'A') code[i] = 1;
		else if(tmp[i+cursor] == 'T') code[i] = 2;
		else if(tmp[i+cursor] == 'G') code[i] = 3;
		else if(tmp[i+cursor] == 'C') code[i] = 4;	
	}
	int opcode =  code[0]*100 + code[1] * 10 + code[2]; 
	return opcode;
}
void execute_page(char *ram){
	uint64_t AMX,RNA,CMX,GP,SMP; // GP gene pointer , CMX counter reg, SMP stack pointer
	uint64_t stack[1024] = {0};
	GP,CMX,SMP,RNA,AMX = 0,0,0,0,0;
	int flag_gp = 0;
	if(!ram) halt("watafinhya ram?");
	for(GP=0;;){
		/* FOR DEBUG ONLY REMOVE IT FOR CHALL */
		
		puts("----------[DEBUG]------------");
		printf("[CMX=%p][SMP=%p][AMX=%p][RNA=%p][GP=%p]\n", CMX, SMP, AMX, RNA, GP);
		for(int i=0;i!=SMP+1;i++) printf("[STACK %d = %d]\n",i, stack[i]);
		

		/* ----------------------------------- */
		
		if(SMP >= 1024) halt("OOM");
		
		int op = getcode(ram, GP, 3);

		if(op == 124){
			char tmph[10];
			memcpy(tmph, ram+GP+3, 6); GP = GP+6; flag_gp = 1;
			stack[SMP] = atoi(tmph);
			SMP++;	
		}
		else if(op == 244){
			stack[SMP] = CMX;
			SMP++;
		}
		else if(op == 213){
			char tmph3[10];
			memcpy(tmph3, ram+GP+3, 3); GP = GP+3 ; flag_gp = 1;
			RNA = atoi(tmph3);
		}
		else if(op == 341){
			char tmph4[10];
			memcpy(tmph4, ram+GP+3, 3); GP =GP+3; flag_gp = 1;
			tmph4[4] = '\0';
			if(tmph4[0] == 'C') CMX++;
			else if(tmph4[0] == 'S') SMP++;
			else if(tmph4[0] == 'R') RNA++;
			else if(tmph4[0] == 'A') AMX++;
			else halt("invlaid reg!!");
		}
		else if(op == 123){
			char tmph2[10];
			memcpy(tmph2, ram+GP+3, 3); GP = GP+3; flag_gp = 1;
			stack[SMP] = atoi(tmph2);
			SMP++;
		}
		else if(op == 111){
			if(SMP == 0 || SMP < 2) halt("rakatxyer fel memory usage bari dir bufferunderflow hahah");
			AMX = stack[SMP-1] ^ stack[SMP-2];
		}
		else if(op == 444){
			if(SMP == 0 || SMP < 2) halt("lmem error abro ??");
			AMX = stack[SMP-1] + stack[SMP-2];
		}
		else if(op == 333){
			if(SMP == 0 || SMP < 2) halt("waaaaaaaaa");
			AMX = stack[SMP-1] - stack[SMP-2];
		}
		else if(op == 324){
			stack[SMP] = AMX;
			SMP++;
		}
		else if(op == 313){
			RNA = stack[SMP];
			stack[SMP] = 0;
			SMP--;
		}
		else if(op == 312){
			stack[SMP] = RNA;
			SMP++;
		}
		else if(op == 314){
			RNA = stack[SMP];
			SMP--;
		}
		else halt("lopcode maxi hwa hadak!");
		if(!flag_gp||flag_gp) GP = GP + 3;
	}	
}
uint64_t load2ram(char *fbin){
	struct stat file_info;
	if(stat(fbin, &file_info)) halt("teked men l file li3titini");
	 
	int code_size = file_info.st_size;
	printf("size = %d\n", code_size);

	void *tmp = mmap(NULL, code_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if(tmp < 0) halt("ram fiha chi la3ba hah");
	//FILE *fd = fopen(fbin, "r");
	int fd = open(fbin, O_RDONLY);

	printf("ram @ %p\n", tmp);
	read(fd,tmp,code_size);
	return tmp;	
}
int main(int c, char *a[]){
	if(c < 2) halt("db ze3Ma ax radi n executer ?");
	//uint64_t *ram = load2ram(a[1]);
	//execute_page(load2ram(a[1]));
	halt("mzl maran executer haha");
	
	return 1;
}
