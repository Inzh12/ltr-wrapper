#include "ltr212_wrapper.h"
#include "ltr_exception.h"

namespace LtrWrapper {
    Ltr212Wrapper::Ltr212Wrapper()
    {
        checkStatus(LTR212_Init(&ltr_struct));
    }

    void Ltr212Wrapper::open(DWORD saddr, WORD sport, const CHAR *csn, WORD cc) {
        checkStatus(LTR212_Open(&ltr_struct, saddr, sport, csn, cc, "ltr212.bio"));
    }

    void Ltr212Wrapper::openDefault(WORD cc) {
        checkStatus(LTR212_Open(&ltr_struct, SADDR_DEFAULT, SPORT_DEFAULT, "", cc, "ltr212.bio"));
    }

    void Ltr212Wrapper::setADC() {
        checkStatus(LTR212_SetADC(&ltr_struct));
    }

    void Ltr212Wrapper::start() {
        checkStatus(LTR212_Start(&ltr_struct));
    }

    void Ltr212Wrapper::stop() {
        checkStatus(LTR212_Stop(&ltr_struct));
    }

    void Ltr212Wrapper::close() {
        checkStatus(LTR212_Close(&ltr_struct));
    }

    void Ltr212Wrapper::recv(DWORD *data, DWORD *tmark, DWORD size, DWORD timeout) {
        checkRecvStatus(LTR212_Recv(&ltr_struct, data, tmark, size, timeout), size);
    }

    void Ltr212Wrapper::process(DWORD *src, double *dest, DWORD *size, bool volt) {
        checkStatus(LTR212_ProcessData(&ltr_struct, src, dest, size, volt));
    }

    void Ltr212Wrapper::checkStatus(int status)
    {
        if(status != LTR_OK) {
            throw LtrException(getErrorString(status));
        }
    }

    void Ltr212Wrapper::checkRecvStatus(int status, int samples_amount)
    {
        if (status > 0 && status != samples_amount) {
            char error_string[] = "Прочитано меньше сэмплов, чем заказано";
            CharToOem(error_string, error_string);
            throw LtrException(error_string);
        } else if (status < 0) {
            throw LtrException(getErrorString(status));
        }
    }

    std::string Ltr212Wrapper::getErrorString(int error)
    {
        char error_string[255];
        strcpy(error_string, (char*)(LTR212_GetErrorString(error)));
        CharToOem(error_string, error_string);
        return error_string;
    }
}

