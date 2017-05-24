/*
 ============================================================================
 Name        : cmdkafka.c
 Author      : guangxinzhang@outlook.com
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * @description: 函数执行命令，并将结果存储到result字符串数组中
 * @param: cmd 表示要执行的命令
 * @param: result 是执行的结果存储的字符串数组
 * @return: 函数执行成功返回1，失败返回0
 */
int execmd(char* cmd, char* result) {
	char buffer[128];                  //定义缓冲区
	FILE* pipe = popen(cmd, "r");      //打开管道，并执行命令
	if (!pipe)
		return 0;                      //返回0表示运行失败

	while (!feof(pipe)) {
		if (fgets(buffer, 128, pipe)) {  //将管道输出到result中
			printf("%s", buffer);
			// strcat(result, buffer);
		}
	}
	pclose(pipe);
	return 1;
}

int main() {
	char result[1024 * 4] = "";
	if (1 == execmd("tail -f /tmp/a.log", result)) {
		printf("%s", result);
	}
	system("pause");
}
