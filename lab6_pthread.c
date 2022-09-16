#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum;
int msum;
int upper;
void *runner (void*param);
int main(int argc,char*argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	int i;
	if(upper>0){
		for(i = 0; i<=upper; i++){
			msum += i;
		}
	}

	printf("msum = %d\n",msum);
	printf("csum-msum = %d",csum-msum);
	return 0;
}
void *runner(void*param){
	upper = atoi(param);
	int i;
	csum = 0;
	if(upper>0){
		for(i = 0; i<= upper*2; i++){
			csum += i;
		}
	}
	printf("csum = %d\n",csum);
	pthread_exit(0);
}
//2.5 : 2 แบบ 1.แม่เสร็จก่อนลูก 2.ลูกเสร็จก่อนแจก่อนแนแม่
