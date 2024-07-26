#pragma once

#include <ltr212api.h>
#include <string>

namespace LtrWrapper {
    class Ltr212Wrapper
    {
    public:
        TLTR212 ltr_struct;

        Ltr212Wrapper();
        void open(DWORD saddr, WORD sport, const CHAR *csn, WORD cc);
        void openDefault(WORD cc);
        void close();
        void setADC();
        void start();
        void stop();
        void recv(DWORD* data, DWORD *tmark, DWORD size, DWORD timeout);
        void process(DWORD* src, double* dest, DWORD* size, bool volt);
    private:
        void checkStatus(int status);
        void checkRecvStatus(int status, int samples_amount);
        std::string getErrorString(int error);
    };
}


