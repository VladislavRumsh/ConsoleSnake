#include "HandleHTTP.h"

void sendHTTPscore(const std::wstring& name, int score, const std::wstring& grid)
{
	HINTERNET hInternet = InternetOpen(L"ConsoleSnakeClient", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (hInternet == NULL)
	{
		std::cout << "Failed to open an internet session";
		return;
	}
	// Construct the URL using a wostringstream
	std::wostringstream urlStream;
	urlStream << L"http://185.130.225.134:8123/ConsoleSnakeScoreboard?name=" << name << L"&score=" << score << L"&grid=" << grid;

	// Convert the constructed URL into a wstring
	std::wstring url = urlStream.str();

	HINTERNET hRequest = InternetOpenUrl(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
	if (!hRequest) {
		// Handle error
		std::cout << "Failed to open URL";
		InternetCloseHandle(hInternet);
		return;
	}

	std::cout << "Success";
	InternetCloseHandle(hRequest);
	InternetCloseHandle(hInternet);
	return;
}
