#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int session=-1;

struct node{
	int nim;
	char nama[100];
	char kelamin[10];
	char tgl_lahir[100];
	char tempat_lahir[100];
	char alamat[100];
	char kelas;
	float UAS, UTS, quiz, tgs, rata;
	char grade;

	struct node *next;
	struct node *prev;
};

struct node *head=NULL;

void login();
void DataMahasiswa();
void NilaiMahasiswa();
void Kelulusan();
void showMahasiswa();
void addMahasiswa();
void deleteMahasiswa();
void editMahasiswa();
void header();
void inputNilai();
void dataNilai();
void avgAll();
void editNilai();
void hapusNilai();
float maxRataRata();
float minRataRata();
void avgGrade();
void infoGrade();
void lulus();
void tidakLulus();
void dataMhs(int);
void editDataDiri(int);
void cekLulus(int);


void main(){

	if(session==-1){
		login();
	}

	int pil;
	char rep;

	do{
	system("cls");
	header();
	puts("|                      MAIN MENU                         |");
	puts("==========================================================");
	puts(" --> 1. Data Pokok");
	puts(" --> 2. Nilai");
	puts(" --> 3. Kelulusan");
	puts(" --> 4. Log Out");
	puts(" --> 5. Exit");
	puts("==========================================================");
	printf(" --> Pilihan : ");
	scanf("%d",&pil);

	switch(pil){
		case 1 :
			DataMahasiswa();
		break;
		case 2 :
			NilaiMahasiswa();
		break;
		case 3 :
			Kelulusan();
		break;
		case 4:
            login();
            break;
        case 5:
            exit(1);
            break;
		default:
			puts(" --> Pilihan tidak tersedia");
		break;
	}

	puts("==========================================================");
	printf(" --> Kembali ke menu utama ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
	login();
}

void login(){
	int cek;
	char user[100], pass[100];
	char data[]="admin";

	system("cls");

	header();


	puts("|            SILAHKAN LOGIN TERLEBIH DAHULU              |");
	puts("==========================================================");
	puts("");
	printf("     --> Masukan Username : ");
	fflush(stdin);
	gets(user);

	printf("     --> Masukan Password : ");
	fflush(stdin);
	gets(pass);

	int cekuser=strcmp(user,data);
	int cekpass=strcmp(pass,data);

	if(cekuser==0 && cekpass==0) {
		puts("");
		puts("     --> Login Berhasil!");
		getch();
		session=1;
		main();
	}

	struct node *bantu;
	int cekLog;
	char keep[100];

	bantu=head;
	cekLog=0;


	while(bantu!=NULL && cekLog==0){

		sprintf(keep, "%d", bantu->nim);

		int cekuser=strcmp(user,keep);
		int cekpass=strcmp(pass,keep);

		if(cekuser==0 && cekpass==0){
			cekLog=1;
			break;
		}

		bantu=bantu->next;
	}

	if(cekLog==1){

		puts("");
		puts("     --> Login Berhasil!");

		getch();
		session=1;

		dataMhs(bantu->nim);

	}

	else{

		puts("");
		puts("     --> Username / Password Salah");

		getch();

		login();
	}

}
void header(){
	puts("|========================================================|");
	puts("|          ****** PROGRAM DATA MAHASISWA ******          |");
	puts("|                 ### UNIVERSITAS X ###                  |");
	puts("|                         2021                           |");
	puts("|=========================^^^^===========================|");
}

void dataMhs(int nimnya){
	int pil;
	char rep;

	do{
	system("cls");

	header();
	printf("| NIM : %d |\n",nimnya);
	puts("==========================================================");
	puts("|                      MAIN MENU                         |");
	puts("==========================================================");
	puts(" --> 1. Ubah Data Diri");
	puts(" --> 2. Cek Kelulusan");
	puts(" --> 3. Log Out");
	puts(" --> 4. Exit");
	puts("==========================================================");
	printf(" --> Pilihan : ");
	scanf("%d", &pil);

	switch(pil){
		case 1 :
			editDataDiri(nimnya);
		break;
		case 2 :
			cekLulus(nimnya);
		break;
		case 3 :
			login();
		break;
		case 4 :
			exit(1);
		break;
		default:
			puts(" --> Pilihan tidak tersedia");
		break;
	}

	puts("==========================================================");
	printf(" --> Kembali ke menu utama ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
	login();
}

void editDataDiri(int nimnya){
	system("cls");
	struct node *bantu;

	header();
	puts("|                    EDIT DATA DIRI                       ");
	puts("==========================================================");
	bantu=head;

	while(bantu!=NULL){
		if(bantu->nim==nimnya){
			break;
		}
		bantu=bantu->next;
	}

		puts(" --> Data Saat Ini :");
		puts("==========================================================");
		printf(" --> Nama 		: %s\n",bantu->nama);
		printf(" --> Jenis Kelamin 	: %s\n",bantu->kelamin);
		printf(" --> Tanggal Lahir 	: %s\n",bantu->tgl_lahir);
		printf(" --> Tempat Lahir 	: %s\n",bantu->tempat_lahir);
		printf(" --> Alamat 		: %s\n",bantu->alamat);

		puts("==========================================================");
		puts(" --> Input Data Baru");
		puts("==========================================================");
		printf(" --> Nama : ");
		fflush(stdin);
		gets(bantu->nama);
		printf(" --> Jenis Kelamin : ");
		fflush(stdin);
		gets(bantu->kelamin);
		printf(" --> Tanggal Lahir : ");
		fflush(stdin);
		gets(bantu->tgl_lahir);
		printf(" --> Tempat Lahir : ");
		fflush(stdin);
		gets(bantu->tempat_lahir);
		printf(" --> Alamat : ");
		fflush(stdin);
		gets(bantu->alamat);

		puts("");
		puts(" --> Data Berhasil Di-Edit");
}

void cekLulus(int nimnya){
	struct node *bantu;

	avgGrade();

	puts("==========================================================");
	puts("|                  INFORMASI KELULUSAN                   |");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->nim==nimnya){
			if(bantu->grade=='A'||bantu->grade=='B'||bantu->grade=='C'){
				puts("==========================================================");
				puts("          *** Selamat Anda Dinyatakan Lulus ***           ");
				puts("==========================================================");
				puts(" --> Berikut Informasi Nilai Anda");
				puts("");
				printf(" --> UAS		: %.2f\n",bantu->UAS);
				printf(" --> UTS		: %.2f\n",bantu->UTS);
				printf(" --> Tugas		: %.2f\n",bantu->tgs);
				printf(" --> Quiz		: %.2f\n",bantu->quiz);
				printf(" --> Rata-Rata		: %.2f\n",bantu->rata);
				printf(" --> Grade		: %c\n",bantu->grade);
			}

			else{
				puts("==========================================================");
				puts("           *** Anda Dinyatakan Tidak Lulus ***            ");
				puts("==========================================================");
				puts(" --> Berikut Informasi Nilai Anda");
				puts("");
				printf(" --> UAS		: %.2f\n",bantu->UAS);
				printf(" --> UTS		: %.2f\n",bantu->UTS);
				printf(" --> Tugas		: %.2f\n",bantu->tgs);
				printf(" --> Quiz		: %.2f\n",bantu->quiz);
				printf(" --> Rata-Rata		: %.2f\n",bantu->rata);
				printf(" --> Grade		: %c\n",bantu->grade);
			}
		}
		bantu=bantu->next;
	}
}
