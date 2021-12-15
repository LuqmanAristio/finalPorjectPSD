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

void deleteMahasiswa(){

	struct node *bantu, *hapus;

	if(head==NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}

	int delNim;
	system("cls");
	header();

	puts("|               HAPUS DATA MAHASISWA BARU                |");
	puts("==========================================================");
	printf(" --> Masukan NIM Mahasiswa : ");
	scanf("%d",&delNim);
	puts("==========================================================");


	int cek;
	cek=0;

		bantu=head;

		while(bantu!=NULL){
			if(bantu->nim==delNim){
				hapus=bantu;

				if(bantu->prev==NULL&&bantu->next==NULL){
					head=NULL;
				}

				else if(bantu->prev==NULL){
					head=head->next;
					head->prev=NULL;
				}

				else if(bantu->next==NULL){
					bantu->prev->next=NULL;
				}

				else{
					hapus->prev->next=bantu->next;
					hapus->next->prev=bantu->prev;
				}

				free(hapus);
				cek=1;
				puts(" --> Data Berhasil Dihapus");
			}
			bantu=bantu->next;
		}

	if(cek==0){
		puts(" --> NIM Tidak Ditemukan");
	}


}

void editMahasiswa(){
	struct node *bantu;
	int editNim, cek;

	if(head==NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}

	cek=0;
	system("cls");
	header();
	puts("|               EDIT DATA MAHASISWA BARU                 ");
	puts("==========================================================");
	printf(" --> Masukan NIM Mahasiswa : ");
	scanf("%d",&editNim);

	bantu=head;

	while(bantu!=NULL){
		if(bantu->nim==editNim){
			cek=1;
			break;
		}
		bantu=bantu->next;
	}


	if(cek==0){
		puts("==========================================================");
		puts(" --> NIM Tidak Ditemukan");
	}
	else{

		puts("==========================================================");
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
}

void Kelulusan()
{
    int pilihan;
    char rep;

    do{

    system("cls");
    header();
    puts("|                Kelulusan Mahasiswa                     |");
    puts("==========================================================");
    printf(" --> 1. Informasi Grade dan Nilai\n");
    printf(" --> 2. Mahasiswa Yang Lulus\n");
    printf(" --> 3. Mahasiswa Yang Tidak Lulus\n");
    printf(" --> 4. Kembali\n");
    puts("==========================================================");
    printf(" --> Pilihan : ");
    scanf("%d",&pilihan);

    switch(pilihan)
    {
        case 1:
            infoGrade();
        break;
    	case 2:
            lulus();
        break;
        case 3:
        	tidakLulus();
        break;
        case 4:
        	main();
        break;
        default:
        	puts(" --> Pilihan Tidak Tersedia");
        break;
    }

    puts("==========================================================");
	printf(" --> Kembali ke menu sebelumnya ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
}

void infoGrade(){
	puts("==========================================================");
	puts("|                   GRADE MAHASISWA                      |");
	puts("==========================================================");
	puts(" --> Grade A untuk Nilai 80 sampai 100");
	puts(" --> Grade B untuk Nilai 70 sampai 79");
	puts(" --> Grade C untuk Nilai 60 sampai 69");
	puts(" --> Grade D untuk Nilai 50 sampai 59");
	puts(" --> Grade E untuk Nilai 50 Kebawah");
}

void lulus(){

	struct node *bantu;
	int j=0;
	avgGrade();

	puts("==========================================================");
	puts("|                 MAHASISWA YANG LULUS                   |");
	puts("==========================================================");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->grade=='A'||bantu->grade=='B'||bantu->grade=='C'){
			printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);
			j++;
		}
		bantu=bantu->next;
	}
	puts("");
	printf(" --> Jumlah : %d\n",j);
}

void tidakLulus(){
	struct node *bantu;
	int j=0;
	avgGrade();

	puts("==========================================================");
	puts("|                 MAHASISWA YANG GAGAL                    ");
	puts("==========================================================");


	bantu=head;

	while(bantu!=NULL){
		if(bantu->grade=='E'||bantu->grade=='D'){
			printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);
			j++;
		}
		bantu=bantu->next;
	}
	puts("");
	printf(" --> Jumlah : %d\n",j);
}

void NilaiMahasiswa(){
	int pil;
	char rep;

	do{
	system("cls");
	header();
	puts("|                     NILAI MAHASISWA                    |");
	puts("==========================================================");
    puts(" --> 1. Tampilkan Data");
    puts(" --> 2. Tambah Data");
    puts(" --> 3. Rata Rata");
    puts(" --> 4. Edit Data");
    puts(" --> 5. Hapus Data");
    puts(" --> 6. Kembali");
	puts("==========================================================");
	printf(" --> Pilihan : ");
	scanf("%d",&pil);
	puts("==========================================================");

	switch(pil)
    {
        case 1:
    		dataNilai();
        break;
        case 2:
        	inputNilai();
    	break;
    	case 3:
        	avgAll();
        break;
        case 4:
        	editNilai();
        break;
		case 5:
            hapusNilai();
        break;
        case 6:
            main();
        break;
		default :
			puts(" --> Pilihan tidak tersedia");
		break;
    }

    puts("==========================================================");
	printf(" --> Kembali ke menu sebelumnya ? (y/t) : ");
	scanf("%s",&rep);

	}while(rep=='y'||rep=='Y');
}

void dataNilai(){

	struct node *bantu;

		if(head==NULL){
        	printf(" --> Data Mahasiswa Sedang Kosong\n");
            return;
        }

        system("cls");
        header();
        puts("|                 DAFTAR NILAI MAHASISWA                 |");
        puts("==========================================================");
        bantu=head;
        while(bantu!=NULL)
        {
        	puts("");
            printf(" -> NIM      : %d\n",bantu->nim);
            printf(" -> Nama     : %s\n",bantu->nama);
            printf(" -> UAS      : %.2f\n",bantu->UAS);
            printf(" -> UTS      : %.2f\n",bantu->UTS);
            printf(" -> Quiz     : %.2f\n",bantu->quiz);
            printf(" -> Tugas    : %.2f\n",bantu->tgs);

			printf("\n----------------------\n");
            bantu=bantu->next;
        }

}

void inputNilai(){

	int nimN,nimM,x=0;
	struct node *bantu;

	if(head==NULL){
        printf(" --> Data Mahasiswa Sedang Kosong\n");
        return;
    }

    system("cls");
    header();
    puts("|                 INPUT NILAI MAHASISWA                  |");
    puts("==========================================================");
    printf(" --> Masukkan NIM : ");
    scanf("%d",&nimN);
    puts("==========================================================");

    if(head->nim==nimN){
        printf(" --> Nama : %s\n",head->nama);
        printf(" --> Nilai UAS : ");
        scanf("%f",&head->UAS);
        printf(" --> Input Nilai UTS : ");
        scanf("%f",&head->UTS);
        printf(" --> Input Nilai Quiz : ");
        scanf("%f",&head->quiz);
        printf(" --> Input Nilai Tugas : ");
        scanf("%f",&head->tgs);
        puts("==========================================================");
        printf(" --> Data Berhasil Ditambahkan !\n");
        x=1;
    }
    else{
	    bantu=head;
	    bantu=bantu->next;
	    while(bantu!=NULL)
	    {
	        if(bantu->nim==nimN){
	            printf(" --> Nama : %s\n",bantu->nama);
	            printf(" --> Input Nilai UAS : ");
	            scanf("%f",&bantu->UAS);
	            printf(" --> Input Nilai UTS : ");
	            scanf("%f",&bantu->UTS);
	            printf(" --> Input Nilai Quiz : ");
	            scanf("%f",&bantu->quiz);
	            printf(" --> Input Nilai Tugas : ");
	            scanf("%f",&bantu->tgs);

	            puts("==========================================================");
           		printf(" --> Data Berhasil Ditambahkan !\n");
	            x=1;
	        }
	            bantu=bantu->next;
	        }
        }

		if(x==0){
            printf(" --> NIM Tidak ditemukan\n");
        }

    	avgGrade();

}

void avgAll(){

	avgGrade();

	struct node *bantu;
	int j,w,ua,ut,qu,tg;
	float b;
	float rataAll,rataUAS,rataUTS,rataQuiz,rataTugas;

	if(head==NULL)
    {
        printf(" --> Data Mahasiswa Sedang Kosong\n");
        return;
    }

    system("cls");
    header();
    puts("|                       Rata Rata                        |");
    puts("|                   Nilai Mahasiswa                      |");
    puts("==========================================================");

    bantu=head;

	j=0;
    rataAll=0;
    b=0,ua=0,ut=0,qu=0,tg=0;
    while(bantu!=NULL)
    {
        bantu->rata=(bantu->UAS+bantu->UTS+bantu->quiz+bantu->tgs)/4;

        printf(" -> %d. %s\tRata Rata : %.2f\tGrade : %c\n",bantu->nim,bantu->nama,bantu->rata,bantu->grade);

        b = b + bantu->rata;
        ua = ua + bantu->UAS;
        ut = ut + bantu->UTS;
        qu = qu + bantu->quiz;
        tg = tg + bantu->tgs;
        bantu = bantu->next;

		j++;
        printf("--------------------------\n");
    }
        rataAll= b/(float)j;
        float rata_rata_max = maxRataRata();
        float rata_rata_min = minRataRata();

        rataUAS = (float)ua/(float)j;
        rataUTS = (float)ut/(float)j;
        rataQuiz = (float)qu/(float)j;
        rataTugas = (float)tg/(float)j;


        puts("");
        puts("==========================================================");
        puts(" --> Data Rata-Rata Nilai");
        puts("==========================================================");
        printf(" --> Seluruh Mahasiswa 	: %.2f\n",rataAll);
        printf(" --> Tertinggi 		: %.2f\n",rata_rata_max);
        printf(" --> Terendah 		: %.2f\n",rata_rata_min);
        puts("==========================================================");
        printf(" --> UAS 		: %.2f\n",rataUAS);
        printf(" --> UTS 		: %.2f\n",rataUTS);
        printf(" --> Quiz 		: %.2f\n",rataQuiz);
        printf(" --> Tugas 		: %.2f\n",rataTugas);

}

void editNilai(){

	int nimM;
	int c;

	struct node *bantu;

	c=0;

	if(head==NULL)
    {
    	printf(" --> Data Mahasiswa Sedang Kosong\n");
    	return;
    }

    system("cls");
    header();
    puts("|                 Update Nilai Mahasiswa                 |");
    puts("==========================================================");
    printf(" --> Masukkan NIM : ");
    scanf("%d",&nimM);
    puts("==========================================================");

    bantu=head;

    while(bantu!=NULL){
    	if(bantu->nim==nimM){
    		c=1;
    		break;
		}
		bantu=bantu->next;
	}

	if(c==1){
		printf(" --> Data Nilai Saat Ini\n");
		puts("==========================================================");
		printf(" -> Nama  : %s\n",bantu->nama);
		printf(" -> UAS   : %.3f\n",bantu->UAS);
		printf(" -> UTS   : %.3f\n",bantu->UTS);
		printf(" -> Quiz  : %.3f\n",bantu->quiz);
		printf(" -> Tugas : %.3f\n",bantu->tgs);

	    puts("==========================================================");
	    printf(" --> Masukan Data Baru\n");
		puts("==========================================================");
		printf(" -> Nilai UAS : ");
		scanf("%f",&bantu->UAS);
		printf(" -> Nilai UTS : ");
		scanf("%f",&bantu->UTS);
		printf(" -> Nilai Quiz : ");
		scanf("%f",&bantu->quiz);
		printf(" -> Nilai Tugas : ");
		scanf("%f",&bantu->tgs);
		puts("==========================================================");
		printf(" --> Data Berhasil Di-Update\n");
	}

    else if(c==0)
        {
            printf(" --> NIM Tidak Ditemukan\n");
        }

    avgGrade();

}

void hapusNilai(){

	if(head==NULL)
    {
    	printf(" --> Data Mahasiswa Sedang Kosong\n");
    	return;
    }

	struct node *bantu;
	bantu=head;
    while(bantu!=NULL)
    {
        bantu->UAS=bantu->UTS=bantu->quiz=bantu->tgs=0;
        bantu=bantu->next;
    }

    avgGrade();

	printf(" --> Data Nilai Berhasil Dihapus !\n");
}

float maxRataRata()
{
    struct node *bantu=head, *bantu2=head;
    float max;

    if(head->next==NULL){
    	return head->rata;
	}

    while(bantu->next!=NULL)
        {
            if(bantu2->rata < bantu->next->rata){
            	bantu2=bantu->next;
			}
            bantu=bantu->next;
        }

    return bantu2->rata;
}

float minRataRata()
{
    struct node *bantu=head, *bantu2=head;
    float min;

    if(head->next==NULL){
    	return head->rata;
	}

    while(bantu->next!=NULL)
        {
            if(bantu2->rata > bantu->next->rata){
            	bantu2=bantu->next;
			}
            bantu=bantu->next;
        }

    return bantu2->rata;
}

void avgGrade(){
	struct node *bantu;

	bantu=head;

	while(bantu!=NULL){
		bantu->rata=(bantu->UAS+bantu->UTS+bantu->quiz+bantu->tgs)/4;

		if(bantu->rata >= 80 && bantu->rata <= 100)
		bantu->grade='A';

		else if(bantu->rata <= 80 && bantu->rata >= 70)
		bantu->grade='B';

		else if(bantu->rata <= 70 && bantu->rata >= 60)
		bantu->grade='C';

		else if(bantu->rata <= 60 && bantu->rata >=50)
		bantu->grade='D';

		else if(bantu->rata<50)
		bantu->grade='E';

		bantu=bantu->next;

	}
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


	if(head == NULL){
		puts("==========================================================");
		puts(" --> Data Sedang Kosong");
		return;
	}

	system("cls");
	header();
	puts("|               Data Mahasiswa Terkini                   |");
	puts("==========================================================");


	puts("");
	int count=0;
        dataM=head;
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

		dataM=head[hashKelas(nim_m)];

		while(dataM!=NULL){
			if(dataM->nim==nim_m){
				printf(" --> NIM		: %d\n",dataM->nim);
				printf(" --> Nama Lengkap 	: %s\n",dataM->nama);
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
