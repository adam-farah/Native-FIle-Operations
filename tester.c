#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void png2jpg(char* filename);
void png2jpeg(char* filename);
void jpg2png(char* filename);
void jpg2jpeg(char* filename);
void jpeg2png(char* filename);
void jpeg2jpg(char* filename);

void mp42flv(char* filename);
void mp42avi(char* filename);
void flv2mp4(char* filename);
void flv2avi(char* filename);
void avi2mp4(char* filename);
void avi2flv(char* filename);

void mp32flac(char* filename);
void mp32wav(char* filename);
void flac2mp3(char* filename);
void flac2wav(char* filename);
void wav2mp3(char* filename);
void wav2flac(char* filename);

void zip(char* archive, char* filename);
void unzip(char* filename);
void tar(char* archive, char* filename);
void untar(char* filename);
void rar(char* archive, char* filename);
void unrar(char* filename);

void main(int argc, char** argv) {

	if(argc<3){
		printf("Too few arguments");
	}else if(argc==3){
		
		char* compressionFormat=argv[1];
		char* archive=argv[2];
		
		printf("compressionFormat: %s\n",compressionFormat);
		printf("archive: %s\n",archive);
		
		if(strcmp(compressionFormat,"unzip")==0){
			//unzip -o audio.zip
			unzip(archive);
		}else if(strcmp(compressionFormat,"untar")==0){
			//tar -xzf audio.tar.gz
			untar(archive);
		}else if(strcmp(compressionFormat,"unrar")==0){
			//unrar e -y audio.rar
			unrar(archive);
		}else{
			printf("Invalid Compression Format\n");
		}
		
	}else if(argc==4){
	
		if(strcmp(argv[1],"zip")==0||strcmp(argv[1],"tar")==0||strcmp(argv[1],"rar")==0){
		
			char* compressionFormat=argv[1];
			char* archive=argv[2];
			char* file=argv[3];
		
			printf("compressionFormat: %s\n",compressionFormat);
			printf("archive: %s\n",archive);
			printf("file: %s\n",file);
			
			if(strcmp(compressionFormat,"zip")==0){
				//zip audio.zip audio.mp3
				zip(archive, file);
			}else if(strcmp(compressionFormat,"tar")==0){
				//tar -czf audio.tar.gz audio.mp3
				tar(archive, file);
			}else if(strcmp(compressionFormat,"rar")==0){
				//rar a audio.rar audio.mp3
				rar(archive, file);
			}else{
				printf("Invalid Compression Format\n");
			}
		
		}else{
	
			char* fileFormat=argv[1];
			char* destFormat=argv[2];
			char* filename=argv[3];
			
			printf("fileFormat: %s\n",fileFormat);
			printf("destFormat: %s\n",destFormat);
			printf("filename: %s\n",filename);
			
			if(strcmp(fileFormat,"png")==0){
			
				if(strcmp(destFormat,"jpg")==0){
					png2jpg(filename);
				}else if(strcmp(destFormat,"jpeg")==0){
					png2jpeg(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"jpg")==0){
			
				if(strcmp(destFormat,"png")==0){
					jpg2png(filename);
				}else if(strcmp(destFormat,"jpeg")==0){
					jpg2jpeg(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"jpeg")==0){
		
				if(strcmp(destFormat,"png")==0){
					jpeg2png(filename);
				}else if(strcmp(destFormat,"jpg")==0){
					jpeg2jpg(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"mp4")==0){
		
				if(strcmp(destFormat,"flv")==0){
					mp42flv(filename);
				}else if(strcmp(destFormat,"avi")==0){
					mp42avi(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"flv")==0){
		
				if(strcmp(destFormat,"mp4")==0){
					flv2mp4(filename);
				}else if(strcmp(destFormat,"avi")==0){
					flv2avi(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"avi")==0){
		
				if(strcmp(destFormat,"mp4")==0){
					avi2mp4(filename);
				}else if(strcmp(destFormat,"flv")==0){
					avi2flv(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"mp3")==0){
		
				if(strcmp(destFormat,"flac")==0){
					mp32flac(filename);
				}else if(strcmp(destFormat,"wav")==0){
					mp32wav(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"flac")==0){
		
				if(strcmp(destFormat,"mp3")==0){
					flac2mp3(filename);
				}else if(strcmp(destFormat,"wav")==0){
					flac2wav(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else if(strcmp(fileFormat,"wav")==0){
		
				if(strcmp(destFormat,"mp3")==0){
					wav2mp3(filename);
				}else if(strcmp(destFormat,"flac")==0){
					wav2flac(filename);
				}else{
					printf("Invalid destination file type\n");
				}
		
			}else{
				printf("Invalid source file type\n");
			}
		}
	}
   

   return;
}

void zip(char* archive, char* file){

	char cmd[512];
	sprintf(cmd,"zip %s %s", archive, file);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void unzip(char* file){

	char cmd[512];
	sprintf(cmd,"unzip -o %s", file);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void tar(char* archive, char* file){

	char cmd[512];
	sprintf(cmd,"tar -czf %s.gz %s", archive, file);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void untar(char* file){

	char cmd[512];
	sprintf(cmd,"tar -xzf %s", file);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void rar(char* archive, char* file){

	char cmd[512];
	sprintf(cmd,"rar a %s %s", archive, file);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void unrar(char* file){

	char cmd[512];
	sprintf(cmd,"unrar e -y %s", file);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void png2jpg(char* filename){

	char cmd[512];
	sprintf(cmd,"convert %s.png %s.jpg", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void png2jpeg(char* filename){

	char cmd[512];
	sprintf(cmd,"convert %s.png %s.jpeg", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void jpg2png(char* filename){

	char cmd[512];
	sprintf(cmd,"convert %s.jpg %s.png", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void jpg2jpeg(char* filename){

	char cmd[512];
	sprintf(cmd,"convert %s.jpg %s.jpeg", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void jpeg2png(char* filename){

	char cmd[512];
	sprintf(cmd,"convert %s.jpeg %s.png", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void jpeg2jpg(char* filename){

	char cmd[512];
	sprintf(cmd,"convert %s.jpeg %s.jpg", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void mp42flv(char* filename){
	
	char cmd[512];
	sprintf(cmd,"HandBrakeCLI -i %s.mp4 -o %s.flv", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}
	
void mp42avi(char* filename){
	
	char cmd[512];
	sprintf(cmd,"HandBrakeCLI -i %s.mp4 -o %s.avi", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void flv2mp4(char* filename){
	
	char cmd[512];
	sprintf(cmd,"HandBrakeCLI -i %s.flv -o %s.mp4", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void flv2avi(char* filename){
	
	char cmd[512];
	sprintf(cmd,"HandBrakeCLI -i %s.flv -o %s.avi", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void avi2mp4(char* filename){
	
	char cmd[512];
	sprintf(cmd,"HandBrakeCLI -i %s.avi -o %s.mp4", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void avi2flv(char* filename){
	
	char cmd[512];
	sprintf(cmd,"HandBrakeCLI -i %s.avi -o %s.flv", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void mp32flac(char* filename){

	char cmd[512];
	sprintf(cmd,"ffmpeg -y -i %s.mp3 %s.flac", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void mp32wav(char* filename){

	char cmd[512];
	sprintf(cmd,"ffmpeg -y -i %s.mp3 %s.wav", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void flac2mp3(char* filename){

	char cmd[512];
	sprintf(cmd,"ffmpeg -y -i %s.flac %s.mp3", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void flac2wav(char* filename){

	char cmd[512];
	sprintf(cmd,"ffmpeg -y -i %s.flac %s.wav", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void wav2mp3(char* filename){

	char cmd[512];
	sprintf(cmd,"ffmpeg -y -i %s.wav %s.mp3", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}

void wav2flac(char* filename){

	char cmd[512];
	sprintf(cmd,"ffmpeg -y -i %s.wav %s.flac", filename, filename);
	printf("%s\n",cmd);
	system(cmd);

	return;
}
