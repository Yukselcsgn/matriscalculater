#include <stdio.h>
#include <time.h>

void matris4()
{
	printf("4. MATRIS: \n");
	
	int matris[100][100];
	int x,y;
	int i,j;
	double sutuntop,satirtop;
	double det1,det2,detgercel;
	printf("satir sayisi seciniz");
	scanf("%d",&x);
	
	printf("sutun sayisi seciniz");
	scanf("%d",&y);

	
	//getch(); entera basana kadar program durur
	printf("%d Sayi giriniz",x*y);
	
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			scanf("%d",&matris[i][j]);
			
		}
	}
	
	printf("\nGirdiginiz matris;\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d\t",matris[i][j]);
			
		}
		
		printf("\n");
	}
	printf("Satir toplami;\tsatir ort;\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			satirtop += matris[i][j];
		}
		
		
		printf("%f\t",satirtop);
		printf("%4f\n", satirtop/y);
		satirtop = 0; 
	}

	printf("\n---------------------\n");

	printf("Sutun toplami;\tsutun ort;\n");

	for(j=0;j<y;j++)//sütunlarý toplamak için sütunlarý satýr haline getiriyoruz oyüzden for döngülerinin yerleri deðiþir
	{
		for(i=0;i<x;i++)
		{
			sutuntop += matris[i][j];
		}
		
		printf("%f\t", sutuntop);
		printf("%4f\n", sutuntop/x);
		sutuntop = 0; 
	}
	if(x==3&&y==3)
	{
		
		det1=((matris[0][0]*matris[1][1]*matris[2][2])+(matris[1][0]*matris[2][1]*matris[0][2])+(matris[2][0]*matris[0][1]*matris[1][2]));
		det2=((matris[0][2]*matris[1][1]*matris[2][0])+(matris[1][2]*matris[2][1]*matris[0][0])+(matris[2][2]*matris[0][1]*matris[1][0]));
		detgercel=det1-det2;
		printf("4. Matrisin determinantý : %f",detgercel);
	}
}



int main()
{
	
	int matris[4][5];
	int i,j;
	int oto;
	srand(time(NULL)); //random matris atanacaðý için yazýyoruz
	double  satirtop,sutuntop;

	printf("\tILK MATRISIMIZ;\n\n");

	for(i=0;i<4;i++) //matrisi hem random larak atamak hem de yazmak için tek döngü yeter
	{
		for(j=0;j<5;j++)//i ler satýr j ler ise sütunlarý temsil eder 
		{
			matris[i][j] = 0 + rand() %11;//random deðer atýyoruz
			printf("%4d",matris[i][j]);//random deðerleri yazdýrýyoruz
		}
		
		printf("\n");
	}
	printf("Satir toplami;\tsatir ort;\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			satirtop += matris[i][j];
		}
		
		
		printf("%f\t",satirtop);
		printf("%4f\n", satirtop/5);
		satirtop = 0; 
	}

	printf("\n---------------------\n");

	printf("Sutun toplami;\tsutun ort;\n");

	for(j=0;j<5;j++)//sütunlarý toplamak için sütunlarý satýr haline getiriyoruz oyüzden for döngülerinin yerleri deðiþir
	{
		for(i=0;i<4;i++)
		{
			sutuntop += matris[i][j];
		}
		
		printf("%f\t", sutuntop);
		printf("%4f\n", sutuntop/4);
		sutuntop = 0; 
	}
	

	printf("\n\n");
//-------------------------------
	//printf("Matrisi kendiniz mi girmek istersiniz(00) rastgele mi olsun(11)");
	//scanf("%d",&oto);
	printf("\n");
	int matris2[3][3];
	int k,n;
	double det1,det2,detgercel;
	double  satirtop2,sutuntop2;

	printf("\tIKINCI MATRISIMIZ;\n\n");

	
	for(k=0;k<3;k++)
	{
		for(n=0;n<3;n++)
		{
			matris2[k][n] = 0 + rand() %6;//programýn düzgün çalýþýp çalýþmadýgýný kullanýcý dogru kontrol etmesi ve detin küçük çýkmasý için 0-1-2-3-4-5 deðerleri atanabiliyor
		
			printf("%4d",matris2[k][n]);
		}
		
		printf("\n");
	}
	printf("Satir toplami;\tsatir ort;\n");
	for(k=0;k<3;k++)
	{
		for(n=0;n<3;n++)
		{
			satirtop2 += matris2[k][n];
		}
		
		
		printf("%f\t",satirtop2);
		printf("%4f\n", satirtop2/5);
		satirtop2 = 0; 
	}

	printf("\n---------------------\n");

	printf("Sutun toplami;\tsutun ort;\n");

	for(n=0;n<3;n++)
	{
		for(k=0;k<3;k++)
		{
			sutuntop2 += matris2[k][n];
		}
		
		printf("%f\t", sutuntop2);
		printf("%4f\n", sutuntop2/4);
		sutuntop = 0; 
	}

	printf("\nIKINCI MATRISIN DETERMINANTI =");

	det1=((matris2[0][0]*matris2[1][1]*matris2[2][2])+(matris2[1][0]*matris2[2][1]*matris2[0][2])+(matris2[2][0]*matris2[0][1]*matris2[1][2]));
	det2=((matris2[0][2]*matris2[1][1]*matris2[2][0])+(matris2[1][2]*matris2[2][1]*matris2[0][0])+(matris2[2][2]*matris2[0][1]*matris2[1][0]));
	detgercel=det1-det2;
	printf("%f",detgercel);
	
	
	
	//---------------------------------------
	
	
	
	printf("\n\n3. MATRIS\n\n");
	printf("9 tane sayi giriniz; ");

	int matris3[3][3];
	det1=0;//tekrar deðiþken oluþturmamak için yukarýda kullandýktan sonra burada 0 a eþitleyip devam ettik
	det2=0;
	detgercel=0;
	double  satirtop3=0,sutuntop3=0;
	int m,l;
	
	for(m=0;m<3;m++)//deðerleri kendimiz atamak istiyor isek ayný iç içe döngüyü 2 kez kullanmalýyýz
	{
		for(l=0;l<3;l++)
		{
			scanf("%d",&matris3[m][l]);
			
		}
	}
	
	printf("\nGirdiginiz matris;\n");
	for(m=0;m<3;m++)//ilk iç içe döngüde deðerler alýndý 2. iç içe döngüde ise alýnan bu deðerler yazdýrýldý  
	{
		for(l=0;l<3;l++)
		{
			printf("%d\t",matris3[m][l]);
			
		}
		
		printf("\n");
	}
	printf("\n\n");
	
	//burdan sonrasý matris toplam ort ve deti verir
	printf("Satir toplami;\tsatir ort;\n");
	
	for(m=0;m<3;m++)
	{
		for(l=0;l<3;l++)
		{
			satirtop3 += matris3[m][l];
		}
		
		
		printf("%f\t",satirtop3);
		printf("%4f\n", satirtop3/3);
		satirtop3 = 0; 
	}

	printf("\n---------------------\n");

	printf("Sutun toplami;\tsutun ort;\n");

	for(l=0;l<3;l++)
	{
		for(m=0;m<3;m++)
		{
			sutuntop3 += matris3[m][l];
		}
		
		printf("%f\t", sutuntop3);
		printf("%4f\n", sutuntop3/3);
		sutuntop3 = 0; 
	}

	printf("\nUCUNCU MATRISIN DETERMINANTI =");

	det1=((matris3[0][0]*matris3[1][1]*matris3[2][2])+(matris3[1][0]*matris3[2][1]*matris3[0][2])+(matris3[2][0]*matris3[0][1]*matris3[1][2]));
	det2=((matris3[0][2]*matris3[1][1]*matris3[2][0])+(matris3[1][2]*matris3[2][1]*matris3[0][0])+(matris3[2][2]*matris3[0][1]*matris3[1][0]));
	detgercel=det1-det2;
	printf("%f",detgercel);
	printf("\n\n");
	
	matris4();
	
	return 0; 
}
