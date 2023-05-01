#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){

	pid_t childpid;

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Connected to Server.\n");
	printf("Welcome to the Image Processing Server!\n\n");
	printf("To modify the pictures in your files use the following format:\n\n");
	printf("\t \"<ImageProcessingFunction>,<NumberAssociatedWithPicture>\" \n\n");
	printf("The list of image processing functions are as follows:\n\n");
	printf("\t colorConvert, edgeDetector, contourDetector, and imageMoments\n\n");
	printf("Since you have granted us permissions to your files we have\n");
	printf("uploaded all your pictures and given them number associations.\n\n");
	printf("The number associations for files:\n\n");
	printf("\t <cityImage.jpeg>, <airportImage.jpg>, and <foodImage.jpg>\n\n");
	printf("are labeled 1 through 3 respectively.\n\n");
	printf("Any input outside of the expected format will result in a format error\n");
	printf("and show what you previously entered.\n\n");
	printf("To leave the server type \":exit\".\n");
	printf("To see the above information again type \":help\".\n\n");

	while(1){
		printf("Client: \t");
		scanf("%s", &buffer[0]);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, ":exit") == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}else if (strcmp(buffer, ":help") == 0){


		} else if(strcmp(buffer,"colorConvert,1") == 0){								// Grayscale functions
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/colorConvertTutorial", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/colorConvertTutorial",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/cityImage.jpeg",
			       NULL);

			}


		}else if(strcmp(buffer,"colorConvert,2") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/colorConvertTutorial", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/colorConvertTutorial",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/airportImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"colorConvert,3") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/colorConvertTutorial", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/colorConvertTutorial",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/foodImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"edgeDetector,1") == 0){								// Edge detector functions
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/edgeDetector", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/edgeDetector",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/cityImage.jpeg",
			       NULL);

			}


		}else if(strcmp(buffer,"edgeDetector,2") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/edgeDetector", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/edgeDetector",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/airportImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"edgeDetector,3") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/edgeDetector", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/edgeDetector",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/foodImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"contourDetector,1") == 0){								// Contour detector functions
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/contourDetector", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/contourDetector",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/cityImage.jpeg",
			       NULL);

			}


		}else if(strcmp(buffer,"contourDetector,2") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/contourDetector", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/contourDetector",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/airportImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"contourDetector,3") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/contourDetector", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/contourDetector",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/foodImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"imageMoments,1") == 0){								// Image moment functions
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/imageMoments", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/imageMoments",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/cityImage.jpeg",
			       NULL);

			}


		}else if(strcmp(buffer,"imageMoments,2") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/imageMoments", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/imageMoments",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/airportImage.jpg",
			       NULL);

			}


		}else if(strcmp(buffer,"imageMoments,3") == 0){
			
			if((childpid = fork()) == 0){

			execl("/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/imageMoments", 
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/imageMoments",
			       "/home/kbritto/ECGR-6181/FinalProject/opencv-4.6.0/Code/foodImage.jpg",
			       NULL);

			}


		}

		if(recv(clientSocket, buffer, 1024, 0) < 0){			// Error in transmission
			printf("[-]Error in receiving data.\n");
		}else if (strcmp(buffer,":help") == 0){								// Outputs help information 

			printf("Server:\n");
			printf("To modify the pictures in your files use the following format:\n\n");
			printf("\t \"<ImageProcessingFunction>,<NumberAssociatedWithPicture>\" \n\n");
			printf("The list of image processing functions are as follows:\n\n");
			printf("\t colorConvert, edgeDetector, contourDetector, and imageMoments\n\n");
			printf("Since you have granted us permissions to your files we have\n");
			printf("uploaded all your pictures and given them number associations.\n\n");
			printf("The number associations for files:\n\n");
			printf("\t <cityImage.jpeg>, <airportImage.jpg>, and <foodImage.jpg>\n\n");
			printf("are labeled 1 through 3 respectively.\n\n");
			printf("Any input outside of the expected format will result in a format error\n");
			printf("and show what you previously entered.\n\n");
			printf("To leave the server type \":exit\".\n");
			printf("To see the above information again type \":help\".\n\n");

		} else if ((strcmp(buffer,"colorConvert,1") == 0) || (strcmp(buffer,"colorConvert,2") == 0) || (strcmp(buffer,"colorConvert,3") == 0)){

			printf("Server: \t%s\n", buffer);		// Server echos client response

		} else if ((strcmp(buffer,"edgeDetector,1") == 0) || (strcmp(buffer,"edgeDetector,2") == 0) || (strcmp(buffer,"edgeDetector,3") == 0)){

			printf("Server: \t%s\n", buffer);		// Server echos client response

		} else if ((strcmp(buffer,"contourDetector,1") == 0) || (strcmp(buffer,"contourDetector,2") == 0) || (strcmp(buffer,"contourDetector,3") == 0)){

			printf("Server: \t%s\n", buffer);		// Server echos client response

		} else if ((strcmp(buffer,"imageMoments,1") == 0) || (strcmp(buffer,"imageMoments,2") == 0) || (strcmp(buffer,"imageMoments,3") == 0)){

			printf("Server: \t%s\n", buffer);		// Server echos client response

		}  else if (strcmp(buffer,":exit") == 0){

			printf("Server: \t%s\n", buffer);		// Server echos client response

		} else{
			printf("Server: \t*Format Error* %s\n", buffer);		// Server echos client response
		}
	}

	return 0;
}
