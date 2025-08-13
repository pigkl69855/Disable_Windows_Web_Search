#include <windows.h>
#include <iostream>

int main() {
    HKEY hKey;
    LPCSTR subKey = "Software\\Policies\\Microsoft\\Windows\\Explorer";

    // 建立或開啟目標路徑
    LONG result = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        subKey,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL
    );

    if (result == ERROR_SUCCESS) {
        DWORD value = 1;
        // 設定 DisableSearchBoxSuggestions = 1 (DWORD 32bit)
        result = RegSetValueExA(
            hKey,
            "DisableSearchBoxSuggestions",
            0,
            REG_DWORD,
            reinterpret_cast<const BYTE*>(&value),
            sizeof(value)
        );

        RegCloseKey(hKey);

        if (result == ERROR_SUCCESS) {
            std::cout << "登錄檔設定成功！\n";
        }
        else {
            std::cerr << "設定值失敗，錯誤碼: " << result << "\n" << "請右鍵工作管理員啟動此程式" << "\n\n";
        }
    }
    else {
        std::cerr << "設定值失敗，錯誤碼: " << result << "\n" << "請右鍵工作管理員啟動此程式" << "\n\n";

    }

    system("Pause");
}
