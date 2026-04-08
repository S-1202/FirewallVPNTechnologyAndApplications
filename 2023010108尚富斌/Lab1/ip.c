#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    char *domain = "www.yxnu.edu.cn";
    struct hostent *host = gethostbyname(domain);

    if (!host) {
        herror("解析失败");
        return 1;
    }

    printf("域名：%s\n", domain);
    printf("主机名：%s\n", host->h_name);
    printf("IP地址列表:\n");

    // 遍历所有IP
    for (int i = 0; host->h_addr_list[i]; i++) {
        struct in_addr *addr = (struct in_addr*)host->h_addr_list[i];
        printf("  - %s\n", inet_ntoa(*addr));
    }

    return 0;
}