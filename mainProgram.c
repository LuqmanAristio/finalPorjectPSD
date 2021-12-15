#include <stdio.h>
#include <stdlib.h>

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
int hashKelas(int);
int cekNIM(int);

void main(){


	
return 0;
}

void DataMahasiswa(){
	int pil;
	char rep;
	do{
	system("cls");
	header();
	puts("|                DATA INDUK MAHASISWA                    |");
	puts("==========================================================");
	puts(" --> 1. Tampilkan Data");
	puts(" --> 2. Tambah Data");
	puts(" --> 3. Hapus Data");
	puts(" --> 4. Edit Data");
	puts(" --> 5. Kembali");
	puts("==========================================================");
	printf(" --> Pilihan : ");
	scanf("%d",&pil);

	switch(pil){
		case 1 :
			showMahasiswa();
		break;
		case 2 :
			addMahasiswa();
		break;
		case 3 :
			deleteMahasiswa();
		break;
		case 4 :
			editMahasiswa();
		break;
		case 5 :
			main();
		break;
		default:
			puts(" --> Pilihan tidak tersedia");
		break;
	}

	puts("==========================================================");
	printf(" --> Kembali ke menu sebelumnya ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
}
void showMahasiswa(){
	char ask;
	int nim_m;

	struct node *dataM;

	if(head==NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}

	system("cls");
	header();
	puts("|               Data Mahasiswa Terkini                   |");
	puts("==========================================================");

	dataM=head;
	puts("");
	int count=0;
	while(dataM!=NULL){

		printf(" -> NIM			: %d \n", dataM->nim);
		printf(" -> Nama Lengkap	: %s \n", dataM->nama);

		printf("\n");
		count++;
		dataM=dataM->next;
	}

	printf(" -> Jumlah Data Mahasiswa : %d\n\n",count);

	puts("==========================================================");
	printf(" --> Ingin menampilkan data lebih rinci? (y/t) : ");
	scanf("%s",&ask);
	puts("==========================================================");

	if(ask=='y'||ask=='Y'){
		printf(" --> Masukan NIM Mahasiswa : ");
		scanf("%d",&nim_m);

		puts("==========================================================");
		puts("                         RESULT                          ");
		puts("==========================================================");
		int a;
		a=0;

		dataM=head;

		while(dataM!=NULL){
			if(dataM->nim==nim_m){
				printf(" --> NIM		: %d\n",dataM->nim);
				printf(" --> Nama Lengkap 	: %s\n",dataM->nama);
				printf(" --> Kelas 		: %c\n",dataM->kelas);
				printf(" --> Jenis Kelamin 	: %s\n",dataM->kelamin);
				printf(" --> Tanggal Lahir 	: %s\n",dataM->tgl_lahir);
				printf(" --> Tempat Lahir 	: %s\n",dataM->tempat_lahir);
				printf(" --> Alamat Tinggal     : %s\n", dataM->alamat);

				a=1;
			}

			dataM=dataM->next;
		}

		if(a==0){
			puts(" --> NIM Tidak Ditemukan");
		}
	}

}
void addMahasiswa(){

	system("cls");

	struct node *baru, *bantu;
	int cek, kelas;
	char ask;

	baru=(struct node *)malloc(sizeof(struct node));
	header();

	puts("|               TAMBAH DATA MAHASISWA BARU               |");
	puts("==========================================================");

	printf(" --> NIM : ");
	scanf("%d",&baru->nim);

	cek=cekNIM(baru->nim);

	if(cek==0){
		puts(" --> NIM tidak tersedia");
		puts("==========================================================");
		printf(" --> Input Kembali? (y/t) : ");
		scanf("%s",&ask);

		free(baru);

		if(ask=='y'||ask=='Y')
			addMahasiswa();
		else
			DataMahasiswa();
	}


	kelas=hashKelas(baru->nim);
    baru->kelas = ('A' + (hashKelas((baru->nim+4))));

	printf(" --> Nama Lengkap : ");
	fflush(stdin);
	gets(baru->nama);

	printf(" --> Jenis Kelamin (L/P) : ");
	fflush(stdin);
	gets(baru->kelamin);

	printf(" --> Tanggal Lahir : ");
	fflush(stdin);
	gets(baru->tgl_lahir);

	printf(" --> Tempat Lahir : ");
	fflush(stdin);
	gets(baru->tempat_lahir);

	printf(" --> Alamat Tinggal : ");
	fflush(stdin);
	gets(baru->alamat);

	baru->UAS=baru->UTS=baru->quiz=baru->tgs=0;
	baru->grade='E';

	baru->next=baru->prev=NULL;

	if(head==NULL){
		head=baru;
	}

	else{
		bantu=head;

		while(bantu->next!=NULL){
			bantu=bantu->next;
		}

		bantu->next=baru;
		baru->prev=bantu;
	}

	puts("==========================================================");
	puts(" --> Data berhasil ditambahkan");
	puts("==========================================================");

	printf(" --> Kembali ke menu sebelumnya ? (y/t) : ");
	scanf("%s", &ask);

	if(ask=='y'||ask=='Y'){
		DataMahasiswa();
	}
	else{
		main();
	}

}

int cekNIM(int nimn){
	struct node *help;

	if(head==NULL){
		return 1;
	}

	help=head;
	while(help!=NULL){
		if(help->nim==nimn){
			return 0;
		}
		help=help->next;
	}

	return 1;
}
int hashKelas(int input){
    return (input%5);
}
