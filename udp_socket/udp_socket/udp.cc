#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <WinSock2.h>
#include <cassert>
#include <string>

#pragma comment(lib,"Ws2_32.lib")
using namespace std;

int server_port = 8080;
string server_ip = "43.138.63.71";

// ���ַ����� Windows Ĭ�ϱ���ת��Ϊ UTF-8 ����
string convertToUTF8(const string& str)
{
    int size = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
    wstring wstr(size, 0);
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &wstr[0], size);

    size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    string utf8Str(size, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &utf8Str[0], size, NULL, NULL);

    return utf8Str;
}

int main()
{
    // ��ʼ���׽���
    WSADATA data;
    (void)WSAStartup(MAKEWORD(2, 2), &data);
    (void)data;

    // �����ͻ���
    // ���� socket
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    assert(sockfd > 0);

    // ��д��������Ӧ����Ϣ
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr.s_addr = inet_addr(server_ip.c_str());

    // ͨѶ����
    string buffer;
    while (true)
    {
        cout << "Please Enter# ";
        getline(cin, buffer);

        // ���ַ����� Windows Ĭ�ϱ���ת��Ϊ UTF-8 ����
        string utf8Str = convertToUTF8(buffer);

        // ����Ϣ�� server
        sendto(sockfd, utf8Str.c_str(), utf8Str.size(), 0,
            (const struct sockaddr*)&server, sizeof(server));
    }

    closesocket(sockfd);
    WSACleanup();

    return 0;
}
