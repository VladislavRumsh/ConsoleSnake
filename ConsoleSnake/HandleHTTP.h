#ifndef HANDLEHTTP_H
#define HANDLEHTTP_H

#include <iostream>
#include <windows.h>
#include <wininet.h>
#include <string>
#include <sstream>


void sendHTTPScore(const std::wstring& name, int score, const std::wstring& grid, int speed);

#endif
