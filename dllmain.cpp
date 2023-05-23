#include <Windows.h>

int __stdcall DllMain(HMODULE m_Module, DWORD m_Reason, void* m_Reserved)
{
    if (m_Reason == DLL_PROCESS_ATTACH)
    {
        const char* m_NewControllerMethodName = "OptionController_ShowPS3";
        size_t m_NewControllerMethodNameSize = strlen(m_NewControllerMethodName) + 1;

        void* m_ControllerMethodName = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(GetModuleHandleA(0)) + 0x17E6398);
        DWORD m_OldProtect = 0x0;
        if (VirtualProtect(m_ControllerMethodName, m_NewControllerMethodNameSize, PAGE_READWRITE, &m_OldProtect))
            memcpy(m_ControllerMethodName, m_NewControllerMethodName, m_NewControllerMethodNameSize);
    }

    return 1;
}
