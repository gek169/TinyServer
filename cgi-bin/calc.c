/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "../csapp.h"

int main(void) {
    char *buf, *p;
    char arg1[MAXLINE], arg2[MAXLINE], arg3[MAXLINE], content[MAXLINE];
    int n1=0, n2=0, op=0;

    /* Extract the two arguments */
    if ((buf = getenv("QUERY_STRING")) != NULL) {
	    //printf("\nBUF IS : %s\n", buf);
		p = strchr(buf, '=');if (p==NULL)return 1;p++;
		strcpy(arg1, p);
		p = strchr(p, '=');if (p==NULL)return 1;p++;
		strcpy(arg2, p);
		p = strchr(p, '=');if (p==NULL)return 1;p++;
		strcpy(arg3, p);
		op = atoi(arg1);
		n1 = atoi(arg2);
		n2 = atoi(arg3);
		//printf("\nARG1 IS : %s\n", arg1);
		// printf("\nARG2 IS : %s\n", arg2);
		// printf("\nARG3 IS : %s\n", arg3);
    }

    /* Make the response body */
    sprintf(content, "Hey Dr.Fei (And his graders)");
    sprintf(content, "%sCheck out this calculator.\r\n<p>", content);
	if(op == 0){
    sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", 
	    content, n1, n2, n1 + n2);
    sprintf(content, "%sThanks for visiting!\r\n", content);
  	} else if (op == 1){
  		sprintf(content, "%sThe answer is: %d - %d = %d\r\n<p>", 
  		    content, n1, n2, n1 - n2);
  		sprintf(content, "%sThanks for visiting!\r\n", content);
  	} else if (op == 2){
  		sprintf(content, "%sThe answer is: %d * %d = %d\r\n<p>", 
  		    content, n1, n2, n1 * n2);
		sprintf(content, "%sThanks for visiting!\r\n", content);
  	} else {
  		sprintf(content, "<p>Unkown Operand.</p>\r\n");
  	}
    /* Generate the HTTP response */
    printf("Connection: close\r\n");
    printf("Content-length: %d\r\n", (int)strlen(content));
    printf("Content-type: text/html\r\n\r\n");
    printf("%s", content);
    fflush(stdout);

    exit(0);
}
/* $end adder */
