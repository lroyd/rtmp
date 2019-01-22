
#include <stdio.h>
#include "librtmp_send264.h"

//for

FILE *fp_send1;

//读文件的回调函数
//we use this callback function to read data from buffer
int read_buffer1(unsigned char *buf, int buf_size )
{
	if(!feof(fp_send1))
	{
		int true_size = fread(buf,1,buf_size,fp_send1);
		return true_size;
	}
	else
	{
		return -1;
	}
}

char *url = "rtmp://192.168.1.163/live/stream";
//char *url = "rtmp://47.104.231.151/live/stream";


int main(int argc, char* argv[])
{
	fp_send1 = fopen("test.h264", "rb");

	//初始化并连接到服务器
	RTMP264_Connect(url);
	
	//发送
	RTMP264_Send(read_buffer1);

	//断开连接并释放相关资源
	RTMP264_Close();

	return 0;
}

