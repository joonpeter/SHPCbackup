#include <stdio.h>
#include <stdlib.h>

//#define AR_SIZE (88100*320/4)
#define AR_SIZE (7047336)
#define R_SIZE 4096
unsigned long long rs[AR_SIZE];
unsigned long long addr[AR_SIZE];

int main (){
       unsigned long long addr_std; 
       FILE* in_fp;
	   FILE* out_fp;
       unsigned long long file_buff[3]; 
	   unsigned long long offset;
	   unsigned long long sum=0;
       unsigned long j = 0;

       in_fp = fopen("/home/smkwon/daptrace/scripts/sum-1217-0.txt","r");
       if(in_fp == NULL){
		   printf("FAIL: file open\n");
		   exit(0);
	   }

  
       fscanf(in_fp, "%llu %llu %llu", &file_buff[0], &file_buff[1], &file_buff[2]);
	 
       fscanf(in_fp, "%llu %llu %llu", &file_buff[0], &file_buff[1], &file_buff[2]); 

       addr_std = file_buff[0];
       
	     while(!feof(in_fp)){
             if(j % 1000000 == 0){ printf("j is %lu\n",j);} 
             
             fscanf(in_fp, "%llu %llu %llu", &file_buff[0], &file_buff[1], &file_buff[2]);


			 if(file_buff[1] == R_SIZE){
				 offset = (file_buff[0] - addr_std)/R_SIZE;

				 addr[offset] = file_buff[0];
				 rs[offset] += file_buff[2];
			    
			 }
			 j++;
		 }

	   fclose(in_fp);
       
       out_fp = fopen("output-1217-0","w");
       if(out_fp == NULL){
		   printf("FAIL: file open\n");
		   exit(0);
	   }
	    
	   for(int i = 0; i < AR_SIZE ; i++){
		   fprintf(out_fp,"%llu %llu\n", addr[i], rs[i]);
		   
		   if(rs[i] > 0) sum++;
	   }
       fclose(out_fp);
	   
	   sum = sum * 4 * 1024;
	   
	   printf("peak memory is %llu bytes\n",sum);
	   
	   return 0;
}

