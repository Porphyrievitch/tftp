#include <getopt.h>
#include <stdio.h>

//main client, checks for args and starts an operation if no errors detected
int main(int argc, char *argv[])
{
	char* address = "127.0.0.1";
	int port = 69;
	char* filename = NULL;
	char ch;
	//读或者写模式
	char mode;
	char resolved_path[80];

	/* Read command line options */
	while ((ch = getopt(argc, argv, "h:p:f:wr")) != -1) 
	{
		switch (ch) 
		{
			case 'h':
				address = optarg;
				break;
			case 'p':
				port = atoi(optarg);
				break;
			case  'w':
				mode = (char)'w';
				break;
			case  'r':
				mode = (char)'r';
				break;
			case 'f':
				filename = optarg;
				printf("the file name is %s \n", filename);
				break;
			case '?':
				if (optopt == 'f') 
				{
					fprintf(stderr, "Option -%c requires an argument\n", optopt);
				} 
				else 
				{
					fprintf(stderr, "Unknown option\n");
				}
				exit(1);
		}
	}

	if (NULL == filename)
	{
		printf("file is null\n");
		printf("Usage: %s [-p port] [-h ip] (-w -f putfile || -r -f getFile)\n", argv[0]);
		exit(1);
	}

  
	printf("the ip : %s\n", address);
	printf("the port : %d\n", port);
	printf("the mode: %c\n", mode);
	printf("the filename: %s\n", filename);

	realpath(filename, resolved_path);

	switch(mode)
	{
		case 'w':
			//上传文件;
			return;
		case 'r':
			//下载文件;
			return;
		default: 
			printf("Unknown action \n");
			break;
	}

	printf("Usage: %s [-p port] [-h ip] (-w -f putfile || -r -f getFile)\n", argv[0]);
}
