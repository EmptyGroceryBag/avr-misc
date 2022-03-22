#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
	char* buffer[2] = {'a', '\0'};

	int chip_fd = open("/dev/ttyACM0", O_RDWR);
	printf("open() returned: %d\n", chip_fd);
	
	int write_result = write(chip_fd, buffer, 2);
	printf("write() returned %d\n", write_result);
	printf("errno = %d\n", errno);

	printf("close() returned: %d\n", close(chip_fd));

	return 0;
}
