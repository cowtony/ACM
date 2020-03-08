#include<iostream.h>
#include<fstream.h>

int main(){
   char ch[2000];    char cih;
   int point=0;  int line=0;

   cih=cin.get();

   while(1){
	  if(cih==-1) break;
	  if(cih==60) {
	 cih=cin.get();
	 if(cih==98) {  while(ch[point]==32) point--;

			 ch[++point]=10;
			line=0;}
	 else { while(ch[point]==32) point--;
		if(line!=0)  ch[++point]=10;
		for(int i=1;i<=80;i++) ch[++point]=45;
		ch[++point]=10;
		line=0;
		   }
	cin.get();cin.get();
	if((cih=cin.get())==-1) {break;}


	  }

	  else if(cih==32||cih==10||cih==9){
		if(line!=0){ ch[++point]=32;
						line++;}
		while(cih==32||cih==10||cih==9) cih=cin.get();
		if(cih==-1) {
				  if(ch[point]==32) point--;
				  ch[++point]=10;break;
				 }
		}
	   else {
		 int count=0;char temp[81];
		 while(cih!=32&&cih!=10&&cih!=-1&&cih!=60) {
			temp[++count]=cih;

			cih=cin.get();
		 }
		 if(80-line>=count){
			for(int i=1;i<=count;i++){
				ch[++point]=temp[i];line++;
			 }
		  }
		  else{
		   ch[++point]=10;
		   line=0;
		   for(int i=1;i<=count;i++){
				ch[++point]=temp[i];line++;
			  }
			}
		   if(cih==-1){ch[++point]=10; break;}
		 }
	}
	//ofstream offfile;
	//offfile.open("1099.txt");

	for(int j=1;j<=point;j++){
	  cout.put(ch[j]);}

  //	offfile.put(ch[j]);      }
	//offfile.close();



	return 0;
}