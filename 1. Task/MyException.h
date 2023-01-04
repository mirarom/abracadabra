//  ���� MyException.h

#pragma once              // ��� ������������ ��������� ����� �����
#include <cstring>        // ��� ������� ������������ �-�����

enum ErrorCode            // ������ �������� ����� �������
{
   EC_RANGE = -3,
   EC_MEMORY = -2,
   EC_UNKNOWN = -1,
   EC_OK = 0
};

class MyException
{
   char message[256];
   ErrorCode  code;
 public:
   MyException(ErrorCode c, const char *msg) {
      code = c;
      strncpy(message, msg, 255);
   }
   const char * Message() const { return message; }
   ErrorCode   Code() const { return code; }
};
