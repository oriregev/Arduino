
#include <Arduino.h>
#include <IPAddress.h>

IPAddress::IPAddress()
{
    memset(_address, 0, sizeof(_address));
}

IPAddress::IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet)
{
    _address[0] = first_octet;
    _address[1] = second_octet;
    _address[2] = third_octet;
    _address[3] = fourth_octet;
}

IPAddress::IPAddress(uint32_t address)
{
    memcpy(_address, &address, sizeof(_address));
}

IPAddress::IPAddress(const uint8_t *address)
{
    memcpy(_address, address, sizeof(_address));
}

IPAddress& IPAddress::operator=(const uint8_t *address)
{
    memcpy(_address, address, sizeof(_address));
    return *this;
}

IPAddress& IPAddress::operator=(uint32_t address)
{
    memcpy(_address, (const uint8_t *)&address, sizeof(_address));
    return *this;
}

bool IPAddress::operator==(const uint8_t* addr)
{
    return memcmp(addr, _address, sizeof(_address)) == 0;
}

long IPAddress::printTo(Print& p) const
{
    long n = 0, t;
    for (int i =0; i < 3; i++)
    {
        if ((t = p.print(_address[i], DEC)) > 0) n += t;
        if ((t = p.print('.')) > 0) n+= t;
    }
    if ((t = p.print(_address[3], DEC)) > 0) n += t;
    return n;
}

