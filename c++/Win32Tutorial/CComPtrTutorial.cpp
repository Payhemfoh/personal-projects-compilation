#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include <shobjidl.h>
#include <atlbase.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr)) {
		//create dialog box instance
		CComPtr<IFileOpenDialog> pFileOpen;

		hr = pFileOpen.CoCreateInstance(__uuidof(FileOpenDialog));
		if (SUCCEEDED(hr)) {
			//display dialog box
			hr = pFileOpen->Show(NULL);

			if (SUCCEEDED(hr)) {
				CComPtr<IShellItem> pItem;

				//get file path
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr)) {
					//display file path in message box
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					if (SUCCEEDED(hr)) {
						MessageBox(NULL, pszFilePath, L"File Path", MB_OK);
						CoTaskMemFree(pszFilePath);
					}
				}
				//pItem out of scope
			}
			//pFIleOpen out of scope
		}
		CoUninitialize();
	}
	
	return 0;
}