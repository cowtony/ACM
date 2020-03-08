  #include<iostream.h>

  int main(){
	char ch;
	char str[20000];
	str[0]=NULL;
	ch=cin.get();

	while(ch==32||ch==10||ch==9)
		ch=cin.get();
	int line=0;
	int point=0;
	while(1){
		if(ch==-1) break;
		if(ch==60){
			ch=cin.get();
			if(ch==98){
				if(str[point]==32) point--;
				str[++point]=10;
			}
			else{
				if(line!=0) {
					if(str[point]==32) point--;
					str[++point]=10;
				}
				for(int temp=1;temp<=80;temp++)
					str[++point]=45;
				str[++point]=10;
			}
			line=0;
			cin.get();cin.get();
			ch=cin.get();

		}
		else if(ch==32||ch==10||ch==9){
			if(line!=0){line++; str[++point]=32;}
			ch=cin.get();
			while(ch==32||ch==10||ch==9)
				ch=cin.get();



		}
		else{char tch[81];int count=0;
			tch[++count]=cin.get();
			while(tch[count]!=32&&tch[count]!=10
				&&tch[count]!=9&&tch[count]!=-1&&tch[count]!=60)
				tch[++count]=cin.get();
			if(line+count>80) {

					str[++point]=10;
					line=0;
				}

				str[++point]=ch;line++;
				for(int temp=1;temp<count;temp++){
					str[++point]=tch[temp];line++;
				}
				ch=tch[count];

			}

		}

		for(int tt=1;tt<=point;tt++)
			cout.put(str[tt]);
		if(line!=0) cout<<endl;
		cout<<endl;






	return 0;
 }






